
#include "STD_types.h"
#include "LED_priv.h"
#include "LED_config.h"
#include "LED_int.h"
void LED_voidInit(void)
{
LED_voidSetLedOff(LED_0);
LED_voidSetLedOff(LED_1);
LED_voidSetLedOff(LED_2);	
}

void LED_voidSetLedOn(u8 Locl_LedNo)
{
	if(locl_LedNo==LED_0)
		
		#if(LED0_CONNECTION==FORWARD)		 
			DIO_voidSetPin(LED_PIN0,DIO_HIGH);
		#elif(LED0_CONNECTION==REVERSE)
			DIO_voidSetPin(LED_PIN0,DIO_LOW);
		#endif
		
	else if(locl_LedNo==LED_1)
		
		#if(LED0_CONNECTION==FORWARD)		 
			DIO_voidSetPin(LED_PIN1,DIO_HIGH);
		#elif(LED0_CONNECTION==REVERSE)
			DIO_voidSetPin(LED_PIN1,DIO_LOW);
		#endif
		
	else(locl_LedNo==LED_2)
	
		#if(LED0_CONNECTION==FORWARD)		 
			DIO_voidSetPin(LED_PIN2,DIO_HIGH);
		#elif(LED0_CONNECTION==REVERSE)
			DIO_voidSetPin(LED_PIN2,DIO_LOW);
		#endif
	

}
`
void LED_voidSetLedOff(u8 Locl_LedNo)
{
	if(locl_LedNo==LED_0)
		
		#if(LED0_CONNECTION==FORWARD)		 
			DIO_voidSetPin(LED_PIN0,DIO_LOW);
		#elif(LED0_CONNECTION==REVERSE)
			DIO_voidSetPin(LED_PIN0,DIO_HIGH);
		#endif
		
	else if(locl_LedNo==LED_1)
		
		#if(LED0_CONNECTION==FORWARD)		 
			DIO_voidSetPin(LED_PIN1,DIO_LOW);
		#elif(LED0_CONNECTION==REVERSE)
			DIO_voidSetPin(LED_PIN1,DIO_HIGH);
		#endif
		
	else(locl_LedNo==LED_2)
	
		#if(LED0_CONNECTION==FORWARD)		 
			DIO_voidSetPin(LED_PIN2,DIO_LOW);
		#elif(LED0_CONNECTION==REVERSE)
			DIO_voidSetPin(LED_PIN2,DIO_HIGH);
		#endif
	
}