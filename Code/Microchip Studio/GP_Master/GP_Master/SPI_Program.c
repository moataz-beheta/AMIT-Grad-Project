#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_configuration.h"

void 	SPI_Master_init			(void)
{
	/* SPI Enable */
	SET_BIT(SPCR,6);
	
	/* SPI Master */
	SET_BIT(SPCR,4);
}

void 	SPI_Slave_init			(void)
{
	/* SPI Enable */
	SET_BIT(SPCR,6);
	
	/* SPI Slave */
	CLR_BIT(SPCR,4);
}

void 	SPI_Clock_Data_Setting		(void)
{
	/* SPI Clock Rate */
	
	#if 	SPEED == Clock/4
	CLR_BIT(SPSR,0);	//SPI2X Pin
	CLR_BIT(SPCR,0);	//SPR0 Pin
	CLR_BIT(SPCR,1);	//SPR1 Pin
	
	#elif 	SPEED == Clock/16
	CLR_BIT(SPSR,0);	//SPI2X Pin
	SET_BIT(SPCR,0);	//SPR0 Pin
	CLR_BIT(SPCR,1);	//SPR1 Pin
	
	#elif 	SPEED == Clock/64
	CLR_BIT(SPSR,0);	//SPI2X Pin
	CLR_BIT(SPCR,0);	//SPR0 Pin
	SET_BIT(SPCR,1);	//SPR1 Pin
	
	#elif 	SPEED == Clock/128
	CLR_BIT(SPSR,0);	//SPI2X Pin
	SET_BIT(SPCR,0);	//SPR0 Pin
	SET_BIT(SPCR,1);	//SPR1 Pin
	
	#elif 	SPEED == Clock/2
	SET_BIT(SPSR,0);	//SPI2X Pin
	CLR_BIT(SPCR,0);	//SPR0 Pin
	CLR_BIT(SPCR,1);	//SPR1 Pin
	
	#elif 	SPEED == Clock/8
	SET_BIT(SPSR,0);	//SPI2X Pin
	SET_BIT(SPCR,0);	//SPR0 Pin
	CLR_BIT(SPCR,1);	//SPR1 Pin
	
	#elif 	SPEED == Clock/32
	SET_BIT(SPSR,0);	//SPI2X Pin
	CLR_BIT(SPCR,0);	//SPR0 Pin
	SET_BIT(SPCR,1);	//SPR1 Pin
	
	
	#else
	#error	"Wrong Choice of SPI Speed!"
	#endif
	
	/* Clock Phase */
	#if 	Clock_Phase == Sample_lead
	CLR_BIT(SPCR,2);
	
	#elif 	Clock_Phase == Setup_lead
	SET_BIT(SPCR,2);
	
	#else
	#error	"Wrong Choice of SPI Clock Phase!"
	#endif

	/* Clock Polarity */
	#if 	Clock_Polarity == Rising_lead
	CLR_BIT(SPCR,3);
	
	#elif 	Clock_Polarity == Falling_lead
	SET_BIT(SPCR,3);
	
	#else
	#error	"Wrong Choice of SPI Clock Polarity!"
	#endif

	/* Data Order */
	#if 	Data_Order == MSB_First
	CLR_BIT(SPCR,5);
	
	#elif 	Data_Order == LSB_First
	SET_BIT(SPCR,5);
	
	#else
	#error	"Wrong Choice of SPI Data Order!"
	#endif
	

}
void 	SPI_Interrupt_Enable	(void)
{
	/*	Set SREG		*/
	
	/*	SPI Interrupt	*/
	SET_BIT(SPCR,7);
}

void SPI_Transmit (u8 data)
{
	SPDR = data;
	while (GET_BIT(SPSR,7)==0);
}

u8 SPI_Receive (void)
{
	while (GET_BIT(SPSR,7)==0);
	return SPDR;
}