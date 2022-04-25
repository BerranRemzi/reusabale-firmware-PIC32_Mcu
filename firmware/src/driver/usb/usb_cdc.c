#include <xc.h>
#include "USB.h"

void USB_EP0_handle_transaction()
{
    int cnt;
    unsigned char temp_data[7];
    USB_LINE_CODING new_line_coding;
    
    // We're not going to bother with whether bmRequestType is IN or OUT for the most part
    switch (USB_transaction.bmRequest)
    {
        case 0xC:
        {
            USBE0CSR0bits.STALL = 1;
            break;
            
        }
        case 0x0: 
        {
            if (USB_transaction.bmRequestType == 0x80) // Get status
                USB_queue_EP0(USB_device_description, 0, 0);
            if (USB_transaction.bmRequestType == 0x00) // Select function
                USB_queue_EP0(USB_device_description, 0, 0);
            break;            
        }
        
        case 0x5: // Set USB address
        {
            USBE0CSR0bits.RXRDYC = 1;
            USB_address = EP[0].rx_buffer[2];
            USB_set_address = 1;
            break;
        }

        case 0x6: // Get descriptor
        {
            switch (USB_transaction.wValue >> 8)
            {
                case 0x1: // Get device descriptor
                {
                    USB_queue_EP0(USB_device_description, sizeof(USB_device_description), USB_transaction.wLength);
                    break;
                }
                
                case 0x2: // Get configuration descriptor
                {
                    USB_queue_EP0(USB_config_descriptor, sizeof(USB_config_descriptor), USB_transaction.wLength);
                    break;
                }
                
                case 0x3: // Get string descriptors
                {
                    switch (USB_transaction.wValue & 0xFF)
                    {
                        case 0x0: // String 0 - Language ID
                        {
                            USB_queue_EP0(string0, sizeof(string0), USB_transaction.wLength);
                            break;
                        }
                        case 0x1: // String 1 - Vendor
                        {
                            USB_queue_EP0(string1, sizeof(string1), USB_transaction.wLength);
                            break;
                        }
                        case 0x2: // String 2 - Product name
                        {
                            USB_queue_EP0(string2, sizeof(string2), USB_transaction.wLength);
                            break;
                        }
                        case 0x3: // String 3 - Serial number
                        {
                            USB_queue_EP0(string3, sizeof(string3), USB_transaction.wLength);
                            break;
                        }
                        case 0x4: // String 4 - Configuration
                        {
                            USB_queue_EP0(string4, sizeof(string4), USB_transaction.wLength);
                            break;
                        }
                        case 0x5: // String 5 - Interface
                        {
                            USB_queue_EP0(string5, sizeof(string5), USB_transaction.wLength);
                            break;
                        }
                        default: break;
                    }
                }
                default: 
                {
                    break;
                }
            }
            break;
        }
        
        case 0x9: // Set interface
        {            
            break;
        }
        
        case 0x20:
        {
            if (USB_transaction.bmRequestType == 0x21)
            {
                // Set line coding
                // Read (wLength) bytes from USB Endpoint 0
                USB_receive_EP0(USB_transaction.wLength);
                
                USB_line_coding.baud = ((int)EP[0].rx_buffer[3] << 24) | ((int)EP[0].rx_buffer[2] << 16) | ((int)EP[0].rx_buffer[1] << 8) | EP[0].rx_buffer[0];
                USB_line_coding.parity_bits = EP[0].rx_buffer[4];
                USB_line_coding.stop_bits = EP[0].rx_buffer[5];
                USB_line_coding.data_bits = EP[0].rx_buffer[6];
            }
            break;
           
        }
        
        case 0x21:
        {
            // Get line coding
            temp_data[0] = USB_line_coding.baud & 0xFF;
            temp_data[1] = (USB_line_coding.baud >> 8) & 0xFF;
            temp_data[2] = (USB_line_coding.baud >> 16) & 0xFF;
            temp_data[3] = USB_line_coding.baud >> 24;
            temp_data[4] = USB_line_coding.stop_bits;
            temp_data[5] = USB_line_coding.parity_bits;
            temp_data[6] = USB_line_coding.data_bits;
            USB_queue_EP0(temp_data, sizeof(temp_data), USB_transaction.wLength);
            break;
        }
        
        case 0x22:
        {
            if (USB_transaction.bmRequestType == 0x21)
            {
                 // Set line control state
                USB_line_control_state = USB_transaction.wValue >> 8;
                (USB_connected_callback)();                
            }
            break;
        }
        
        default: 
        {
            USBE0CSR0bits.STALL = 1;
            break;
        }
    }   
}

void USB_CDC_send(unsigned char *data, int size){
     USB_send_EP2(data, size);
}