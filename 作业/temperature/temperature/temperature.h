#pragma once

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

int temperature = 0;

int time = 0;
int time1, time2, time3, time4;

int terminal_flag = 0;

unsigned char dis_time[4];

//����ߧܧ�ڧ� �էڧ��ݧ֧�
void Initialize_LCD();
void Set_LCD_POS(INT8U x, INT8U y);
void write_LCD_Data(INT8U dat);
void LC_ShowString(INT8U x, INT8U y, char* str);
void Disp_Temperature();

//����ߧܧ�ڧ� �էѧ��ڧܧ� ��֧ާ�֧�ѧ����
void Read_Temperature();
void Temperature_Convert();
char Current_Temp_Display_Buffer[];
