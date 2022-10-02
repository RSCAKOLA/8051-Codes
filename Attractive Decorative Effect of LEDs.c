
/*
  Code of blinking LEDs Extended code
	Created by: Vidyasagar Academy, Akola:- http://vsa.edu.in/ 
	Date: 25.02.2020

	*** Please respect our efforts 
	and write Google review about Vidyasagar Academy, Akola. ***

*/

#include <reg51.h> // registry head file included
#include "delay.c" // including the .c file for user defined delay function

int i,k=2;
float j=1;

	int main() // main function

	{ // main function brace opened

	while(1) // infinite loop

	{ // while loop brace opened

		// blink all LEDs 5 times
		for(i=0;i<5;i++)
		{
		P1=0xff;
		delay(1000);
		P1=0x00;
		delay(1000);
		}
		
		// forward running LEDs effect 8 times
		for(i=0;i<8;i++)
    {
      P1=j;
      delay(1000);
      j=j*2;
			
    if(j>128)
    {
      j=1;
    }		
		}

		// reverse running LEDs effect 8 times
		j=128;
		for(i=0;i<8;i++)
    {
      P1=j;
      delay(1000);
      j=j/2;
			
    if(j<1)
    {
      j=1;
    }		
		}





		// chasing LEDs effect 5 times
    for(i=0;i<10;i++)
    {
			P1=j;
			delay(1000);
			j=j+k; // incrementing the value of "j" by "k"
			k=k+k; // incrementing the value of "k" by "k"
		
    if(j=255) // when j=255, i.e. all LEDs are ON, we must make j=1, k=2
    {
      delay(1000); // this delay ensures that last 8th LED will glow for 1 sec.
      j=1;
      k=2;
    }
    }

	} // while loop closed

	} // main closed