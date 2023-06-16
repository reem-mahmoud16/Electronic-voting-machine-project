/*
 * electronic_voting_machine.c
 *
 * Created: 8/17/2022 2:16:12 AM
 *  Author: HP.SXH08
 */ 


#include <avr/io.h>
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "button.h"
#include "LCD.h"
#define del 50


int main(void)
{
	LCD_vInit();
	button_vInit('B',3);
	button_vInit('B',4);
	button_vInit('B',5);
	button_vInit('B',6);
	button_vInit('B',7);
	
	char a=0,b=0,c=0,d=0;
	char oldread_A=0, oldread_B=0, oldread_C=0, oldread_D=0, oldReset=0;
	char newread_A, newread_B, newread_C, newread_D, newReset;
	
	LCD_clearscreen();
	LCD_vSend_string("A=");
	LCD_vSend_char(a+48);
	LCD_movecursor(1,8);
	LCD_vSend_string("B=");
	LCD_vSend_char(b+48);
	LCD_movecursor(2,1);
	LCD_vSend_string("C=");
	LCD_vSend_char(c+48);
	LCD_movecursor(2,8);
	LCD_vSend_string("D=");
	LCD_vSend_char(d+48);
    while(1)
    {
		
        newread_A= button_u8read('B',3);
		newread_B= button_u8read('B',4);
		newread_C= button_u8read('B',5);
		newread_D= button_u8read('B',6);
		newReset= button_u8read('B',7);
		
		if(oldread_A==1 && newread_A==0 && a<100)
		{
			if(a+1 > 9)
			{
				a++;
				LCD_movecursor(1,3);
				LCD_vSend_char((a/10)+48);
				LCD_movecursor(1,4);
				LCD_vSend_char((a%10)+48);
			}
			else
			{
				a++;
				LCD_movecursor(1,3);
				LCD_vSend_char(a+48);
				//_delay_ms(del);
			}
			
		}
		else if(oldread_B==1 && newread_B==0 && b<100)
		{
			if(b+1 > 9)
			{
				b++;
				LCD_movecursor(1,10);
				LCD_vSend_char((b/10)+48);
				LCD_movecursor(1,11);
				LCD_vSend_char((b%10)+48);
			}
			else
			{
				b++;
				LCD_movecursor(1,10);
				LCD_vSend_char(b+48);
				//_delay_ms(del);
			}
			
		}
		else if(oldread_C==1 && newread_C==0 && c<100)
		{
			if(c+1 > 9)
			{
				c++;
				LCD_movecursor(2,3);
				LCD_vSend_char((c/10)+48);
				LCD_movecursor(2,4);
				LCD_vSend_char((c%10)+48);
			}
			else
			{
				c++;
				LCD_movecursor(2,3);
				LCD_vSend_char(c+48);
				//_delay_ms(del);
			}
			
		}
		else if(oldread_D==1 && newread_D==0 && d<100)
		{
			if(d+1 > 9)
			{
				d++;
				LCD_movecursor(2,10);
				LCD_vSend_char((d/10)+48);
				LCD_movecursor(2,11);
				LCD_vSend_char((d%10)+48);
			}
			else
			{
				d++;
				LCD_movecursor(2,10);
				LCD_vSend_char(d+48);
				//_delay_ms(del);
			}
			
		}
		else if(oldReset==1 && newReset==0)
		{
			a=0;
			b=0;
			c=0;
			d=0;
			LCD_movecursor(1,3);
			LCD_vSend_char(a+48);
			LCD_movecursor(1,4);
			LCD_vSend_char(0x20);
			
			LCD_movecursor(1,10);
			LCD_vSend_char(b+48);
			LCD_movecursor(1,11);
			LCD_vSend_char(0x20);
			
			LCD_movecursor(2,3);
			LCD_vSend_char(c+48);
			LCD_movecursor(2,4);
			LCD_vSend_char(0x20);
			
			LCD_movecursor(2,10);
			LCD_vSend_char(d+48);
			LCD_movecursor(2,11);
			LCD_vSend_char(0x20);
			//_delay_ms(del);
			
		}
		
		oldread_A= newread_A;
		oldread_B= newread_B;
		oldread_C= newread_C;
		oldread_D= newread_D;
		oldReset= newReset;
		
		
    }
}