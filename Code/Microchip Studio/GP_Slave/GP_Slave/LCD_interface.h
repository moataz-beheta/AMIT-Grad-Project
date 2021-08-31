#ifndef			LCD_INTERFACE_H
#define			LCD_INTERFACE_H

#define		CONTROL_PORT    PORTB
#define		LCD_RS			PIN1
#define		LCD_RW			PIN2
#define		LCD_EN			PIN3

#define		DATA_PORT		PORTA

void	LCD_init(void);
void	LCD_WriteChar(u8 Data);
void	LCD_CMD(u8 CMD);
void    LCD_SendCMD4(u8 cmd);
void    LCD_WriteChar4(u8 Data);
void    LCD_GOTOXY(u8 LINE_NUM,u8 POSITION);
void    LCD_WriteSTring(u8 * ptr);
void	LCD_Clear(void);

#endif