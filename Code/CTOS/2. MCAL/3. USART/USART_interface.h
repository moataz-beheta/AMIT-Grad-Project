//fn prototypes + #define
//habi3 eih ll user, dah elly batala3o ll user

#ifndef			USART_INTERFACE_H
#define			USART_INTERFACE_H

void	USART_INIT (void);
void	USART_SEND_BYTE (u8 data);
u8		USART_RECEIVE_BYTE (void);

#endif