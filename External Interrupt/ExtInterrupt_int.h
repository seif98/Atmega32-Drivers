#ifndef EXTINTERRUPT_INT_H_
#define EXTINTERRUPT_INT_H_

void ExtInterrupt_voidInit(void);

void ExtInterrupt_voidSetINT0_ISR(void (*Local_ISR0)(void));
void ExtInterrupt_voidSetINT1_ISR(void (*Local_ISR1)(void));
void ExtInterrupt_voidSetINT2_ISR(void (*Local_ISR2)(void));


#endif /* EXTINTERRUPT_INT_H_*/
