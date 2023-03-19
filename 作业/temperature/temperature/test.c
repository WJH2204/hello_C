#include "temperature.h"

//-----------------------------------------------------------------
// Главная функция
//-----------------------------------------------------------------
int main()
{
	//端口设置
	DDRA = 0XFF; //将端口设置为输出
	DDRB = 0x00; PORTB = 0x00; //将端口设置为输入，所有端口为低
	DDRC = 0xFF; //输出
	DDRD = 0xFF; //输出
	//初始化LCD
	Initialize_LCD();
	//Вывести две строки информации
	LCD_ShowString(0, 0, "DS18B20 TEST PRG");
	LCD_ShowString(0, 1, "Wait...	");
	//Считывать температуру
	Read_Temperature();
	_delay_ms(1000);
	//Очистить вторую строку
	LCD_ShowString(0, 1, "			");
	while (1)
	{
		//Считывать температуру
		Read_Temperature();
		if (!DS18B20_ERROR)
		{
			//Преобразование формата температуры
			Temperature_Convert();
			//Показ температуры на дисплей
			Disp_Temperature();
			_delay_ms(100);
		}

		if (temperature > 310 && temperature < 330)
		{

			if (time < 10)
			{
				PORTA = _BV(PA1);
				LCD_ShowString(0, 1, "OVERHEAT        ");
				_delay_ms(10);
				terminal_flag++;
				if (terminal_flag > 8)
				{
					terminal_flag = 0;
					time++;
				}

				time1 = time / 1000;
				time2 = time % 1000 / 100;
				time3 = time % 100 / 10;
				time4 = time % 10;

				dis_time[0] = time1 + '0';
				dis_time[1] = time2 + '0';
				dis_time[2] = time3 + '0';
				dis_time[3] = time4 + '0';
				LCD_ShowString(10, 1, dis_time);
			}
			else
			{
				PORTA = _BV(PA0);
				LCD_ShowString(0, 1, "EMERGENTCY STOP ");
			}
		}

		if (temperature < 300)
		{
			PORTA = _BV(PA1);
			LCD_ShowString(0, 1, "Operating      ");
			terminal_flag = 0;
			time = 0;
		}
		if (temperature == 350)
		{
			PORTA = _BV(PA1);
			LCD_ShowString(0, 1, "CRITICAL        ");
			terminal_flag = 0;
			time = 0;
		}
		if (temperature > 350)
		{
			PORTA = _BV(PA0);
			LCD_ShowString(0, 1, "EMERGENTCY STOP ");
			terminal_flag = 0;
			time = 0;
		}
	}
}