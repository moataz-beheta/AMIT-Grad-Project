#ifndef			MAIN_INTERFACE_H
#define			MAIN_INTERFACE_H

#define	RX	PORTD,	PIN0
#define	TX	PORTD,	PIN1	

#define MOSI	PORTB, PIN5
#define MISO	PORTB, PIN6
#define SCK		PORTB, PIN7
#define SS		PORTB, PIN4

#define	PORT_LED1	PORTC_REG
#define	PIN_LED1	PIN3
#define	PORT_LED2	PORTD_REG
#define	PIN_LED2	PIN3


void	Toggle_Led1		(void);
void	Toggle_Led2		(void);

#endif