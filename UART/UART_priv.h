#ifndef UART_PRIV_H_
#define UART_PRIV_H_

/*** Baud Rate ***/
#define BAUD_RATE_2400    2400
#define BAUD_RATE_4800    4800
#define BAUD_RATE_9600    9600
#define BAUD_RATE_14400   14400
#define BAUD_RATE_19200   19200
#define BAUD_RATE_28800   28800
#define BAUD_RATE_38400   38400
#define BAUD_RATE_57600   57600
#define BAUD_RATE_115200  115200

/*** Parity mode ***/
#define NO_PARITY         9
#define EVEN_PARITY       10
#define ODD_PARITY        11

/*** Stop Bit ***/
#define STOP_BIT_1        12
#define STOP_BIT_2        13

/** UART_fosc **/
#define fosc_1Mhz      1000000
#define fosc_1_8Mhz    1843200
#define fosc_2Mhz      2000000
#define fosc_3_6Mhz    3686400
#define fosc_4Mhz      4000000
#define fosc_7_3Mhz    7372800
#define fosc_8Mhz      8000000
#define fosc_11_05Mhz  11059200
#define fosc_14_7Mhz   14745600
#define fosc_16Mhz     16000000
#define fosc_18_4Mhz   18432000
#define fosc_20Mhz     20000000

/** DOUBLE BAUD **/
#define UART_SINGLE 0
#define UART_HIGH   1


#endif
