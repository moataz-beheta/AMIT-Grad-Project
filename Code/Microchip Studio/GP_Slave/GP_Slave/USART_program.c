//program + fn def

#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"USART_interface.h"
#include	"USART_private.h"
#include	"USART_Configuration.h"

void	USART_INIT (void)
{
	u8	UBRR = 0;
	u8  Local_UCSRC=0;
	/* Enable transmitter and receiver */
	
	SET_BIT(UCSRB_REG,3);
	SET_BIT(UCSRB_REG,4);

	/* 	 Mode of Operation 		  				 */
	#if 		Mode == Asynchronous
	CLR_BIT(Local_UCSRC,6);
	#elif		Mode == Synchronous
	SET_BIT(Local_UCSRC,6);
	#else
		#error	"Wrong Choice of USART Mode of Operation!"
	#endif
	
	/* 	 Transmission Speed 		  				 */
	#if		Mode == Asynchronous
	#if		SPEED == NORMAL
	SET_BIT(UCSRA_REG,1);
	#elif	SPEED == DOUBLE
	CLR_BIT(UCSRA_REG,1);
	#endif
	
	#elif 	Mode == Synchronous
	CLR_BIT(UCSRA_REG,1);
	#else
		#error	"Wrong Choice of USART Transmission Speed!"
	#endif

	
	/* 	Baud Rate Equation		  				*/
	CLR_BIT(UBRRH_REG,15); // Select UBRRH Register
	#if 		Mode == Asynchronous
	#if			(SPEED == NORMAL)
	UBRR = ((F_CPU/(16*BAUD_RATE))-1);
	UBRRH_REG = (u8) (UBRR>>8);
	UBRRL_REG = (u8) UBRR;
	
	#elif		(SPEED == DOUBLE)
	UBRR = ((F_CPU/(8*BAUD_RATE))-1);
	UBRRH_REG = (u8)(UBRR>>8);
	UBRRL_REG = (u8)UBRR;
	#endif
	
	#elif 	mode == Synchronous
	UBRR = ((F_CPU/(2*BAUD_RATE))-1);
	UBRRH_REG = (u8) (UBRR>>8);
	UBRRL_REG = (u8) UBRR;
	#endif
	
	
	/* 	Send 8 bit Data Size  				 	*/
	#if 		Num_of_Bits == 5
	CLR_BIT(UCSRB_REG,2);
	CLR_BIT(Local_UCSRC, 1);
	CLR_BIT(Local_UCSRC, 2);
	#elif		Num_of_Bits == 6
	CLR_BIT(UCSRB_REG,2);
	SET_BIT(Local_UCSRC, 1);
	CLR_BIT(Local_UCSRC, 2);
	#elif		Num_of_Bits == 7
	CLR_BIT(UCSRB_REG,2);
	CLR_BIT(Local_UCSRC, 1);
	SET_BIT(Local_UCSRC, 2);
	#elif		Num_of_Bits == 8
	CLR_BIT(UCSRB_REG,2);
	SET_BIT(Local_UCSRC, 1);
	SET_BIT(Local_UCSRC, 2);
	#elif		Num_of_Bits == 9
	SET_BIT(UCSRB_REG,2);
	SET_BIT(Local_UCSRC, 1);
	SET_BIT(Local_UCSRC, 2);
	#else
		#error	"Wrong Choice of USART Data Size!"
	#endif
	

	/* 	Number of Stop Bits 		  				*/
	#if 		STOP_BIT == 1
	CLR_BIT(Local_UCSRC,3);
	#elif 	STOP_BIT == 2
	SET_BIT(Local_UCSRC,3);
	#else
		#error	"Wrong Choice of USART Stop Bits!"
	#endif
	
	/* 	Clock Polarity	   		  				 */
	#if 		MODE_OF_OPERATION == Synchronous
	#if(CLOCK_POLARITY == RISING)
	CLR_BIT(Local_UCSRC,0);
	#elif(CLOCK_POLARITY == FALLING)
	SET_BIT(Local_UCSRC,0);
	#endif
	
	#elif 	MODE_OF_OPERATION == Asynchronous
	CLR_BIT(Local_UCSRC,0);
	#else
		#error	"Wrong Choice of USART Clock Polarity!"
	#endif
	
	
	/*	Select and Assign UCSRC	Reg				*/
	SET_BIT(Local_UCSRC, 7);  					 
	UCSRC_REG = Local_UCSRC;
}
void	USART_SEND_BYTE (u8 data)
{
	while( GET_BIT(UCSRA_REG,5) == 0 );
	UDR_REG = data;

}
u8		USART_RECEIVE_BYTE (void)
{
	while( GET_BIT(UCSRA_REG , 7)  ==0 );
	
	return UDR_REG;
}