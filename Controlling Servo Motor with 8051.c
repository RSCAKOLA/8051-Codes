
/*
  	The basic project of using servo motor in 8051 microcontroller

	Created by: Vidyasagar Academy, Akola

	Date: 18.06.2015
*/

#include<reg51.h>
sbit  servomotor_pin=P0^5;
void delay (unsigned int);
void servo_delay  (unsigned int);
void main()
{
servomotor_pin=0x00;
do
{
// turn to 0°
servomotor_pin=0x01;
sevo_delay(50);
servomotor_pin=0x00;
delay(1000);
//turn to 90 degrees
servomotor_pin=0x01;
sevo_delay(82);
servomotor_pin=0x00;
delay(1000);
//turn to 180 degrees
servomotor_pin=0x01;
sevo_delay(110);
servomotor_pin=0x00;
delay(1000);
while(1)
}
}
void delay(unsigned int a)
{
unsigned int p;
for(p=0;p<a;p++)
for(p=0;p<250;p++);
}
void servo_delay (unsigned int a)
{
unsigned int p;
for(p=0;p<a;p++)
for(p=0;p<250;p++);
}
