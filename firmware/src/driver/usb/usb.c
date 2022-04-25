#include <xc.h>
#include "USB.h"

unsigned char USB_address = 0;
volatile char USB_set_address = 0;
volatile char USB_line_control_state = 0;

volatile USB_ENDPOINT EP[3];
volatile USB_TRANSACTION USB_transaction;
volatile USB_LINE_CODING USB_line_coding;

void (*USB_receive_callback)(const unsigned char *buffer, int length);
void (*USB_connected_callback)(void) ;




void USB_init_endpoints()
{
    USBE1CSR0bits.MODE = 0;     // EP1 is OUT (OUT from host = in to device = RX)
    USBE2CSR0bits.MODE = 0;     // EP2 is OUT (for now, will be IN at times)
    
    // Clear all interrupt flags
	USBCSR0bits.EP0IF = 0;
    USBCSR0bits.EP1TXIF = 0;
    USBCSR0bits.EP2TXIF = 0;
    USBCSR1bits.EP1RXIF = 0;
    USBCSR1bits.EP2RXIF = 0;
	
    // Set the maximum transfer length for each endpoint
	// Configure endpoint 0 first.
    USBE0CSR0bits.TXMAXP = 16; // Set endpoint 0 buffer size to 16 bytes (can be a maximum of 64 for EP0)

    // And next my custom endpoints
    USBE1CSR0bits.TXMAXP = 16;   // Endpoint 1 - Maximum TX payload / transaction (can be a maximum of 64 for CDC "Interrupt IN endpoint"
    USBE2CSR0bits.TXMAXP = 512;   // Endpoint 2 - Maximum TX payload / transaction (512 is the maximum, set to 512)
    USBE2CSR1bits.RXMAXP = 512;   // Endpoint 2 - Maximum RX payload / transaction (512 is the maximum, set to 512)

	// Specify which kinds of endpoint we will be using
    USBE1CSR2bits.PROTOCOL = 3; // Endpoint 1 - Interrupt mode
    USBE2CSR2bits.PROTOCOL = 2; // Endpoint 2 TX - Bulk mode
    USBE2CSR3bits.PROTOCOL = 2; // Endpoint 2 RX - Bulk mode

	// Enable DISNYET
    USBE1CSR1bits.PIDERR = 0; // Clear DISNYET to enable NYET replies
    USBE2CSR1bits.PIDERR = 0; // Clear DISNYET to enable NYET replies

	// Set up buffer location for endpoint 1
    USBCSR3bits.ENDPOINT = 1;
    USBFIFOA = 0x08;
    USBIENCSR0bits.CLRDT = 1;

	// Set up buffer locations for endpoint 2
    USBCSR3bits.ENDPOINT = 2;
    USBFIFOA = 0x000A004A;
    USBIENCSR0bits.CLRDT = 1;
    USBE2CSR3bits.TXFIFOSZ = 0x9;   // Transmit FIFO Size bits - 512 bytes
    USBE2CSR3bits.RXFIFOSZ = 0x9;   // Receive FIFO Size bits - 512 bytes
	
	// Set maximum size for each packet before splitting occurs
    USBOTGbits.RXFIFOSZ = 0b0110; // 0b0110 = 512 bytes
    USBOTGbits.TXFIFOSZ = 0b0110; // 0b0110 = 512 bytes

	// Set receive endpoint 2 to High Speed
    USBE2CSR3bits.SPEED = 1;
    
	// Disable Isochronous mode for endpoints 1 and 2
    USBE1CSR0bits.ISO = 0;      // Isochronous TX Endpoint Disable bit (Device mode).
    USBE2CSR0bits.ISO = 0;      // Isochronous TX Endpoint Disable bit (Device mode).

    // Set up endpoint interrupts
	// Initially clear all the interrupt enables (IE)
    USBCSR1 = 0;
    USBCSR2 = 0;
    
    USBCSR1bits.EP0IE = 1;      // Endpoint 0 interrupt enable
    USBCSR1bits.EP1TXIE = 1;    // Endpoint 1 TX interrupt enable
    USBCSR2bits.EP1RXIE = 1;    // Endpoint 1 RX interrupt enable
    USBCSR1bits.EP2TXIE = 1;    // Endpoint 2 TX interrupt enable
    USBCSR2bits.EP2RXIE = 1;    // Endpoint 2 RX interrupt enable
    USBCSR2bits.RESETIE = 1;
    USBCSR2bits.RESUMEIE = 1;
    USBCSR2bits.SOFIE = 1;

	// Set current endpoint to EP2
    USBCSR3bits.ENDPOINT = 2;    
}



