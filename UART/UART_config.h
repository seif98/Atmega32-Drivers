#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/** 
    fosc_1Mhz  
    fosc_1_8Mhz    
    fosc_2Mhz      
    fosc_3_6Mhz    
    fosc_4Mhz      
    fosc_7_3Mhz    
    fosc_8Mhz      
    fosc_11_05Mhz  
    fosc_14_7Mhz   
    fosc_16Mhz     
    fosc_18_4Mhz   
    fosc_20Mhz
 **/
#define fosc fosc_1Mhz

/**
 * BAUD_RATE_2400
 * BAUD_RATE_4800
 * BAUD_RATE_9600
 * BAUD_RATE_14400
 * BAUD_RATE_19200
 * BAUD_RATE_28800
 * BAUD_RATE_38400
 * BAUD_RATE_57600
 * BAUD_RATE_115200
 **/

#define UART_BAUD_RATE  BAUD_RATE_9600

/** sets the doubling of Baud
 * UART_SINGLE
 * UART_DOUBLE
**/
#define UART_BAUD SINGLE

/**
NO_PARITY         
EVEN_PARITY       
ODD_PARITY       
**/
#define UART_PARITY     NO_PARITY

/**
 * STOP_BIT_1
 * STOP_BIT_2
 **/
#define UART_STOP_BIT   STOP_BIT_1






#endif
