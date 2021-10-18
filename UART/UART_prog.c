#include "UART_priv.h"
#include "UART_config.h"
#include "UART_int.h"

#define UBRR_1 (f32) ((UART_fosc/(16*UART_BAUD_RATE ))-1)
#if ((UBRR_1 - (u16) UBRR_1) >= 0.5)
#define UBRR (u16) UBRR_1 + 1
#else
#define UBRR (u16) UBRR_1
#endif

/*** pointers to the functions used in ISR ***/
void (*TX_COMPLETE_ISR)(void)  = NULL;
void (*RX_COMPLETE_ISR)(void)  = NULL;

void UART_voidInit(void)
{
    /*** Double the transmission speed ***/
    #if (UART_BAUD == UART_SINGLE)
    CLRBIT(UCSRA, U2X);
    #elif (UART_BAUD == UART_DOUBLE)
    SETBIT(UCSRA, U2X);
    #endif

    /*** Enable Tx and Rx ***/
    SETBIT(UCSRB, RXEN);
    SETBIT(UCSRB, TXEN);

    /*** Enable Tx and Rx Complete Interrupts ***/
    SETBIT(UCSRB, RXCIE);
    SETBIT(UCSRB, TXCIE);

    /*** Set 8-bit mode ***/
    CLRBIT(UCSRB, UCSZ2);

    /*** Select UCSRC Register ***/
    SETBIT(UCSRC, URSEL);

    /*** Set 8-bit mode ***/
    SETBIT(UCSRC, UCSZ0);
    SETBIT(UCSRC, UCSZ1);


    /*** Set Parity mode ***/
    #if (UART_PARITY == NO_PARITY)
        CLRBIT(UCSRC, UPM0);
        CLRBIT(UCSRC, UPM1);
    #elif (UART_PARITY == EVEN_PARITY)
        CLRBIT(UCSRC, UPM0);
        SETBIT(UCSRC, UPM1);
    #elif (UART_PARITY == ODD_PARITY)
        SETBIT(UCSRC, UPM0);
        SETBIT(UCSRC, UPM1);
    #endif

    /*** Set Stop bit ***/
    #if (UART_STOP_BIT == STOP_BIT_1)
        CLRBIT(UCSRC, USBS);
    #elif (UART_STOP_BIT == STOP_BIT_2)
        SETBIT(UCSRC, USBS);
    #endif


    /** set Baud Rate **/
    UBRRH = (u8) (UBRR >> 8);
    UBRRL = (u8) UBRR;
    
} 

void UART_voidSetDataRegister(u8 Local_Data)
{
    UDR = Local_Data;
}

u8 UART_u8GetDataRegister(void)
{
    return UDR;
}

void UART_voidSetTxComplete_ISR(void (*Local_ISR)(void))
{
    TX_COMPLETE_ISR = Local_ISR;
}

void UART_voidSetRxComplete_ISR(void (*Local_ISR)(void))
{
    RX_COMPLETE_ISR = Local_ISR;
}

void __vector_13 (void) __attribute__ ((signal, used, externally_visible))
{
    TX_COMPLETE_ISR();
}

void __vector_15 (void) __attribute__ ((signal, used, externally_visible))
{
    RX_COMPLETE_ISR();
}

