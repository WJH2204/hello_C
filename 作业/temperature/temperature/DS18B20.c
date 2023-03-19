#include "temperature.h"

//-----------------------------------------------------------------
// §¥§Ñ§ä§é§Ú§Ü §ä§Ö§Þ§á§Ö§â§Ñ§ä§å§â§í DS18B20
//-----------------------------------------------------------------

//§°§á§â§Ö§Õ§Ö§Ý§Ö§ß§Ú§Ö §Ü§à§ß§ä§Ñ§Ü§ä§à§Ó DS18B20
#define DQ PB3

//§¯§Ñ§ã§ä§â§à§Û§Ü§Ñ §ß§Ñ§á§â§Ñ§Ó§Ý§Ö§ß§Ú§ñ §Õ§Ñ§ß§ß§í§ç
#define DQ_DDR_0()    DDRB &= ~_BV(DQ)
#define DQ_DDR_1()    DDRB |=  _BV(DQ)

//§°§á§â§Ö§Õ§Ö§Ý§Ö§ß§Ú§Ö §â§Ñ§Ò§à§ä§í §Ü§à§ß§ä§Ñ§Ü§ä§à§Ó §ä§â§å§Ò§Ü§Ú §ä§Ö§Þ§á§Ö§â§Ñ§ä§å§â§í
#define DQ_1()        PORTB |=  _BV(DQ)
#define DQ_0()        PORTB &= ~_BV(DQ)
#define RD_DQ_VAL()  (PINB  &   _BV(DQ))

//§´§Ñ§Ò§Ý§Ú§è§Ñ §Õ§Ö§ã§ñ§ä§Ú§é§ß§í§ç §Ù§ß§Ñ§Ü§à§Ó §Õ§Ý§ñ §ä§Ö§Þ§á§Ö§â§Ñ§ä§å§â§í
const INT8U df_Table[] = { 0,1,1,2,3,3,4,4,5,6,6,7,8,8,9,9 };

//§¸§Ö§Ý§Ñ§ñ §é§Ñ§ã§ä§î §ã§é§Ú§ä§Ñ§ß§ß§à§Û §ä§Ö§Þ§á§Ö§â§Ñ§ä§å§â§í
INT8U CurrentT = 0;
//§©§ß§Ñ§é§Ö§ß§Ú§Ö §ä§Ö§Þ§á§Ö§â§Ñ§ä§å§â§í, §ã§é§Ú§ä§Ñ§ß§ß§à§Ö  §ã §Õ§Ñ§ä§é§Ú§Ü§Ñ
INT8U Temp_Value[] = { 0x00,0x00 };
//§°§ä§à§Ò§â§Ñ§Ø§Ñ§Ö§Þ§í§Ö §è§Ú§æ§â§í §ä§Ö§Þ§á§Ö§â§Ñ§ä§å§â§í
INT8U Display_Digit[] = { 0,0,0,0 };
//§¶§Ý§Ñ§Ô §ã§à§ã§ä§à§ñ§ß§Ú§ñ §Õ§Ñ§ä§é§Ú§Ü§Ñ
INT8U DS18B20_ERROR = 0;
//§¢§å§æ§Ö§â §Õ§Ý§ñ §à§ä§à§Ò§â§Ñ§Ø§Ö§ß§Ú§ñ §ä§Ö§Ü§å§ë§Ö§Û §ä§Ö§Þ§á§Ö§â§Ñ§ä§å§â§í
char Current_Temp_Display_Buffer[] = { "T:              " };

// §ª§ß§Ú§è§Ú§Ñ§Ý§Ú§Ù§Ñ§è§Ú§ñ DS18B20 
INT8U Init_DS18B20()
{
	INT8U status;
	DQ_DDR_1(); DQ_0();		_delay_us(500);
	DQ_DDR_0();		_delay_us(50);
	status = RD_DQ_VAL();		_delay_us(500);
	DQ_1();
	return status;
}

// §±§â§à§é§Ú§ä§Ñ§ä§î §Ò§Ñ§Û§ä
INT8U ReadOneByte()
{
	INT8U i, dat = 0;
	for (i = 0; i < 8; i++)
	{
		DQ_DDR_1(); DQ_0();
		DQ_DDR_0();
		if (RD_DQ_VAL())   dat |= _BV(i);
		_delay_us(80);
	}
	return dat;
}

// §¯§Ñ§á§Ú§ã§Ñ§ä§î §Ò§Ñ§Û§ä
void WriteOneByte(INT8U dat)
{
	INT8U i;
	for (i = 0x01; i != 0x00; i <<= 1)
	{
		DQ_DDR_1(); DQ_0();
		if (dat & i) DQ_1(); else DQ_0();
		_delay_us(80);
		DQ_1();
	}
}

// §¹§ä§Ö§ß§Ú§Ö §ä§Ö§Þ§á§Ö§â§Ñ§ä§å§â§í
void Read_Temperature()
{


	if (Init_DS18B20() != 0x00)
		DS18B20_ERROR = 1;
	else
	{
		WriteOneByte(0xCC);
		WriteOneByte(0x44);
		Init_DS18B20();
		WriteOneByte(0xCC);
		WriteOneByte(0xBE);
		Temp_Value[0] = ReadOneByte();
		Temp_Value[1] = ReadOneByte();
		DS18B20_ERROR = 0;
	}
}

// §±§â§Ö§à§Ò§â§Ñ§Ù§à§Ó§Ñ§ß§Ú§Ö §Ù§ß§Ñ§é§Ö§ß§Ú§Û §ä§Ö§Þ§á§Ö§â§Ñ§ä§å§â§í
void Temperature_Convert()
{
	INT8U ng = 0;
	if ((Temp_Value[1] & 0xF0) == 0xF0)
	{
		Temp_Value[1] = ~Temp_Value[1];
		Temp_Value[0] = ~Temp_Value[0] + 1;
		if (Temp_Value[0] == 0x00) Temp_Value[1]++;
		ng = 1;
	}
	Display_Digit[0] = df_Table[Temp_Value[0] & 0x0F];
	CurrentT = (Temp_Value[0] >> 4) | (Temp_Value[1] << 4);
	Display_Digit[3] = CurrentT / 100;
	Display_Digit[2] = CurrentT % 100 / 10;
	Display_Digit[1] = CurrentT % 10;
	Current_Temp_Display_Buffer[5] = Display_Digit[0] + '0';

	Current_Temp_Display_Buffer[4] = Display_Digit[1] + '0';
	Current_Temp_Display_Buffer[3] = Display_Digit[2] + '0';
	Current_Temp_Display_Buffer[2] = Display_Digit[3] + '0';

	if (Display_Digit[3] == 0)
		Current_Temp_Display_Buffer[2] = ' ';
	if (Display_Digit[2] == 0 && Display_Digit[3] == 0)
		Current_Temp_Display_Buffer[3] = ' ';
	if (ng)
	{
		if (Current_Temp_Display_Buffer[3] == ' ')
			Current_Temp_Display_Buffer[3] = '-';
		else
			if (Current_Temp_Display_Buffer[2] == ' ')
				Current_Temp_Display_Buffer[2] = '-';
			else
				Current_Temp_Display_Buffer[1] = '-';
	}

	if (ng == 0)
	{
		temperature = Display_Digit[3] * 1000 + Display_Digit[2] * 100 + Display_Digit[1] * 10 + Display_Digit[0] * 1;
	}

	if (ng == 1)
	{
		temperature = -(Display_Digit[3] * 1000 + Display_Digit[2] * 100 + Display_Digit[1] * 10 + Display_Digit[0] * 1);
	}
}
