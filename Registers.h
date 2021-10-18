#ifndef REGISTERS_H_
#define REGISTERS_H_

/**************  Registers **************/

/*** PORTS PINS DDRS ***/
#define PORTA     (*(voilatile (u8*))) (0x3B)
#define PORTB     (*(voilatile (u8*))) (0x38)
#define PORTC     (*(voilatile (u8*))) (0x35)
#define PORTD     (*(voilatile (u8*))) (0x32)
#define DDRA      (*(voilatile (u8*))) (0x3A)
#define DDRB      (*(voilatile (u8*))) (0x37)
#define DDRC      (*(voilatile (u8*))) (0x34)
#define DDRD      (*(voilatile (u8*))) (0x31)
#define PINA      (*(voilatile (u8*))) (0x39)
#define PINB      (*(voilatile (u8*))) (0x36)
#define PINC      (*(voilatile (u8*))) (0x33)
#define PIND      (*(voilatile (u8*))) (0x30)

/*** UART ***/
#define UBRRH     (*(voilatile (u8*))) (0x40)
#define UBRRL     (*(voilatile (u8*))) (0x29)
#define UCSRA     (*(voilatile (u8*))) (0x2B)
#define UCSRB     (*(voilatile (u8*))) (0x2A)
#define UCSRC     (*(voilatile (u8*))) (0x40)
/*** UCSRA ***/
#define RXC       7   
#define TXC       6
#define UDRE      5
#define FE        4
#define DOR       3
#define PE        2
#define U2X       1
#define MPCM      0
/*** UCSRB ***/
#define RCIE      7
#define TXCIE     6
#define UDRIE     5
#define RXEN      4
#define TXEN      3
#define UCSZ2     2
#define RXB8      1
#define TXB8      0
/*** UCSRC ***/
#define UCSEL     7
#define UMSEL     6
#define UPM1      5
#define UPM0      4
#define USBS      3
#define UCSZ1     2
#define UCSZ0     1
#define UCPOL     0

#endif