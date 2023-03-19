#include "temperature.h"

//-----------------------------------------------------------------
// §µ§á§â§Ñ§Ó§Ý§Ö§ß§Ú§Ö §Õ§Ú§ã§á§Ý§Ö§ñ §Ú §Ñ§Ý§Ô§à§â§Ú§ä§Þ §á§à§Ü§Ñ§Ù§Ñ.
//-----------------------------------------------------------------

// §±§à§Ü§Ñ§Ù§Ñ§ä§î §Ú§ß§æ§à§â§Þ§Ñ§è§Ú§ð §à §ä§Ö§Þ§á§Ö§â§Ñ§ä§å§â§Ö
void Disp_Temperature()
{
	LCD_ShowString(0, 0, Current_Temp_Display_Buffer);
	Set_LCD_POS(7, 0);
	Write_LCD_Data(0xDF);

	Set_LCD_POS(8, 0);
	Write_LCD_Data('C');
}

//§°§á§â§Ö§Õ§Ö§Ý§Ö§ß§Ú§Ö §Ü§à§ß§ä§Ñ§Ü§ä§à§Ó §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§ñ LCD-§Õ§Ú§ã§á§Ý§Ö§ñ
#define RS_1() PORTD |=  (1<<PD0)
#define RS_0() PORTD &= ~(1<<PD0)
#define RW_1() PORTD |=  (1<<PD1)
#define RW_0() PORTD &= ~(1<<PD1)
#define EN_1() PORTD |=  (1<<PD2)
#define EN_0() PORTD &= ~(1<<PD2)

//§°§á§â§Ö§Õ§Ö§Ý§Ö§ß§Ú§Ö §á§à§â§ä§Ñ LCD-§Õ§Ú§ã§á§Ý§Ö§ñ
#define LCD_PORT  PORTC                     //§±§à§â§ä §Õ§Ý§ñ §à§ä§á§â§Ñ§Ó§Ü§Ú §Õ§Ñ§ß§ß§í§ç LCD-§Õ§Ú§ã§á§Ý§Ö§ñ
#define LCD_PIN   PINC                      //§±§à§â§ä §Õ§Ý§ñ §á§â§Ú§Ö§Þ§Ñ §Õ§Ñ§ß§ß§í§ç LCD-§Õ§Ú§ã§á§Ý§Ö§ñ
#define LCD_DDR   DDRC                      //§°§â§Ú§Ö§ß§ä§Ñ§è§Ú§ñ §á§à§â§ä§Ñ LCD-§Õ§Ú§ã§á§Ý§Ö§ñ

// §¶§å§ß§Ü§è§Ú§ñ §à§Ø§Ú§Õ§Ñ§ß§Ú§ñ
void LCD_BUSY_WAIT()
{

	RS_0(); // PD0 low
	RW_1();	// PD1 high §²§Ö§Ô§Ú§ã§ä§â§Ñ §Õ§Ý§ñ §é§ä§Ö§ß§Ú§ñ §ã§à§ã§ä§à§ñ§ß§Ú§ñ
	LCD_DDR = 0x00;	//§µ§ã§ä§Ñ§ß§à§Ó§Ú§ä§î §á§à§â§ä §Ü§Ñ§Ü §Ó§ç§à§Õ
	EN_1(); // PD2 high
	_delay_us(10);
	loop_until_bit_is_clear(LCD_PIN, 7); //LCD-§Õ§Ú§ã§á§Ý§Ö§Û §Ó §à§Ø§Ú§Õ§Ñ§ß§Ú§Ú, §á§à§Ü§Ñ §ã§ä§Ñ§â§ê§Ú§Û §Ò§Ú§ä PIN LCD-§Õ§Ú§ã§á§Ý§Ö§ñ §ß§Ö §ã§ä§Ñ§ß§Ö§ä §â§Ñ§Ó§ß§í§Þ 0.
	EN_0(); //PD2 low
	LCD_DDR = 0xFF;	//§£§à§ã§ã§ä§Ñ§ß§à§Ó§Ú§ä§î §á§à§â§ä §Ü§Ñ§Ü §Ó§í§ç§à§Õ
}

// §²§Ö§Ô§Ú§ã§ä§â §Õ§Ý§ñ §Ù§Ñ§á§Ú§ã§Ú §Ü§à§Þ§Ñ§ß§Õ LCD
void Write_LCD_Command(INT8U cmd)
{
	LCD_BUSY_WAIT();
	RS_0();	RW_0();
	LCD_PORT = cmd;
	EN_1(); EN_0();
}

// §²§Ö§Ô§Ú§ã§ä§â §Õ§Ý§ñ §Ù§Ñ§á§Ú§ã§Ú §Õ§Ñ§ß§ß§í§ç LCD
void Write_LCD_Data(INT8U dat)
{
	LCD_BUSY_WAIT();
	RS_1(); RW_0();
	LCD_PORT = dat;
	EN_1(); EN_0();		
}

// §©§Ñ§á§Ú§ã§î §á§à§Ý§î§Ù§à§Ó§Ñ§ä§Ö§Ý§î§ã§Ü§Ú§ç §ã§Ú§Þ§Ó§à§Ý§à§Ó §Ó CGRAM
void Write_NEW_LCD_Char()
{
	INT8U i;
	const INT8U Temperature_Char[8] = { 0x06 , 0x09 ,0x09 , 0x06 , 0x00 , 0x00 ,0x00 ,0x00 };
	Write_LCD_Command(0x40);
	for (i = 0; i < 8; i++)
		Write_LCD_Data(Temperature_Char[i]);
}

// §ª§ß§Ú§è§Ú§Ñ§Ý§Ú§Ù§Ñ§è§Ú§ñ LCD-§Õ§Ú§ã§á§Ý§Ö§ñ
void Initialize_LCD()
{
	Write_LCD_Command(0x38); _delay_ms(15);
	Write_LCD_Command(0x01); _delay_ms(15);
	Write_LCD_Command(0x06); _delay_ms(15);
	Write_LCD_Command(0x0C); _delay_ms(15);
	Write_NEW_LCD_Char();
}

// §¯§Ñ§ã§ä§â§à§Û§Ü§Ú §á§à§Ù§Ú§è§Ú§Ú §à§ä§à§Ò§â§Ñ§Ø§Ö§ß§Ú§ñ
void Set_LCD_POS(INT8U x, INT8U y)
{
	if (y == 0)
		Write_LCD_Command(0x80 | x);
	else if (y == 1)
		Write_LCD_Command(0xC0 | x);
}

// §°§ä§à§Ò§â§Ñ§Ø§Ö§ß§Ú§Ö §ã§ä§â§à§Ü§Ñ
void LCD_ShowString(INT8U x, INT8U y, char* str)
{
	INT8U i = 0;
	Set_LCD_POS(x, y);
	for (i = 0; i < 16 && str[i] != '\0'; i++)
	{
		Write_LCD_Data(str[i]);
	}
}
