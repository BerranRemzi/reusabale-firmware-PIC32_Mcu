#include "typedef_global.h"
#include "usart.h"
#include "wdt.h"
#include "bootloader.h"
#include "stdio.h"
#include "string.h"
#include "device_config.h"
#include "systmr.h"
#include "system_config.h"
#include "flash_mem.h"
#include "debug.h"
#include "version.h"
#include "board.h"






volatile const uint32_t __attribute__((section(".sw_version"))) VERSION = _VERSION_;

volatile const uint32_t *_appVer1 = (const uint32_t *)MAIN_APP_ADDR + 0x490;
volatile const uint32_t *_appVer2 = (const uint32_t *)BACK_APP_ADDR + 0x490;

static const uint16_t frame_crc16_table[16] =
{
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
    0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef
};


#define READ_BOOT_INFO          (1)
#define ERASE_FLASH             (2)
#define PROGRAM_FLASH           (3)
#define READ_CRC                (4)
#define JMP_TO_APP              (5)
#define CMD_ERROR               (0xff)

typedef struct
{
    uint8_t RecDataLen;
    uint32_t Address;
    uint8_t RecType;
    uint8_t* Data;
    uint8_t CheckSum;
    uint32_t ExtSegAddress;
    uint32_t ExtLinAddress;
} HexRecord;

#define DATA_RECORD             (0)
#define END_OF_FILE_RECORD      (1)
#define EXT_SEG_ADRS_RECORD     (2)
#define EXT_LIN_ADRS_RECORD     (4)



#define SOH 0x01 // start of header
#define EOT 0x04 // end of text
#define DLE 0x10 // Excepe symbol

static uint32_t _calcCrc1;
static uint32_t _calcCrc2;

static uint8_t rx_data[512];
static uint32_t rx_count;

static uint8_t tx_data[512];
static uint32_t tx_count;

static volatile bool flag_runApp = false;



// bootloader uart communication
void writeChar(char ch);
bool readChar(char *pch, int timeout_ms);

void handleFrameData(void);
void sendTransmitFrame(void);
bool writeHexRecord2Flash(uint8_t *pHexRecord, uint32_t hexRecLen);




bool BOOTLOADER_AppExist()
{
    bool exist = (0xFFFFFFFF != *(uint32_t *) (APP_RESET_ADDRESS | 0x20000000));
    PRINTF("\nApp does not exist\n");
    return exist;
}

void runApp(void)
{
    asm("j 0x9d000000");
}

uint16_t calculateFrameCrc(uint8_t *data, uint32_t len)
{
    uint32_t i;
    uint16_t crc = 0;

    while (len--)
    {
        i = (crc >> 12) ^ (*data >> 4);
        crc = frame_crc16_table[i & 0x0F] ^ (crc << 4);
        i = (crc >> 12) ^ (*data >> 0);
        crc = frame_crc16_table[i & 0x0F] ^ (crc << 4);
        data++;
    }

    return (crc & 0xFFFF);
}


bool readChar(char *pchar, int timeout_ms) {    
        
    SYSTEM_timer_start( timeout_ms);    
    while (!SYSTEM_timer_timeout())
    {
        if (uart_rxline_error(UART3))
        {
            uart_reset(UART3);
        }
        if (uart_data_available(UART3))
        {
            LED2(1);
            uart_getc(UART3, pchar);
            LED2(0);
            return true;
        }
    }
    return false;
}


void writeChar(char ch)
{
    while(uart_txline_busy(UART3) == true);
    uart_putc(UART3, ch);
}


ResultError_t BOOTLOADER_Initialize() {
    ResultError_t result = RES_ERROR;
   
    
    // calculate CRC1 for MAIN app memory
    _calcCrc1 = FLASH_CalculateCrc(FLASH_MEM1);

    // calculate CRC2 for BACKUP memory 
    _calcCrc2 = FLASH_CalculateCrc(FLASH_MEM2);    
    
    // loads current configuration from memory   
    result = device_config_load();    
    
    
    // print information about memory and bootloader versions,crcs
    if (result == RES_NO_ERROR) {                
        #ifdef DEBUG_VER
            if(DBG_PIN){
                PRINTF("\nBootloader build:0x%x", VERSION);            
                while(!uart_txline_empty(DBG_UART));    
            }
        #endif  
    }
    else
    {   
        #ifndef DEBUG_VER
        PRINTF("\nBootloader: config error - set default");
        device_config_set_default();
        device_config_save();
        #endif
    }
    
    
    
    return result;
}

