/*
 * PB.c
 *
 * Created: 4/7/2023 1:26:10 PM
 *  Author: mohamed
 */
#include <util/delay.h> 
#include "STD_TYPES.h"
#include "DIO.h"

void button_vInit(u8 portname ,u8 pinnumber)
{
	DIO_vsetPINDir(portname ,pinnumber ,INPUT);
}
u8 button_read(u8 portname ,u8 pinnumber)
{
	u8 PB_READ=0 ;
	PB_READ=DIO_u8read(portname ,pinnumber);
	_delay_ms(10);
	return PB_READ ;
	
}