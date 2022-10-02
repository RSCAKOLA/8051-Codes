
/*
	8051 Remote Controlled Robotic Arm
	Created by: Vidyasagar Academy, Akola
	Website: https://vsagar.og/
	Date: 28.03.2014
*/

#include <reg51.h>
#include "delay.c"

#define 

sbit A=P3^0; // receiver's outputs DCBA
sbit B=P3^1;
sbit C=P3^2;
sbit D=P3^3;

	int main()
	{
	P1=0x0F; // P1^3 to P1^0 are set as output pins connected to motors
	P2=0x0F; // jaw motor & arm motor connected to P2^3 to P2^0 (see below)
	P3=0x00; // PORT3 is set as input port, receiver's output is connected to P3^3 to P3^0 - DCBA

	while(1)
	{
	_delay_ms(5); 	 // perceptible pause for 
					 // starting up the receiver module

	// controlling signals for moving the robot trolley

	if((D==1)&(C==1)&(B==1)&(A==1)) // 0000	 b00001111
	{
		PORTB=0b00000000; // trolley stopped
		PORTD=0b00000000; // jaw and arm stopped
		_delay_ms(20); 
	}

	if((D==0)&(C==1)&(B==1)&(A==0)) // 1001
	{
		PORTB=0b00001001; // forward
		_delay_ms(20); 
	}

	if((D==1)&(C==0)&(B==0)&(A==1)) // 0110
	{
		PORTB=0b00000110; // backward
	}

	if((D==0)&(C==1)&(B==0)&(A==1))	// 1000
	{
		PORTB=0b00001000; // soft right
		_delay_ms(20); 
	}

	if((D==1)&(C==0)&(B==1)&(A==0))	// 0001
	{
		PORTB=0b00000001; // soft left
		_delay_ms(20); 
	}

	// Controlling signals for movement of robotic hand
	// Arm motor: P2^3(+) & P2^2(-)
	// Jaw motor: P2^1(+) & P2^0(-)

	if((D==0)&(C==1)&(B==1)&(A==1)) // 1000
	{
		PORTD=0b00000100; // arm moves upward
		_delay_ms(20); 
	}

	if((D==1)&(C==1)&(B==1)&(A==0)) // 0001
	{
		PORTD=0b00001000; // arm moves downward
		_delay_ms(20);
	}

	if((D==1)&(C==0)&(B==1)&(A==1))// 0100
	{
		PORTD=0b00000001; // jaw closes
		_delay_ms(20);
	}

	if((D==1)&(C==1)&(B==0)&(A==1)) // 0010
	{
		PORTD=0b00000010; // jaw opens
		_delay_ms(20);
	}

	} // while closed

	} // main closed
