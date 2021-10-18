#include "std_types.h"
#include "utils.h"
#include <util/delay.h>
#include <avr/interrupt.h>

#include "ADC_priv.h"
#include "ADC_config.h"
#include "ADC_int.h"

void (*ADC_ISR)(void) = '\0';

void ADC_voidInit(void)
{
        #if (VREF == AREF_PIN)
            CLRBIT(ADMUX, REFS0);
            CLRBIT(ADMUX, REFS1);
        #elif (VREF == AVCC_PIN)
            SETBIT(ADMUX, REFS0);
            CLRBIT(ADMUX, REFS1);
        #elif (VREF == INTERNAL_VREF)
            SETBIT(ADMUX, REFS0);
            SETBIT(ADMUX, REFS1);
        #endif

        /*** Set Input Channel ***/

        CLRBIT(ADMUX, MUX4);
        CLRBIT(ADMUX, MUX3);

        #if (INPUT_CHANNEL == ADC0_CH)
            CLRBIT(ADMUX, MUX2);
            CLRBIT(ADMUX, MUX1);
            CLRBIT(ADMUX, MUX0);
        #elif (INPUT_CHANNEL == ADC1_CH)
            CLRBIT(ADMUX, MUX2);
            CLRBIT(ADMUX, MUX1);
            SETBIT(ADMUX, MUX0);
        #elif (INPUT_CHANNEL == ADC2_CH)
            CLRBIT(ADMUX, MUX2);
            SETBIT(ADMUX, MUX1);
            CLRBIT(ADMUX, MUX0);
        #elif (INPUT_CHANNEL == ADC3_CH)
            CLRBIT(ADMUX, MUX2);
            SETBIT(ADMUX, MUX1);
            SETBIT(ADMUX, MUX0);
        #elif (INPUT_CHANNEL == ADC4_CH)
            SETBIT(ADMUX, MUX2);
            CLRBIT(ADMUX, MUX1);
            CLRBIT(ADMUX, MUX0);
        #elif (INPUT_CHANNEL == ADC5_CH)
            SETBIT(ADMUX, MUX2);
            CLRBIT(ADMUX, MUX1);
            SETBIT(ADMUX, MUX0);
        #elif (INPUT_CHANNEL == ADC6_CH)
            SETBIT(ADMUX, MUX2);
            SETBIT(ADMUX, MUX1);
            CLRBIT(ADMUX, MUX0);
        #elif (INPUT_CHANNEL == ADC7_CH)
            SETBIT(ADMUX, MUX2);
            SETBIT(ADMUX, MUX1);
            SETBIT(ADMUX, MUX0);
        #endif

        CLRBIT(ADMUX, ADLAR);

        /*** Configure control and status register ***/
        SETBIT(ADCSRA, ADEN);
        CLRBIT(ADCSRA, ADSC);
        CLRBIT(ADCSRA, ADATE);
        SETBIT(ADCSRA, ADIF);
        SETBIT(ADCSRA, ADIE);

        SETBIT(ADCSRA, ADPS0);
        SETBIT(ADCSRA, ADPS1);
        SETBIT(ADCSRA, ADPS2);

}

void ADC_voidSetISR(void (*Local_ISR)(void))
{
    ADC_ISR = Local_ISR;
}

void ADC_voidStartConv(void)
{
    SETBIT(ADCSRA, ADSC);
}

u16 ADC_u16GetData(void)
{
    return ADCW;
}


ISR(ADC_vect)
{
    ADC_ISR();
}
