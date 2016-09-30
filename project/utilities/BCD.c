/*
модуль BCD преобразования
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "BCD.h"

/*
конвертация двоичного значения в упакованное двоично-десятичное (3 байта на 6 цифр)
*/
void IntToBCD_6dig(long val, char* buf)
{
	unsigned char pos[6];
	if((val > 999999) || (val < 0)){
		return;
	}
	pos[0]=val/100000;
	val=val-pos[0]*100000;
	pos[1]=val/10000;
	val=val-pos[1]*10000;
	pos[2]=val/1000;
	val=val-pos[2]*1000;
	pos[3]=val/100;
	val=val-pos[3]*100;
	pos[4]=val/10;
	val=val-pos[4]*10;
	pos[5]=val;
	pos[0]=pos[0]*16+pos[1];
	pos[1]=pos[2]*16+pos[3];
	pos[2]=pos[4]*16+pos[5];
	memcpy(buf, (char*)pos, (size_t)3);
}

/*
конвертация двоичного значения в упакованное двоично-десятичное (2 байта на 4 цифр)
*/
void IntToBCD_4dig(short val, char* buf)
{
	unsigned char pos[4];
	if((val > 9999) || (val < 0)){
		return;
	}
	pos[0]=val/1000;
	val=val-pos[0]*1000;
	pos[1]=val/100;
	val=val-pos[1]*100;
	pos[2]=val/10;
	val=val-pos[2]*10;
	pos[3]=val;
	pos[0]=pos[0]*16+pos[1];
	pos[1]=pos[2]*16+pos[3];
	memcpy(buf, (char*)pos, (size_t)2);
}

// конвертируем параметр byte (2 BCD цифры) в значение параметра iResult (?)
// если входное значение не корректное то возвращается -1
// при успехе возвращается 0
int BCDToInt_2dig(char val, char* result)
{
	if(((val & 0x0F) > 9) || ((val & 0xF0) > 0x90)){
		return (-1);
	}
	*result = (val >> 4)*10 + (val & 0x0F);
	return(0);
}
