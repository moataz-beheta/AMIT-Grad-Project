/*
 * GP_Master.c
 *
 * Created: 8/29/2021 1:01:09 AM
 * Author : Moataz
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Dio_interface.h"
#include "Dio_private.h"
#include "USART_interface.h"
#include "LCD_interface.h"
#include "SPI_interface.h"
#include "main_interface.h"
#define F_CPU	8000000UL
#include "util/delay.h"

int main(void)
{	
	u8 Command=0;
	
	/*		Set pin direction for RX and TX pins		*/
	DIO_voidSetPinDirection(RX,	INPUT);
	DIO_voidSetPinDirection(TX,	OUTPUT);
	/*		UART Initialization							*/
	USART_INIT();

	/*		Set Pin Direction for LCD Pins				*/
	DIO_voidSetPortDirection(PORTA,	0xFF);
	DIO_voidSetPinDirection(PORTB,	PIN1,	OUTPUT);
	DIO_voidSetPinDirection(PORTB,	PIN2,	OUTPUT);
	DIO_voidSetPinDirection(PORTB,	PIN3,	OUTPUT);

	/*		LCD Initialization							*/
	LCD_init();
	
	/*		SPI Initialization							*/
	SPI_Slave_init				();
	SPI_Clock_Data_Setting		();
	
	/*		Set Pin Direction for SPI Pins				*/
	DIO_voidSetPinDirection(MOSI, OUTPUT);
	DIO_voidSetPinDirection(MISO, INPUT);
	DIO_voidSetPinDirection(SCK, OUTPUT);
	DIO_voidSetPinDirection(SS, INPUT);
	
	/*		Set Pin Direction for LEDs Pins				*/
	DIO_voidSetPinDirection(PORT_LED1,PIN_LED1, OUTPUT);
	DIO_voidSetPinDirection(PORT_LED2,PIN_LED2, OUTPUT);
	
    while (1) 
    {
		Command = 0;	
		LCD_Clear();
	    LCD_WriteSTring("Waiting...");
		
		Command = SPI_Receive ();
		LCD_Clear();
		LCD_WriteSTring("Received");
		_delay_ms(500);
		
		switch(Command)
		{
			case 'a' :
			Toggle_Led1();
			break;
			
			case 'b' :
			Toggle_Led2();
			break;
			
			default:
			LCD_Clear();
			LCD_WriteSTring("Wrong Command - ");
			LCD_WriteChar4(Command);
			_delay_ms(1000);
			break;
		}
		
    }
}




