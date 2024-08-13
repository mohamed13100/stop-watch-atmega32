/*
 * PB.h
 *
 * Created: 4/7/2023 1:26:31 PM
 *  Author: mohamed
 */ 


#ifndef PB_H_
#define PB_H_
#include "STD_TYPES.h"

void button_vInit(u8 portname ,u8 pinnumber);
 u8 button_read(u8 portname ,u8 pinnumber);




#endif /* PB_H_ */