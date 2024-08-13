/*
 * IncFile1.h
 *
 * Created: 4/5/2023 11:34:49 AM
 *  Author: mohamed
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_


/*
	Function Name        : LED_vInit
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Initialize the pin as an output pin to connect the led.
*/
void LED_vInit(unsigned char portname,unsigned char pinnumber);

/*
	Function Name        : LED_vTurnOn
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Turn on the led connected to the given pin and port.
*/
void LED_vTurnOn(unsigned char portname,unsigned char pinnumber);

/*
	Function Name        : LED_vTurnOff
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Turn off the led connected to the given pin and port.
*/
void LED_vTurnOff(unsigned char portname,unsigned char pinnumber);

/*
	Function Name        : LED_vToggle
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Toggle the led connected to the given pin and port.
*/
void LED_vToggle(unsigned char portname,unsigned char pinnumber);






#endif /* INCFILE1_H_ */