#include "temperature.h"

//-----------------------------------------------------------------
// �����ѧӧݧ֧ߧڧ� �էڧ��ݧ֧� �� �ѧݧԧ��ڧ�� ���ܧѧ٧�.
//-----------------------------------------------------------------

// ����ܧѧ٧ѧ�� �ڧߧ���ާѧ�ڧ� �� ��֧ާ�֧�ѧ����
void Disp_Temperature()
{
	LCD_ShowString(0, 0, Current_Temp_Display_Buffer);
	Set_LCD_POS(7, 0);
	Write_LCD_Data(0xDF);

	Set_LCD_POS(8, 0);
	Write_LCD_Data('C');
}

//�����֧է֧ݧ֧ߧڧ� �ܧ�ߧ�ѧܧ��� ����ѧӧݧ֧ߧڧ� LCD-�էڧ��ݧ֧�
#define RS_1() PORTD |=  (1<<PD0)
#define RS_0() PORTD &= ~(1<<PD0)
#define RW_1() PORTD |=  (1<<PD1)
#define RW_0() PORTD &= ~(1<<PD1)
#define EN_1() PORTD |=  (1<<PD2)
#define EN_0() PORTD &= ~(1<<PD2)

//�����֧է֧ݧ֧ߧڧ� ������ LCD-�էڧ��ݧ֧�
#define LCD_PORT  PORTC                     //������ �էݧ� �����ѧӧܧ� �էѧߧߧ�� LCD-�էڧ��ݧ֧�
#define LCD_PIN   PINC                      //������ �էݧ� ���ڧ֧ާ� �էѧߧߧ�� LCD-�էڧ��ݧ֧�
#define LCD_DDR   DDRC                      //����ڧ֧ߧ�ѧ�ڧ� ������ LCD-�էڧ��ݧ֧�

// ����ߧܧ�ڧ� ��اڧէѧߧڧ�
void LCD_BUSY_WAIT()
{

	RS_0(); // PD0 low
	RW_1();	// PD1 high ���֧ԧڧ���� �էݧ� ���֧ߧڧ� �������ߧڧ�
	LCD_DDR = 0x00;	//�����ѧߧ�ӧڧ�� ����� �ܧѧ� �ӧ���
	EN_1(); // PD2 high
	_delay_us(10);
	loop_until_bit_is_clear(LCD_PIN, 7); //LCD-�էڧ��ݧ֧� �� ��اڧէѧߧڧ�, ���ܧ� ���ѧ��ڧ� �ҧڧ� PIN LCD-�էڧ��ݧ֧� �ߧ� ���ѧߧ֧� ��ѧӧߧ�� 0.
	EN_0(); //PD2 low
	LCD_DDR = 0xFF;	//�������ѧߧ�ӧڧ�� ����� �ܧѧ� �ӧ����
}

// ���֧ԧڧ��� �էݧ� �٧ѧ�ڧ�� �ܧ�ާѧߧ� LCD
void Write_LCD_Command(INT8U cmd)
{
	LCD_BUSY_WAIT();
	RS_0();	RW_0();
	LCD_PORT = cmd;
	EN_1(); EN_0();
}

// ���֧ԧڧ��� �էݧ� �٧ѧ�ڧ�� �էѧߧߧ�� LCD
void Write_LCD_Data(INT8U dat)
{
	LCD_BUSY_WAIT();
	RS_1(); RW_0();
	LCD_PORT = dat;
	EN_1(); EN_0();		
}

// ���ѧ�ڧ�� ���ݧ�٧�ӧѧ�֧ݧ��ܧڧ� ��ڧާӧ�ݧ�� �� CGRAM
void Write_NEW_LCD_Char()
{
	INT8U i;
	const INT8U Temperature_Char[8] = { 0x06 , 0x09 ,0x09 , 0x06 , 0x00 , 0x00 ,0x00 ,0x00 };
	Write_LCD_Command(0x40);
	for (i = 0; i < 8; i++)
		Write_LCD_Data(Temperature_Char[i]);
}

// ���ߧڧ�ڧѧݧڧ٧ѧ�ڧ� LCD-�էڧ��ݧ֧�
void Initialize_LCD()
{
	Write_LCD_Command(0x38); _delay_ms(15);
	Write_LCD_Command(0x01); _delay_ms(15);
	Write_LCD_Command(0x06); _delay_ms(15);
	Write_LCD_Command(0x0C); _delay_ms(15);
	Write_NEW_LCD_Char();
}

// ���ѧ����ۧܧ� ���٧ڧ�ڧ� ����ҧ�ѧا֧ߧڧ�
void Set_LCD_POS(INT8U x, INT8U y)
{
	if (y == 0)
		Write_LCD_Command(0x80 | x);
	else if (y == 1)
		Write_LCD_Command(0xC0 | x);
}

// �����ҧ�ѧا֧ߧڧ� �����ܧ�
void LCD_ShowString(INT8U x, INT8U y, char* str)
{
	INT8U i = 0;
	Set_LCD_POS(x, y);
	for (i = 0; i < 16 && str[i] != '\0'; i++)
	{
		Write_LCD_Data(str[i]);
	}
}