void USB_init(void *receive_callback, void *connected_callback)
{
    USB_receive_callback = receive_callback;
    USB_connected_callback = connected_callback;

    USBCSR0bits.SOFTCONN = 0;   // Initially disable it while we go into setup

    USB_address = 0;			// We haven't been given an address yet    
    USBCSR0bits.FUNC = 0;       // Initially set the USB address to 0 until later when the host assigns us an address

    USBCSR2bits.RESETIE = 1;    // Enable the reset interrupt
    IEC4bits.USBIE = 1;         // Enable the USB interrupt
    USBCRCONbits.USBIE = 1;     // Enable USB module interrupt
    IFS4bits.USBIF = 0;         // Clear the USB interrupt flag.
    IPC33bits.USBIP = 7;        // USB Interrupt Priority 7
    IPC33bits.USBIS = 1;        // USB Interrupt Sub-Priority 1

    USBCSR0bits.HSEN = 1;       // Enable High Speed (480Mbps) USB mode
    
    USB_line_coding.baud = 9600;
    USB_line_coding.data_bits = 8;
    USB_line_coding.parity_bits = 0;
    USB_line_coding.stop_bits = 1;
}

void USB_send_EP2(const unsigned char *buffer, int size)
{
    int cnt;
    unsigned char *FIFO_buffer;
    
    USBE2CSR0bits.MODE = 1;     // EP2 is TX

    FIFO_buffer = (unsigned char *)&USBFIFO2;
    
    for (cnt = 0; cnt < size; cnt++)
    {
        *FIFO_buffer = buffer[cnt]; // Send the bytes
    }

    USBE2CSR0bits.TXPKTRDY = 1;
}

int USB_EP0_Wait_TXRDY()
{
    int timeout;
    
    timeout = 0;
    
    while (USBE0CSR0bits.TXRDY)
    {
        timeout++;
        if (timeout > USB_EP0_WAIT_TIMEOUT) return 1;
    };
    
    return 0;
}

// Send EP[0].tx_num_bytes from EP[0].tx_buffer on endpoint 0
void USB_send_EP0()
{
    int cnt;
    unsigned char *FIFO_buffer;
        
    FIFO_buffer = (unsigned char *)&USBFIFO0;
    
    if (USB_EP0_Wait_TXRDY()) return;
    
    cnt = 0;
    
    while (cnt < EP[0].tx_num_bytes)
    {
        *FIFO_buffer = EP[0].tx_buffer[cnt]; // Send the bytes
        cnt++;
        // Have we sent 64 bytes?
        if ((cnt > 0) && (cnt % 64 == 0))
        {
            // Set TXRDY and wait for it to be cleared before sending any more bytes
            USBE0CSR0bits.TXRDY = 1;            
            if (USB_EP0_Wait_TXRDY()) return;
        }
    }
    
    USBE0CSR0bits.TXRDY = 1;            
}

void USB_receive_EP0(int length)
{
    int cnt;
    unsigned char *FIFO_buffer;
    
    // Store number of bytes received
    EP[0].rx_num_bytes = USBE0CSR2bits.RXCNT;
                
    // Get 8-bit pointer to USB FIFO for endpoint 0
    FIFO_buffer = (unsigned char *)&USBFIFO0;
    
    for(cnt = 0; cnt < length; cnt++)
    {
        // Read in one byte at a time
        EP[0].rx_buffer[cnt] = *(FIFO_buffer + (cnt & 3));
    }
        
    USBE0CSR0bits.RXRDYC = 1;
}

