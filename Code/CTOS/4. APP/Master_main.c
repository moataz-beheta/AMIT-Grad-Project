/*
 * GP_Master.c
 *
 * Created: 8/29/2021 1:01:09 AM
 * Author : Moataz
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Dio_interface.h"
#include "main_interface.h"
#include "USART_interface.h"
#include "LCD_interface.h"
#include "SPI_interface.h"
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
	SPI_Master_init				();
	SPI_Clock_Data_Setting		();
	
	/*		Set Pin Direction for SPI Pins				*/
	DIO_voidSetPinDirection(MOSI, OUTPUT);
	DIO_voidSetPinDirection(MISO, INPUT);
	DIO_voidSetPinDirection(SCK, OUTPUT);
	DIO_voidSetPinDirection(SS, OUTPUT);
	DIO_voidSetPinValue(SS,HIGH);
	
    while (1) 
    {
		/*	Wait Command from Bluetooth Module	*/
		LCD_Clear();
		LCD_WriteSTring("Waiting...");
		_delay_ms(500);
		
		/*	Receive Command from Bluetooth Module via USART	*/
		Command = USART_RECEIVE_BYTE ();
		LCD_Clear();
		_delay_ms(500);
		LCD_WriteSTring("Command : ");
		LCD_WriteChar4(Command);
		_delay_ms(500);
		
		DIO_voidSetPinValue(SS,LOW);
		
		/*	Send Command to Slave via SPI	*/
		LCD_Clear();
		LCD_WriteSTring("Received ");
		SPI_Transmit(Command);
		
		LCD_Clear();
		LCD_WriteSTring("Sent");
		
		_delay_ms(500);
		
		/*	Interpret which action should be executed 	*/
		switch(Command)
		{
			/*	Toggle Led 1 	*/
			case 'a' :
			Toggle_Led1();
			break;
			
			/*	Toggle Led 2 	*/
			case 'b' :
			Toggle_Led2();
			break;
			
			/*	Any other received command 	*/
			default:
			LCD_Clear();
			LCD_WriteSTring("Wrong Command - ");
			LCD_WriteChar4(Command);
			_delay_ms(1000);
			break;
		}
    }
}
