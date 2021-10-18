#include "std_types.h"
#include "utils.h"
#include <util/delay.h>
#include <avr/interrupt.h>

#include "ExtInterrupt_priv.h"
#include "ExtInterrupt_config.h"
#include "ExtInterrupt_int.h"

void (*ISR0)(void) = '\0';
void (*ISR1)(void) = '\0';
void (*ISR2)(void) = '\0';

void ExtInterrupt_voidInit(void)
{
    /*** Configure Interrupt Sense Control ***/
    #if (INT0_SENSE == LOW_LEVEL)
        CLRBIT(MCUCR, ISC00);
        CLRBIT(MCUCR, ISC01);
    #elif (INT0_SENSE == LOGICAL_CHANGE)
        SETBIT(MCUCR, ISC00);
        CLRBIT(MCUCR, ISC01);
    #elif (INT0_SENSE == FALLING_EDGE)
        CLRBIT(MCUCR, ISC00);
        SETBIT(MCUCR, ISC01);
    #elif (INT0_SENSE == RISING_EDGE)
        SETBIT(MCUCR, ISC00);
        SETBIT(MCUCR, ISC01);
    #endif

    #if (INT1_SENSE == LOW_LEVEL)
        CLRBIT(MCUCR, ISC10);
        CLRBIT(MCUCR, ISC11);
    #elif (INT1_SENSE == LOGICAL_CHANGE)
        SETBIT(MCUCR, ISC10);
        CLRBIT(MCUCR, ISC11);
    #elif (INT1_SENSE == FALLING_EDGE)
        CLRBIT(MCUCR, ISC10);
        SETBIT(MCUCR, ISC11);
    #elif (INT1_SENSE == RISING_EDGE)
        SETBIT(MCUCR, ISC10);
        SETBIT(MCUCR, ISC11);
    #endif

    #if (INT2_SENSE == FALLING_EDGE)
        CLRBIT(MCUCSR, ISC2);
    #elif (INT2_SENSE == RISING_EDGE)
        SETBIT(MCUCSR, ISC2);
    #endif

    /*** Enable/Disable Interrupts ***/

    #if (INT0_EN == INT_ENABLE)
        SETBIT(GICR,INT0);
    #elif (INT0_EN == INT_DISABLE)
        CLRBIT(GICR,INT0);
    #endif

    #if (INT1_EN == INT_ENABLE)
        SETBIT(GICR,INT1);
    #elif (INT1_EN == INT_DISABLE)
        CLRBIT(GICR,INT1);
    #endif

    #if (INT2_EN == INT_ENABLE)
        SETBIT(GICR,INT2);
    #elif (INT2_EN == INT_DISABLE)
        CLRBIT(GICR,INT2);
    #endif

    /*** Clear Interrupts Flags ***/
    SETBIT(GIFR,INTF0);
    SETBIT(GIFR,INTF1);
    SETBIT(GIFR,INTF2);

}

void ExtInterrupt_voidSetINT0_ISR(void (*Local_ISR0)(void))
{
    ISR0 = Local_ISR0;
}

void ExtInterrupt_voidSetINT1_ISR(void (*Local_ISR1)(void))
{
    ISR1 = Local_ISR1;
}

void ExtInterrupt_voidSetINT2_ISR(void (*Local_ISR2)(void))
{
    ISR2 = Local_ISR2;
}

ISR(INT0_vect)
{
    ISR0();
}

ISR(INT1_vect)
{
    ISR1();
}

ISR(INT2_vect)
{
    ISR2();
}
