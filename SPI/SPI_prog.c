#include "std_types.h"
#include "utils.h"
#include <util/delay.h>
#include <avr/interrupt.h>

#include "SPI_priv.h"
#include "SPI_config.h"
#include "SPI_int.h"

void (*SPI_ISR)(void)  = '\0';

void SPI_voidInit(void)
{

    /*** Set as Master ***/
    SETBIT(SPCR, MSTR);

    /*** Enable SPI Interrupt ***/
    SETBIT(SPCR, SPIE);

    /*** Enable SPI ***/
    SETBIT(SPCR, SPE);

    /*** Set Clock Polarity ***/
    #if (SPI_CLK_POLARITY == CLK_POLARITY_IDLE_HIGH)
        SETBIT(SPCR, CPOL);
    #elif (SPI_CLK_POLARITY == CLK_POLARITY_IDLE_LOW)
        CLRBIT(SPCR, CPOL);
    #endif

    /*** Set Clock Phase ***/
    #if (SPI_CLK_PHASE == CLK_PHASE_SAMPLE_LEADING_EDGE)
        CLRBIT(SPCR, CPHA);
    #elif (SPI_CLK_PHASE == CLK_PHASE_SAMPLE_TRAILING_EDGE)
        SETBIT(SPCR, CPHA);
    #endif

    /*** Set Clock Rate ***/
    #if (SPI_PRESCALER == PRESCALER_4)
        CLRBIT(SPSR, SPI2X);
        CLRBIT(SPCR, SPR0);
        CLRBIT(SPCR, SPR1);
    #elif (SPI_PRESCALER == PRESCALER_16)
        CLRBIT(SPSR, SPI2X);
        SETBIT(SPCR, SPR0);
        CLRBIT(SPCR, SPR1);
    #elif (SPI_PRESCALER == PRESCALER_64)
        CLRBIT(SPSR, SPI2X);
        CLRBIT(SPCR, SPR0);
        SETBIT(SPCR, SPR1);
    #elif (SPI_PRESCALER == PRESCALER_128)
        CLRBIT(SPSR, SPI2X);
        SETBIT(SPCR, SPR0);
        SETBIT(SPCR, SPR1);
    #elif (SPI_PRESCALER == PRESCALER_2)
        SETBIT(SPSR, SPI2X);
        CLRBIT(SPCR, SPR0);
        CLRBIT(SPCR, SPR1);
    #elif (SPI_PRESCALER == PRESCALER_8)
        SETBIT(SPSR, SPI2X);
        SETBIT(SPCR, SPR0);
        CLRBIT(SPCR, SPR1);
    #elif (SPI_PRESCALER == PRESCALER_32)
        SETBIT(SPSR, SPI2X);
        CLRBIT(SPCR, SPR0);
        SETBIT(SPCR, SPR1);
    #endif

}

void SPI_voidSetDataRegister(u8 Local_Data)
{
    SPDR = Local_Data;
}

u8 SPI_u8GetDataRegister(void)
{
    return SPDR;
}

void SPI_voidSetISR(void (*Local_ISR)(void))
{
    SPI_ISR = Local_ISR;
}

ISR(SPI_STC_vect)
{
    SPI_ISR();
}

