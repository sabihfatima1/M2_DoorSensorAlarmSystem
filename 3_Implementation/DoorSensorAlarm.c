
/*
* A door sensor is connected to bit 0 of Port D.
* An LED is connected to bit 6  of Port C .
* An Audio Out device is connected to bit 3 of port C.
* Write an AVR C program to monitor the door sensor and when it opens turns on the LED without changing the state of other pins.
* 
* Created: 20-04-2022
* Author: Sabih Fatima

*/





#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>



int main(void)
{

 

  
  DDRC=0XFF;
  DDRC|=(1<<PC0);  //  set B0=1 for led
  DDRD&=~(1<<PD0);  // clear bit
  PORTD|=(1<<PD0);
  
  while(1)
  {
  
    if(!(PIND&(1<<PD0))) //switch press
     {
	 
	  
	 
     PORTC&=~(1<<PC0); //LED will not glow
	 _delay_ms(20);      //Wait for some time
	   

      
	 }
	 
	 else
	 {
	 
	 
	 PORTC|=(1<<PC0);  //LED will  glow
	 _delay_ms(20);      //Wait for some time
	 
	  PORTC=0xFF;       //Turn ON the Buzzer connected to PORTC
		 _delay_ms(20); //Wait for some time
		 PORTC=0X00;    //Turn OFF the BUZZER connected to PORTC
		 _delay_ms(20); //wait for some time
         
	 
	 
	 }
	 
 
  }
  return 0;
  
  
}