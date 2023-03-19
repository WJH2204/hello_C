#include "temperature.h"

//-----------------------------------------------------------------
// ���ѧ��ڧ� ��֧ާ�֧�ѧ���� DS18B20
//-----------------------------------------------------------------

//�����֧է֧ݧ֧ߧڧ� �ܧ�ߧ�ѧܧ��� DS18B20
#define DQ PB3

//���ѧ����ۧܧ� �ߧѧ��ѧӧݧ֧ߧڧ� �էѧߧߧ��
#define DQ_DDR_0()    DDRB &= ~_BV(DQ)
#define DQ_DDR_1()    DDRB |=  _BV(DQ)

//�����֧է֧ݧ֧ߧڧ� ��ѧҧ��� �ܧ�ߧ�ѧܧ��� ����ҧܧ� ��֧ާ�֧�ѧ����
#define DQ_1()        PORTB |=  _BV(DQ)
#define DQ_0()        PORTB &= ~_BV(DQ)
#define RD_DQ_VAL()  (PINB  &   _BV(DQ))

//���ѧҧݧڧ�� �է֧���ڧ�ߧ�� �٧ߧѧܧ�� �էݧ� ��֧ާ�֧�ѧ����
const INT8U df_Table[] = { 0,1,1,2,3,3,4,4,5,6,6,7,8,8,9,9 };

//���֧ݧѧ� ��ѧ��� ���ڧ�ѧߧߧ�� ��֧ާ�֧�ѧ����
INT8U CurrentT = 0;
//���ߧѧ�֧ߧڧ� ��֧ާ�֧�ѧ����, ���ڧ�ѧߧߧ��  �� �էѧ��ڧܧ�
INT8U Temp_Value[] = { 0x00,0x00 };
//�����ҧ�ѧاѧ֧ާ�� ��ڧ��� ��֧ާ�֧�ѧ����
INT8U Display_Digit[] = { 0,0,0,0 };
//���ݧѧ� �������ߧڧ� �էѧ��ڧܧ�
INT8U DS18B20_ERROR = 0;
//�����֧� �էݧ� ����ҧ�ѧا֧ߧڧ� ��֧ܧ��֧� ��֧ާ�֧�ѧ����
char Current_Temp_Display_Buffer[] = { "T:              " };

// ���ߧڧ�ڧѧݧڧ٧ѧ�ڧ� DS18B20 
INT8U Init_DS18B20()
{
	INT8U status;
	DQ_DDR_1(); DQ_0();		_delay_us(500);
	DQ_DDR_0();		_delay_us(50);
	status = RD_DQ_VAL();		_delay_us(500);
	DQ_1();
	return status;
}

// ������ڧ�ѧ�� �ҧѧۧ�
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

// ���ѧ�ڧ�ѧ�� �ҧѧۧ�
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

// ����֧ߧڧ� ��֧ާ�֧�ѧ����
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

// ����֧�ҧ�ѧ٧�ӧѧߧڧ� �٧ߧѧ�֧ߧڧ� ��֧ާ�֧�ѧ����
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