bool BOOTLOADER_WaitSequence() {
    int i = 0;
    int retry = 5;
    char c;
    PRINTF("\n WaitSequence...(0xAA,0x55) 115200 8N1");
    while (retry--) {
        bool ok = readChar(&c, 50);
        if (ok) {
            switch (i) {
                case 0:
                    if ((unsigned char) c == 0xAA) i = 1;
                    else i = 0;
                    break;
                case 1:
                    if ((unsigned char) c == 0x55) i = 2;
                    else i = 0;
                    break;
                default:
                    i=0;
                    break;
            }
        } else i = 0;

        if (i == 2) {
            return true;
        }
    }
    return false;
}



void handleFrameData(void) {

        uint8_t cmd;                                                
    
        // First byte of the data field is command.
        cmd = rx_data[0];                
    
        // Reset the response length to 0.
        tx_count = 0;
    
         //Process the command.
        switch (cmd)
        {
            
        case READ_BOOT_INFO: // Read boot loader version info.
            tx_data[0] = READ_BOOT_INFO;
            tx_data[1] = (VERSION&0xff)>>8;
            tx_data[2] = (VERSION&0xff);            
            //Set the transmit frame length.
            tx_count = 2 + 1; // Boot Info Fields	+ command
            sendTransmitFrame();
            break;
    
        case ERASE_FLASH:
            {             
                bool ok;
                #ifdef   DEBUG_VER
                /*D*/if(DBG_PIN)
                /*D*/    ok = FLASH_EraseMemory(FLASH_MEM2);
                /*D*/else
                #endif      
                ok = FLASH_EraseMemory(FLASH_MEM1);                
                
                // if erase memory OK
                if(ok) tx_data[0] = ERASE_FLASH;
                else tx_data[0] = CMD_ERROR;
                
                // return Command or Error
                tx_count = 1;                
                sendTransmitFrame();
            }
            break;
    
        case PROGRAM_FLASH:            
            //Negate length of command and CRC RxBuff.Len.
            if(writeHexRecord2Flash(&rx_data[1], rx_count - 3)) 
                tx_data[0] = PROGRAM_FLASH;
            else tx_data[0] = CMD_ERROR;
            
            //return Command or Error
            tx_count = 1;
            sendTransmitFrame();
            break;
    
    
        case READ_CRC:
            {
                // Get address from the packet.
                 tx_data[0] = READ_CRC;
                uint32_t address,length;
                memcpy((uint8_t*)&address, &rx_data[1], sizeof (address));
                memcpy((uint8_t*)&length, &rx_data[5], sizeof (length));
                uint16_t crc16 = calculateFrameCrc((uint8_t *) address, length);
                
                //Set the transmit frame length.                
                tx_data[1] =  (uint8_t)crc16&0xff;               
                tx_data[2] =  (uint8_t)(crc16>>8)&0xff;               
                
                // Command + 2 bytes of CRC.
                tx_count = 1 + 2; 
                sendTransmitFrame();
            }
            break;
                   
        case JMP_TO_APP:
            
            // Exit firmware upgrade mode.
             flag_runApp = 1;
                        
            #ifdef   DEBUG_VER
             if(DBG_PIN){
             currentConfig()->app_crc_2 = FLASH_CalculateCrc(FLASH_MEM2);
                   flag_runApp = 0;
                  }
             else
            #endif      
            
            // save application CRC
            currentConfig()->app_crc_1 = FLASH_CalculateCrc(FLASH_MEM1);                               
            if(device_config_save()) { tx_data[0] = JMP_TO_APP;  }
            else tx_data[0] = CMD_ERROR;
            // return Command or ERROR
            tx_count = 1;
            sendTransmitFrame();
            break;
    
        default:
            // Nothing to do.
            break;
        }
}

