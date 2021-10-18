#ifndef SEG_INT_H
#define SEG_INT_H

void SEG_voidInit(void);
void SEG_voidDisplay(u8 local_SegNo, u8 local_DispNum);
void SEG_voidTurnOff7Seg(u8 local_SegNo);

#define SEG_0 0
#define SEG_1 1

#endif