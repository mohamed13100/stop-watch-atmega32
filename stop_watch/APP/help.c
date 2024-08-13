/*
 * CFile1.c
 *
 * Created: 8/31/2023 2:19:40 AM
 *  Author: mohamed
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "std_macros.h"
#include "DIO.h"
#include "SSD.h"
#include "PB.h"
#include "ADC_driver.h"
#include "led.h"
void stopwatch_start(void)
{
	u8 Digit=0;
	u8  sec=0 ;
	u8 min= 0;
	u8 Mili_sec =0 ;
	u8 hour =0 ;
	u8 button_1;
	switch (Digit)
	{
		case 0:
		DIO_write('D',PIND0,LOW);
		//DIO_write('D',PIND4,LOW);
		seven_seg_write('C',0);
		DIO_write('D',PIND5,HIGH);
		Digit=1;
		seven_seg_write('C',sec % 10);
		break;
		
		case 1:
		DIO_write('D',PIND5,LOW);
		seven_seg_write('C',0);
		DIO_write('D',PIND4,HIGH);
		Digit=2;
		seven_seg_write('C',sec / 10);
		break;
		case 2:
		DIO_write('D',PIND4,LOW);
		seven_seg_write('C',0);
		DIO_write('D',PIND3,HIGH);
		Digit=3;
		seven_seg_write('C',min % 10);
		break;
		case 3:
		DIO_write('D',PIND3,LOW);
		seven_seg_write('C',0);
		DIO_write('D',PIND2,HIGH);
		Digit=4;
		seven_seg_write('C',min / 10);
		break;
		case 4:
		DIO_write('D',PIND2,LOW);
		seven_seg_write('C',0);
		DIO_write('D',PIND1,HIGH);
		Digit=5;
		seven_seg_write('C',hour % 10);
		break;
		case 5:
		DIO_write('D',PIND1,LOW);
		seven_seg_write('C',0);
		DIO_write('D',PIND0,HIGH);
		Digit=0;
		seven_seg_write('C',hour / 10);
		break;
	}
	Mili_sec++;
	if (Mili_sec==100)
	{
		sec++;
		Mili_sec=0;
		if (sec==60)
		{min++;sec=0;
			if (min==60)
			{
				min =0;
				hour++;
				if (hour==60)
				{
					hour=0;
				}
				
			}
		}
		
	}
	_delay_ms(1);
	
	
	
}

