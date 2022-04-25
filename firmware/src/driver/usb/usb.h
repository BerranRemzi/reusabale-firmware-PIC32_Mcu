#ifndef _USB_H 
#define _USB_H

#define MAX_USB_BUFFER_SIZE     (512)
#define USB_EP0_WAIT_TIMEOUT    (1000)

typedef struct
{
    int baud;
    short stop_bits;
    short parity_bits;
    short data_bits;
} USB_LINE_CODING;

typedef struct
{
    uint16_t rx_num_bytes;
    uint16_t tx_num_bytes;
    uint8_t tx_buffer[MAX_USB_BUFFER_SIZE];
    uint8_t rx_buffer[MAX_USB_BUFFER_SIZE];
} USB_ENDPOINT;

typedef struct
{
    uint8_t bmRequestType;
    uint8_t bmRequest;
    uint16_t wValue;
    uint16_t wIndex;
    uint16_t wLength;
} USB_TRANSACTION;



extern unsigned char USB_address ;
extern volatile char USB_set_address ;
extern volatile char USB_line_control_state ;

extern volatile  USB_ENDPOINT EP[3];
extern volatile USB_TRANSACTION USB_transaction;
extern volatile USB_LINE_CODING USB_line_coding;

extern void (*USB_receive_callback)(const unsigned char *buffer, int length);
extern void (*USB_connected_callback)(void) ;

#define	STR_DESC(l)	(((((l))<<1) & 0xFF) | 0x0300)
// String descriptors. All have a common format: [byte] string_length, [byte] data_type (3 = string), UTF-16 encoded string, hence all the 0's between each 8-byte character


static const unsigned char USB_device_description[] = {
/* Descriptor Length						*/ 18, /* Always 18 or 0x12 */
/* DescriptorType: DEVICE					*/ 0x01,
/* bcdUSB (ver 2.0)							*/ 0x00,0x02,
/* bDeviceClass								*/ 0x00,
/* bDeviceSubClass							*/ 0x00,
/* bDeviceProtocol							*/ 0x00,
/* bMaxPacketSize0							*/ 0x40, /* Always 64 or 0x40 for High Speed USB */
/* idVendor									*/ 0xD8,0x04, /* e.g. - 0x04D8 - Microchip VID */
/* idProduct								*/ 0x0A,0x00, /* e.g. - 0x000A */
/* bcdDevice								*/ 0x00,0x01, /* e.g. - 02.00 */
/* iManufacturer							*/ 0x01,
/* iProduct									*/ 0x02,
/* iSerialNumber							*/ 0x03, 
/* bNumConfigurations						*/ 0x01
};

// Language description
static const unsigned char string0[] =  { 4, 0x03, 0x09, 0x04}; // 0x0409 = English

// Vendor description
static const unsigned short string1[] = { STR_DESC(12),
                            'O','N',' ','S','e','m','i','c','o','n','d','u','c','t','o','r'};   

// Product description
static const unsigned short string2[] = { STR_DESC(13),
                            'O','N',' ','M','C','U',' ','v','2'};
 
// Serial number description
static const unsigned short string3[] = { STR_DESC(8),
                            '9','9','9','9','9','9','9'};

// Configuration description
static const unsigned short string4[] = { STR_DESC(9),
                            'O','N',' ','M','C','U','v','2'};
// Interface description 
static const unsigned short string5[] = { STR_DESC(4),
                            'C','D','C'};


