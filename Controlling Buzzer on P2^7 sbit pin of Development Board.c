



/* Code of forward and rverse chasing leds 

Created by: chaitanya Pande

	Date: 10.12.2016
*/

#include <reg51.h>
#include "delay.c"
#define LEDs P1
sbit bz=P2^7;

	int main() // main function

	{ // main function brace opened

	while(1) // infinite loop

	{ // while loop brace opened

	LEDs=0x01; 
	delay(1000);
	 

	LEDs=0x03;
  	delay(1000);		
	 

	LEDs=0x07; 
	delay(1000);
	 

	LEDs=0x0f;
  	delay(1000);		
	 

	LEDs=0x1f;
  	delay(1000);		
	 

	LEDs=0x3f;
  	delay(1000);	
	 

	LEDs=0x7f;
  	delay(1000);	
	 

	LEDs=0xff;
  	delay(1000);	
	 

	LEDs=0x00;
	delay(900);
	bz=0;	
	delay(100); 
	bz=1;
	
	
	LEDs=0x80;
  	delay(1000);
	
	
	LEDs=0xc0;
  	delay(1000);


  LEDs=0xe0;
  delay(1000);
	
	
	LEDs=0xf0;
  delay(1000);
	
	
	LEDs=0xf8;
  delay(1000);
	
	
	LEDs=0xfc;
  delay(1000);
	
	
	LEDs=0xfe;
  delay(1000);
	
	
	LEDs=0xff;
  delay(1000);
	
	} // while loop closed

	} // main closed