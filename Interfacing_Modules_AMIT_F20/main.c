#include "LCD.h"
#include "ADC.h"
#include "OUTPUT_Module.h"


int main(void)
{
	LCD_Init();
	ADC_Initialize();
	LCD_CLEAR();
	uint16_t voltage;
	while (1)
	{
		voltage=ADC_Read();
		_delay_ms(50);
		if (voltage != 0)
		{
			LCD_CLEAR();
			LCD_WRITE_STR("voltage = ");
			LCD_WRITE_NBR(voltage);
			_delay_ms(150);
			voltage=0;
		}
		
		
	}
}
