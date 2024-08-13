/*
 * SSD.h
 *
 * Created: 4/14/2023 4:40:41 PM
 *  Author: mohamed
 */ 


#ifndef SSD_H_
#define SSD_H_

#include "STD_TYPES.h"

#define CA   //COMAN ANODE

void seven_seg_vinit(u8 port_name);
void seven_seg_write(u8 portname,u8 number) ;

void seven_seg_init_BCD(u8 portname);
void seven_seg_write_BCD(u8 portname,u8 value);

unsigned short segment(unsigned short x);
void displaySegment(void);


#endif /* SSD_H_ */