bool writeHexRecord2Flash(uint8_t *pHexRecord, uint32_t hexRecLen)
{
    static HexRecord hexRecordSt;
    static int iiii = 0;
    uint8_t checksum = 0;
    uint32_t i;
    uint32_t  WrData;
    uint32_t nextRecStartPt = 0;

    while (hexRecLen >= 5) // A hex record must be atleast 5 bytes. (1 Data Len byte + 1 rec type byte+ 2 address bytes + 1 crc)
    {
        pHexRecord = &pHexRecord[nextRecStartPt];
        hexRecordSt.RecDataLen = pHexRecord[0];
        hexRecordSt.RecType = pHexRecord[3];
        hexRecordSt.Data = &pHexRecord[4];

        //Determine next record starting point.
        nextRecStartPt = hexRecordSt.RecDataLen + 5;

        // Decrement total hex record length by length of current record.
        hexRecLen = hexRecLen - nextRecStartPt;

        // Hex Record checksum check.
        checksum = 0;
        for (i = 0; i < hexRecordSt.RecDataLen + 5; i++)
        {
            checksum += pHexRecord[i];
        }

        if (checksum != 0)
        {
            //Error. Hex record Checksum mismatch.
        }
        else
        {
            // Hex record checksum OK.
            switch (hexRecordSt.RecType)
            {
            case DATA_RECORD: //Record Type 00, data record.

                hexRecordSt.Address =  ((uint32_t)pHexRecord[1] << 8) | (uint32_t)pHexRecord[2];
                // Derive the address.
                hexRecordSt.Address = hexRecordSt.Address + hexRecordSt.ExtLinAddress + hexRecordSt.ExtSegAddress;

                while (hexRecordSt.RecDataLen) // Loop till all bytes are done.
                {

                    uint32_t progAddress;
                    // Convert the Physical address to Virtual address.
                    progAddress = (uint32_t)PA_TO_KVA0(hexRecordSt.Address);
                    

                    
                    // check if this data belongs to app memory. Doesn't matter of mainApp or backup. 
                    // Lets allow backup memory update
                    const bool addr_is_app =     (progAddress >= MAIN_APP_ADDR) && (progAddress <=  (MAIN_APP_ADDR + APP_SIZE_BYTES * 2) );

                    // Make sure we are not writing boot area and device configuration bits.
                    if (addr_is_app )
                    {
                        if (hexRecordSt.RecDataLen < 4)
                        {
                            // Sometimes record data length will not be in multiples of 4. Appending 0xFF will make sure that..
                            // we don't write junk data in such cases.
                            WrData = 0xFFFFFFFF;
                            memcpy(&WrData, hexRecordSt.Data, hexRecordSt.RecDataLen);
                        }
                        else
                        {
                            memcpy(&WrData, hexRecordSt.Data, 4);
                        }

#ifdef DEBUG_VER
                        if(DBG_PIN)    progAddress += 0x80000;
#endif

                        // Write the data into flash.
                        if(nvm_write_word( progAddress, WrData) == RES_ERROR && iiii++ > 3)
                        {
                            // if Error writing data stop and return false
                            return false;
                        }

                    }

                    // Increment the address.
                    hexRecordSt.Address += 4;

                    // Increment the data pointer.
                    hexRecordSt.Data += 4;

                    // Decrement data len.
                    if (hexRecordSt.RecDataLen > 3)
                    {
                        hexRecordSt.RecDataLen -= 4;
                    }
                    else
                    {
                        hexRecordSt.RecDataLen = 0;
                    }
                }
                break;

            case EXT_SEG_ADRS_RECORD: // Record Type 02, defines 4th to 19th bits of the data address.               
                hexRecordSt.ExtSegAddress = ((uint32_t)hexRecordSt.Data[0]<<16)| ((uint32_t)hexRecordSt.Data[1]<<8);                
                // Reset linear address.
                hexRecordSt.ExtLinAddress = 0;
                break;

            case EXT_LIN_ADRS_RECORD: // Record Type 04, defines 16th to 31st bits of the data address.
                hexRecordSt.ExtLinAddress = ((uint32_t)hexRecordSt.Data[0]<<24) | (uint32_t)hexRecordSt.Data[1]<<16;                
                // Reset segment address.
                hexRecordSt.ExtSegAddress = 0;
                break;

            case END_OF_FILE_RECORD: //Record Type 01, defines the end of file record.
            default:
                hexRecordSt.ExtSegAddress = 0;
                hexRecordSt.ExtLinAddress = 0;
                break;
            }
        }
    }//while(1)
    return true;
}

