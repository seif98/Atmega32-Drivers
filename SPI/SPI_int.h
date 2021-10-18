#ifndef SPI_INT_H_
#define SPI_INT_H_

#include "STD_TYPES.h"

void SPI_voidInit(void);
void SPI_voidSetDataRegister(u8 Local_Data);
u8 SPI_u8GetDataRegister(void);
void SPI_voidSetISR(void (*Local_ISR)(void));

#endif /* SPI_INT_H_ */
