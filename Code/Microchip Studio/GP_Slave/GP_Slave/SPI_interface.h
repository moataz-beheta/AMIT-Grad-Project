#ifndef		SPI_INTERFACE_H
#define		SPI_INTERFACE_H

void 	SPI_Master_init				(void);
void 	SPI_Slave_init				(void);
void 	SPI_Clock_Data_Setting		(void);
void 	SPI_Interrupt_Enable		(void);

u8 		SPI_Receive 				(void);
void	SPI_Transmit 				(u8 data);

#endif