void sendTransmitFrame()
{
    int i;

    if (tx_count > 0)
    {
        //There is something to transmit.
        // Calculate CRC of the frame.
        uint16_t crc16 = calculateFrameCrc(tx_data, tx_count);
        tx_data[tx_count++] = (uint8_t)crc16 & 0xff;
        tx_data[tx_count++] = (uint8_t)((crc16 >> 8) & 0xff);

        // Insert SOH (Indicates beginning of the frame)
        writeChar(SOH);

        // Insert Data Link Escape Character.
        for (i = 0; i < tx_count; i++)
        {
            if ((tx_data[i] == EOT) || (tx_data[i] == SOH)
                    || (tx_data[i] == DLE))
            {
                // EOT/SOH/DLE repeated in the data field, insert DLE.
                writeChar(DLE);
            }
            writeChar(tx_data[i]);
        }

        // Mark end of frame with EOT.
        writeChar( EOT);

        // Purge this buffer, no more required.
        tx_count = 0;
    }

}





void BOOTLOADER_ExecuteUartUpdater() {
    unsigned int blinker=0;
    bool led1_state = 0;

    printf("ONMCU Bootloader...\n");
    flag_runApp = false;
    while (flag_runApp == false) {
        bool have_frame = false;
        bool escape = 0;
        rx_count =0;
        char c;
        
        while (readChar(&c, 20)) {
            
                uint8_t byte;
                byte = (unsigned char) c;

                switch (byte) {
                    case SOH:
                        if (escape) {
                            rx_data[rx_count++] = byte;
                            escape = 0;
                        }
                        else {
                                LED2(1);
                                rx_count = 0;
                        }
                        break;

                    case EOT:
                        if (escape) {
                            rx_data[rx_count++] = byte;
                            escape = 0;
                        } else {
                            
                            uint16_t crc = (uint16_t) rx_data[rx_count - 2] | ((uint16_t) rx_data[rx_count - 1] << 8);
                            if (rx_count > 2) {
                                const bool crc_ok = (calculateFrameCrc(&rx_data[0], rx_count - 2) == crc);
                                if (crc_ok) {
                                    // CRC matches and frame received is valid.
                                    have_frame = 1;                                   
                                }else{
                                    rx_count=0;
                                }
                            }                            
                        }
                        break;

                    case DLE:
                        if (escape) {
                            rx_data[rx_count++] = byte;
                            escape = 0;
                        } else escape = 1;
                        break;

                    default:
                        rx_data[rx_count++] = byte;
                        escape = 0;
                        break;

                }                
           
                
                if (have_frame) {
                    handleFrameData();
                    have_frame=0;
                    rx_count =0;
                    tx_count=0;
                    LED2(0);
                }
        }

        if( (++blinker&7) ==0){
            LED1(led1_state);
            led1_state = !led1_state;
        }

        clearWdt();
    }
         LED2(0);
}

bool BOOTLOADER_CheckNeedUpdate() {

    // version 1 - is main application version
    // version 2 - is backup version
    // we can't run backup code this is just stored bytes

    // if CRC1 = CRC2 versions are equal ->not update
    if (currentConfig()->app_crc_1 == currentConfig()->app_crc_2 ) 
    {
        PRINTF("\nCRC1=CRC2 update not needed");
        return false;
    }
    // if CRC2 backup has valid CRC 
    else if(_calcCrc2 == currentConfig()->app_crc_2 )
    {
        //if version2 is higher than version1 is not fffffff ->update
        if(*_appVer1 < *_appVer2 && *_appVer2 != 0xffffffff){
            PRINTF("\nVersion1 < Version2");
            return true;
        }
        
        #ifdef  DEBUG_VER
        else if(DBG_PIN==1)
        {        
            PRINTF("\nDebugPin=1");
            //if Debug pin is ON update on CRC1 <> CRC2
            // it is used when we debug and not increment version
            return true;
        }
        #endif
    }       
    // in all cases except above NO NEED update
    return false;
}

void BOOTLOADER_ExecuteLiveUpdater(){    
    // check if crc is valid
    PRINTF("\nStart LiveUpdater...");    
    if (currentConfig()->app_crc_2 == _calcCrc2) // if backup memory is valid
    {
        if(FLASH_UpdateFromBackup()==true){
            _calcCrc1 = FLASH_CalculateCrc(FLASH_MEM1);
            if(_calcCrc1 == _calcCrc2){
                currentConfig()->app_crc_1 = _calcCrc1;
                if(device_config_save() == RES_NO_ERROR){
                    PRINTF("\nBackup Success!");    
                }
            }
        }
    }
    //else some error
    PRINTF("\nBackup App is not valid!");

    //... ignore and exit to application ....
}