static const unsigned char USB_config_descriptor[] = {

/*********************************************************************
 Configuration Descriptors 
 *********************************************************************/
/*  bLength (Descriptor Length)             */ 9, 
/*  bDescriptorType: CONFIG					*/ 0x02,
/*  wTotalLength							*/ 0x43,0x00,
/*  bNumInterfaces							*/ 2, 
/*  bConfigurationValue						*/ 1, 
/*  iConfiguration							*/ 0, 
/*  bmAttributes							*/ 0x80, /* bit 6 set = bus powered = 0x80, 0xC0 is for self powered */
/*  bMaxPower								*/ 0x32, /* Value x 2mA, set to 0 for self powered, was 0x32 */
/*********************************************************************
  Interface 0 - Communications Class
 *********************************************************************/                                               
/* bLength                                  */ 0x09,
/* bDescriptorType: INTERFACE               */ 0x04,
/* bInterfaceNumber                         */ 0x00,
/* bAlternateSetting                        */ 0x00,
/* bNumEndpoints: 0 endpoint(s)             */ 0x01,
/* bInterfaceClass: CDC                     */ 0x02,
/* bInterfaceSubclass:Abstract Control Model*/ 0x02,
/* bInterfaceProtocol:AT Commands V.25ter   */ 0x01,
/* iInterface                               */ 0x00,
/*********************************************************************
 Header Functional Descriptor
 *********************************************************************/                                               
/* bLength                                  */ 0x05,
/* bDescriptorType: CS_INTERFACE            */ 0x24,
/* bDescriptorSubtype: HEADER FD            */ 0x00,
/* bcdADC                                   */ 0x20,0x01,
/*********************************************************************
 Abstract Control Model Functional Descriptor
 *********************************************************************/                                               
/* bLength                                  */ 0x04,
/* bDescriptorType: CS_INTERFACE            */ 0x24,
/* bDescriptorSubtype: ACM-FD               */ 0x02,
/* bmCapabilities                           */ 0x02,
/*********************************************************************
 Union Functional Descriptor
 *********************************************************************/                                               
/* bLength                                  */ 0x05,
/* bDescriptorType: CS_INTERFACE            */ 0x24,
/* bDescriptorSubtype: Union FD             */ 0x06,
/* bControlInterface                        */ 0x00,
/* bSubordinateInterface                    */ 0x01,
/*********************************************************************
 Call Management Functional Descriptor
 *********************************************************************/
/* bLength                                  */ 0x05,
/* bDescriptorType: CS_INTERFACE            */ 0x24,
/* bDescriptorSubtype: CM-FD                */ 0X01,
/* bmCapabilities                           */ 0x00,
/* bDataInterface                           */ 0x01,
/*********************************************************************
 Interrupt IN Endpoint - 1
 *********************************************************************/                                               
/* bLength                                  */ 0x07,
/* bDescriptorType: ENDPOINT                */ 0x05,
/* bEndpointAddress: IN Endpoint 1          */ 0x81, 
/* bmAttributes: INTERRUPT                  */ 0x03, 
/* max packet size (LSB)                    */ 0x10,
/* max packet size (MSB)                    */ 0x00,
/* polling interval                         */ 0x2, 
/*********************************************************************
 Interface 1 - Data Class Interface
 *********************************************************************/                                               
/* bLength                                  */ 0x09,
/* bDescriptorType: INTERFACE               */ 0x04,
/* interface index                          */ 0x01,
/* alt setting index                        */ 0x00,
/* bNumEndpoints: 2 endpoint(s)             */ 0x02,
/* bInterfaceClass: CDC-Data                */ 0x0A,
/* bInterfaceSubclass: unused               */ 0x00,
/* bInterfaceProtocol: None                 */ 0x00,
/* iInterface                               */ 0x00,
/*********************************************************************
 Endpoint 2 (Bulk IN)
 *********************************************************************/
/* bLength                                  */ 0x07,
/* bDescriptorType: ENDPOINT                */ 0x05,
/* bEndpointAddress: IN Endpoint 3          */ 0x02, 
/* bmAttributes: BULK                       */ 0x02,
/* max packet size (LSB)                    */ 0x00,
/* max packet size (MSB)                    */ 0x02,
/* bInterval: None for BULK                 */ 0x00,
/*********************************************************************
 Endpoint 2 (Bulk OUT)
 *********************************************************************/                                               
/* bLength                                  */ 0x07,
/* bDescriptorType: ENDPOINT                */ 0x05,
/* bEndpointAddress: OUT Endpoint 2         */ 0x82,
/* bmAttributes: BULK                       */ 0x02,
/* max packet size (LSB)                    */ 0x00,
/* max packet size (MSB)                    */ 0x02,
/* bInterval: None for BULK                 */ 0x00
};


void USB_init(void *receive_callback, void *connected_callback);
void USB_connect();
void USB_send_EP2(const unsigned char *buffer, int size);


#endif /* _USB_H */