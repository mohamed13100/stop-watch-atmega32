/*
 * stop_watch.c
 *
 * Created: 8/27/2023 3:13:00 PM
 * Author : mohamed
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>  
#include "STD_TYPES.h"
#include "std_macros.h"
#include "DIO.h"
#include "SSD.h"
#include "PB.h"
#include "ADC_driver.h"
#include "led.h"
#include "help.h"
#include "timer.h"
#define  RESET_STATE  1
#define  STOP_TIME    2
#define  HOUR_PLUSE   3
u8 Digit=0;
u8 volatile flag=0 ;
u8 volatile counter =0;
u8 volatile flag_2=0;
u8 volatile flag_3=0;
u16 volatile tim_flag=0;
u8 button_state = 1;
 u8 button_check=0;
 u8  sec=0 ;
 u8 min= 0;
 u8 Mili_sec =0 ;
 u8 hour =0 ;
int main(void)
{
    /* Replace with your application code */
	sei();
	SET_BIT(GICR,INT2);
	SET_BIT(GICR,INT1);
	SET_BIT(GICR,INT0);
	SET_BIT(MCUCR,ISC2);
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	SET_BIT(MCUCR,ISC11);
	SET_BIT(MCUCR,ISC10);
	timer_CTC_init_interrupt();
	button_vInit('A',PINA0);
	button_vInit('A',PINA1);
	button_vInit('A',PINA2);
	button_vInit('A',PINA3);
	button_vInit('b',PINB5);
	 button_check=button_read('b',PINB5);
	LED_vInit('B',0);
	seven_seg_vinit('C');
	
	
    u8 button_1;
	DIO_vsetPINDir('D',PIND5,OUTPUT);
	DIO_vsetPINDir('D',PIND4,OUTPUT);
	DIO_vsetPINDir('D',PIND3,INPUT);
	DIO_vsetPINDir('D',PIND2,INPUT);
	DIO_vsetPINDir('D',PIND1,OUTPUT);
	DIO_vsetPINDir('D',PIND0,OUTPUT);
	button_1 = button_read('a',0);
	

    while (1) 
    { 
		u8 i=0 ;
		
		switch(button_state)
		{
			case RESET_STATE:
			if(flag==1)
			{
			
				for (i=0 ;i<=6 ;i++)
				{
					
					DIO_write('d',PIND6,HIGH);
					seven_seg_write('c',0);
				}
				_delay_ms(10);
				 sec=0 ;
				 min= 0;
				 Mili_sec =0;
				flag=0;	
				
				_delay_ms(10);
				//counter=1;		
					
			}
			button_state=2;
			
			break;
			case STOP_TIME:
			if ( flag_2==1)
			{
				//_delay_ms(100);
			//min++;
			}
			//flag_2=0;
			button_state=3;
				
			break;
			case HOUR_PLUSE :
			if (flag_3==1)
			{
				hour++;
				_delay_ms(10);
			}
			flag_3=0;
			button_state=1;
			
			break;
			
			
			
			break;
		}
			
			
			
		switch (Digit)
		{
		case 0:
			DIO_write('A',PINA0,LOW);
			//DIO_write('D',PIND4,LOW);
			seven_seg_write('C',0);
			DIO_write('A',PINA5,HIGH);
			Digit=1;
			seven_seg_write('C',sec % 10);
			break;
		
		case 1:
			DIO_write('A',PINA5,LOW);
			seven_seg_write('C',0);
			DIO_write('A',PINA4,HIGH);
			Digit=2;
			seven_seg_write('C',sec / 10);
			break;
		case 2:
			DIO_write('A',PINA4,LOW);
			seven_seg_write('C',0);
			DIO_write('A',PINA3,HIGH);
			Digit=3;
			seven_seg_write('C',min % 10);
			break;
		case 3:
			DIO_write('A',PINA3,LOW);
			seven_seg_write('C',0);
			DIO_write('A',PINA2,HIGH);
			Digit=4;
			seven_seg_write('C',min / 10);
			break;
			case 4:
			DIO_write('A',PINA2,LOW);
			seven_seg_write('C',0);
			DIO_write('A',PINA1,HIGH);
			Digit=5;
			seven_seg_write('C',hour % 10);
			break;
			case 5:
			DIO_write('A',PINA1,LOW);
			seven_seg_write('C',0);
			DIO_write('A',PINA0,HIGH);
			Digit=0;
			seven_seg_write('C',hour / 10);
			break;
		 }
		Mili_sec++;
		if (Mili_sec==100)
		{
			if(flag_2 == 0)
			sec++;
		Mili_sec=0;
			if (sec==60)
				{
					if(flag_2 == 0)
					{min++;sec=0;}
					if (min==60)
					{
						if(flag_2 == 0)
						{min =0;
						hour++;}
						if (hour==60)
						{
							hour=0;
						}
						
					}
				}
				
				}
				_delay_ms(1);
				
		}
				
		
		
}


ISR(INT2_vect)
{
	if (counter==0)
	{
			flag=1;
	}
	
	

}

ISR(INT0_vect)
{
	if(flag_2 == 0)
	flag_2 = 1;
	else
	flag_2 = 0;
}

ISR(INT1_vect)
{
	flag_3=1;
}
ISR(TIMER0_COMP_vect)
{
	if(flag_2==1)
	{
		tim_flag++;
	}
	
	
		
	
	
}