int USB_receive_EP2()
{
    unsigned char *FIFO_buffer;
    int cnt;
    int bytes_received;
    
    USBE2CSR0bits.MODE = 0;     // EP2 is RX

    bytes_received = USBE2CSR2bits.RXCNT;
    
    FIFO_buffer = (unsigned char *)&USBFIFO2;
    
    for(cnt = 0; cnt < bytes_received; cnt++)
    {
        EP[2].rx_buffer[cnt] = *(FIFO_buffer + (cnt & 3)); // Store the received bytes in array ep0data[].
    }
    
    USBE2CSR1bits.RXPKTRDY = 0;
    
    return bytes_received;
}

void USB_queue_EP0(unsigned char *buffer, int size, int max_size)
{
    int cnt;
    
    if (max_size < size)
        size = max_size;
    
    EP[0].tx_num_bytes = size;
    
    for (cnt = 0; cnt < size; cnt++)
        EP[0].tx_buffer[cnt] = buffer[cnt];

    USB_send_EP0();
}

void __attribute__((vector(_USB_VECTOR), interrupt(ipl7srs), nomips16)) USB_handler()
{
    int cnt;
    unsigned char *FIFO_data;
    
    if(USBCSR2bits.RESETIF)
    {
        // So when this is set, the USB bus has been reset and we actually need to set up all the USB endpoints now

        USB_init_endpoints();
        
        USBCSR2bits.RESETIF = 0;      
        
    }
    
    /* Endpoint 0 Interrupt Hanler */
    if(USBCSR0bits.EP0IF == 1)
    {
        if (USB_set_address) // Do we need the set the USB address?
        {
            USBCSR0bits.FUNC = USB_address & 0x7F;
            USB_set_address = 0;
        }
        
        if(USBE0CSR0bits.RXRDY)
        {
            USB_receive_EP0(USBE0CSR2bits.RXCNT);
            
            USB_transaction.bmRequestType = EP[0].rx_buffer[0];
            USB_transaction.bmRequest = EP[0].rx_buffer[1];
            USB_transaction.wValue = (int)(EP[0].rx_buffer[3] << 8) | EP[0].rx_buffer[2];
            USB_transaction.wIndex = (int)(EP[0].rx_buffer[5] << 8) | EP[0].rx_buffer[4];
            USB_transaction.wLength = (int)(EP[0].rx_buffer[7] << 8) | EP[0].rx_buffer[6];          

            
            USB_EP0_handle_transaction();
            
            if (USB_transaction.wLength == 0) USBE0CSR0bits.DATAEND = 1; // End of Data Control bit (Device mode) 
        }
                
        if (USBE0CSR0bits.SETEND) 
        {
            USBE0CSR0bits.SETENDC = 1;
        }
        
        USBCSR0bits.EP0IF = 0;  // Clear the USB EndPoint 0 Interrupt Flag.
    }
    
    if(USBCSR0bits.EP1TXIF == 1)
    { 
        USBCSR0bits.EP1TXIF = 0;        // Supposedly Cleared By Hardware (Clear Just In Case).
    } 
        
    if(USBE2CSR1bits.RXPKTRDY)
    {
        EP[2].rx_num_bytes = USB_receive_EP2();
        if (USB_receive_callback !=0) 
            (USB_receive_callback)((const char*)EP[2].rx_buffer, (int)EP[2].rx_num_bytes);       
       // USBE2CSR1bits.RXPKTRDY = 0;
        USBCSR1bits.EP2RXIF = 0;
    }  

    if (USBCSR2bits.SOFIF)
    {
        USBCSR2bits.SOFIF = 0;
    }
    
    IFS4bits.USBIF = 0;
}

void USB_connect()
{
    USBCSR0bits.SOFTCONN = 1;
}

