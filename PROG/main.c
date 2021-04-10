/*
 By Liyanboy74
 https://github.com/liyanboy74
*/

#include <mega16.h>
#include <stdio.h>
#include <delay.h>

#define RELAY_1 PORTA.0
#define RELAY_2 PORTA.1 
#define RELAY_3 PORTA.2 

#define LED_1   PORTB.0
#define LED_2   PORTB.1
#define LED_3   PORTB.2

#define OFF     0
#define ON      1

#define RELAY_DELAY_MS  500

/**
 * Char Table
 *{
 * 0:Relay 1 ON
 * 1:Relay 2 ON
 * 2:Relay 3 ON  
 * 3:Relay 1 OFF 
 * 4:Relay 2 OFF
 * 5:Relay 3 OFF
 * 6:All Off 
 * 7:Test LED
 *}
 */
const char CharTable[8]={'a','b','c','d','e','f','g','h'};

void main(void)
{
//buffer
char ch;

//GPIO Initial
DDRA=0XFF;
PORTA=0X00;
DDRB=0XFF;
PORTB=0X00;

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 9600
UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (1<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
UBRRH=0x00;
UBRRL=0x33;

while (1)
  {
  //Get char from bluetooth module 
  ch=getchar();
   
  //compare receiving data 

  //Relay 1 ON       
  if(ch==CharTable[0])
   {
   RELAY_1=ON;
   LED_1=ON;
   delay_ms(RELAY_DELAY_MS);
            
   }
   
   //Relay 2 On
  else if(ch==CharTable[1])
   {
   RELAY_2=ON;
   LED_2=ON;
   delay_ms(RELAY_DELAY_MS);        
   }
   
   //Relay 3 On
  else if(ch==CharTable[2])
   {
   RELAY_3=ON;
   LED_3=ON;
   delay_ms(RELAY_DELAY_MS);        
   }
   
   //Relay 1 Off
  else if(ch==CharTable[3])
   {
   RELAY_1=OFF;
   LED_1=OFF;
   delay_ms(RELAY_DELAY_MS);        
   } 
   
   //Relay 2 Off
  else if(ch==CharTable[4])
   {
   RELAY_2=OFF;
   LED_2=OFF;
   delay_ms(RELAY_DELAY_MS);        
   }
   
   //Relay 3 Off
  else if(ch==CharTable[5])
   {
   RELAY_3=OFF;
   LED_3=OFF;
   delay_ms(RELAY_DELAY_MS);        
   }
   
   //All Off 
  else if(ch==CharTable[6])
   {
   RELAY_1=OFF;
   RELAY_2=OFF;
   RELAY_3=OFF; 
   LED_1=OFF;
   LED_2=OFF;
   LED_3=OFF;
   delay_ms(RELAY_DELAY_MS);                    
   } 
   
   //LED Test               
  else if(ch==CharTable[7])
   {
   LED_1=ON;  
   LED_2=ON;
   LED_3=ON;
   delay_ms(RELAY_DELAY_MS*2);
   LED_1=OFF;  
   LED_2=OFF;
   LED_3=OFF;  

   RELAY_1=OFF;  
   RELAY_2=OFF;
   RELAY_3=OFF;                    
   }  
  }
}
