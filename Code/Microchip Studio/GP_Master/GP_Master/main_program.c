#include 		"BIT_MATH.h"
#include		"STD_TYPES.h"
#include 		"main_interface.h"
#include 		"Dio_interface.h"
#include 		"Dio_private.h"
#include 		"LCD_interface.h"

#include		<util/delay.h>


void	Toggle_Led1(void)
{
	LCD_Clear();
	PORT_LED1 ^= (1<<PIN_LED1);
	LCD_WriteSTring("Led 1 Toggled");
	_delay_ms(500);
}

void	Toggle_Led2(void)
{	
	LCD_Clear();
	PORT_LED2 ^= (1<<PIN_LED2);
	LCD_WriteSTring("Led 2 Toggled");
	_delay_ms(500);
}