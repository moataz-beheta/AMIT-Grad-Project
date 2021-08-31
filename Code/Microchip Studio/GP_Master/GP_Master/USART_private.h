//#define regs
#ifndef			USART_PRIVATE_H	//3ashan maya3mlsh #include 2aktr min mara ll USART_private.h
#define			USART_PRIVATE_H

// efta7 el datasheet w roo7 3ala Register summary w dawar 3ala el registers beta3t el USART

#define		UDR_REG				*((volatile u8 *)0x2C)
#define		UCSRA_REG			*((volatile u8 *)0x2B)
#define		UCSRB_REG			*((volatile u8 *)0x2A)
#define		UCSRC_REG			*((volatile u8 *)0x40) // SAME ADDRESS FOR UBRRH_REG
#define		UBRRH_REG			*((volatile u8 *)0x40) // SAME ADDRESS FOR UBRRH_REG
#define		UBRRL_REG			*((volatile u8 *)0x29)


#endif
// '*' 3ashan ana ma7tag el mo7tawa elly fih mish el address beta3ah
//'(u8*)' hena ba3mel casting ll pointer 3ashan 2afahimoh eno hayshawer 3ala char (8bit)
//volatile : 3ashan maya3mlhash optimization w maya3mlhash cashing
//cashing: be7otha bel initial value beta3itha( elly heya b zero)  fi el GPRs w mish hatt5ayar, hay3mil keda la2ino basta5dmha ketir to save time