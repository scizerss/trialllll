/*
* KEYPAD.c
*
* Created: 1/22/2021 10:06:54 PM
*  Author: karim
*/

#include "KEYPAD.h"

const uint8_t KEYPAD[4][4] =
{
	{'7','4','1','C'},
	{'8','5','2','0'},
	{'9','6','3','='},
	{'/','*','-','+'}
};


void KEYPAD_Init(void)/*Initialize keypad*/
{
	/*Define direction for output pins*/
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_OUT_PIN0, KEYPAD_OUTPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_OUT_PIN1, KEYPAD_OUTPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_OUT_PIN2, KEYPAD_OUTPUT);
	DIO_SetPin_DirectionDIO_SET(KEYPAD_PORT, KEYPAD_OUT_PIN3, KEYPAD_OUTPUT);
	/*Define direction for input pins*/
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_INP_PIN0, KEYPAD_INPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_INP_PIN1, KEYPAD_INPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_INP_PIN2, KEYPAD_INPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_INP_PIN3, KEYPAD_INPUT);
	/*Activate internal pull-up resistor*/
	DIO_SetPin_PullUp(KEYPAD_PORT, KEYPAD_INP_PIN0);
	DIO_SetPin_PullUp(KEYPAD_PORT, KEYPAD_INP_PIN1);
	DIO_SetPin_PullUp(KEYPAD_PORT, KEYPAD_INP_PIN2);
	DIO_SetPin_PullUp(KEYPAD_PORT, KEYPAD_INP_PIN3);
	/*All output should be normally high*/
	DIO_SetPin_State(KEYPAD_PORT, KEYPAD_OUT_PIN0, KEYPAD_HIGH);
	DIO_SetPin_State(KEYPAD_PORT, KEYPAD_OUT_PIN1, KEYPAD_HIGH);
	DIO_SetPin_State(KEYPAD_PORT, KEYPAD_OUT_PIN2, KEYPAD_HIGH);
	DIO_SetPin_State(KEYPAD_PORT, KEYPAD_OUT_PIN3, KEYPAD_HIGH);
}

uint8_t KEYPAD_READ(void)/*Read keypad value*/
{
	uint8_t LOC_COL = 0; /*Counter for columns*/
	uint8_t LOC_ROW = 0; /*Counter for rows*/
	uint8_t temp = 0;    /*To get reading from keypad*/
	uint8_t val = 0;     /*To check value inside array 2D*/
	for(LOC_COL = COL_INIT; LOC_COL <= COL_FINAL; LOC_COL++)
	{
		DIO_SetPin_State(KEYPAD_PORT, LOC_COL, KEYPAD_LOW);
		for (LOC_ROW = ROW_INIT; LOC_ROW <= ROW_FINAL; LOC_ROW++)
		{
			temp = DIO_GetPin_State(KEYPAD_PORT, LOC_ROW);
			if(temp == 0)/*Active LOW*/
			{
				val = KEYPAD[LOC_ROW - ROW_INIT][LOC_COL - COL_INIT];
				//De-bounce
				while (temp == 0)
				{
					temp = DIO_GetPin_State(KEYPAD_PORT, LOC_ROW);
				}
				_delay_ms(10);
				//End of De-bounce
			}
		}
		DIO_SetPin_State(KEYPAD_PORT, LOC_COL, KEYPAD_HIGH);
	}
	return val;
}