/*
 * CFile1.c
 *
 * Created: 4/14/2023 4:40:10 PM
 *  Author: mohamed
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>

#include "STD_TYPES.h"
#include "std_macros.h"
#include "DIO.h"
#include "SSD.h"


void seven_seg_vinit(u8 port_name)
{
	DIO_set_port_direction(port_name,0xFF);
}

void seven_seg_write(u8 portname,u8 number) //coman cathode 
{  
	#if defined CC  //coman cathode 
	u8 arr[]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
		
	#elif defined CA	 //comman anode
	u8 arr[]={ ~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x6f};
		
    #endif
	DIO_write_port(portname,arr[number]);
}
void seven_seg_init_BCD(unsigned char portname)
{
	DIO_vsetPINDir(portname,0,1);
	DIO_vsetPINDir(portname,1,1);
	DIO_vsetPINDir(portname,2,1);
	DIO_vsetPINDir(portname,3,1);
}
void seven_seg_write_BCD(unsigned char portname,unsigned char value)
{
	
	write_low_nibble(portname,value);
}

unsigned short segment(unsigned short x)
{
	unsigned short y=0;
	switch(x)
	{
		case 0: y = 0b00111111;break;
		case 1: y = 0b00000110;break;
		case 2: y = 0b01011011;break;
		case 3: y = 0b01001111;break;
		case 4: y = 0b01100110;break;
		case 5: y = 0b01101101;break;
		case 6: y = 0b01111101;break;
		case 7: y = 0b00000111;break;
		case 8: y = 0b01111111;break;
		case 9: y = 0b01101111;break;
		default: break;
	}
	return y;
}

void displaySegment(void)
{
	unsigned short i=0;
	unsigned short SEC=56;
	unsigned short mint=0;
	PORTC = 0;//DATA
	PORTD = 0b11111111;//SELECT
	PORTD &= ~(1<<1);  //SELECT DIGIT
	PORTC = segment(i % 10);//SHOW DATA ONES
	_delay_us(100);
	
	PORTC = 0;
	PORTD = 255;
	PORTD &= ~(1<<0);// PIN PORTB.0 RB0
	PORTC = segment(i / 10);// SHOW TENS
	_delay_us(100);    // 1 millisecond delay
	
	// SEC
	PORTC = 0;//DATA
	PORTD = 0b11111111;//SELECT
	PORTD &= ~(1<<3);  //SELECT DIGIT
	PORTC = segment(SEC % 10);//SHOW DATA ONES
	_delay_us(100);
	
	PORTC = 0;
	PORTD = 255;
	PORTD &= ~(1<<2);// PIN PORTB.0 RB0
	PORTC = segment(SEC / 10);// SHOW TENS
	_delay_us(100);    // 1 millisecond delay
	
	// min
	PORTC = 0;//DATA
	PORTD = 0b11111111;//SELECT
	PORTD &= ~(1<<5);  //SELECT DIGIT
	PORTC = segment(mint % 10);//SHOW DATA ONES
	_delay_us(100);
	
	PORTC = 0;
	PORTD = 255;
	PORTD &= ~(1<<4);// PIN PORTB.0 RB0
	PORTC = segment(mint / 10);// SHOW TENS
	_delay_us(100);    // 1 millisecond delay
	
}