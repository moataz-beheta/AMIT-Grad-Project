#ifndef			USART_CONFIGURATION_H
#define			USART_CONFIGURATION_H



#define		Mode	 					Asynchronous	//Choose Asynchronous or Synchronous
#define		PARITY	 					NO_Pairty		//ODD or EVEN or NO_Pairty
#define		Direction 					F_DUPLEX		//F_DUPLEX or H_DUPLEX
#define		SPEED 						NORMAL			//NORMAL or DOUBLE
#define		STOP_BIT	 				1				//Number of Stop Bits, 1 or 2
#define		Rate						BIT				//BIT or BYTE or SYMBOLS or FRAMES
#define		Num_of_Bits					8				//5 or 6 or 7 or 8 or 9
#define		Clock_Polarity				RISING			//RISING or FALLING
#define		BAUD_RATE					9600			//Enter the desired baud rate
#define		F_CPU						8000000UL		//Enter the Crystal Oscillator 

#endif