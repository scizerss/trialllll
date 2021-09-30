/*
 * OUTPUT_Module.c
 *
 * Created: 8/7/2021 10:20:07 PM
 *  Author: karim
 */ 


#include "OUTPUT_Module.h"

void LED0_Initialize(void)
{
	DIO_SetPin_Direction(LED0_DDR, LED0, LED_OUTPUT);
}
void LED0_ON(void)
{
	DIO_SetPin_State(LED0_PRT, LED0, LED_HIGH);
}
void LED0_OFF(void)
{
	DIO_SetPin_State(LED0_PRT, LED0, LED_LOW);
}
void LED0_Toggle(void)
{
	DIO_TglPin_State(LED0_PRT, LED0);
}
