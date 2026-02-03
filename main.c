/*
 * File:   main.c
 * Author: VINAYAK ACHARYA
 *
 * Created on 21 January, 2026, 8:53 AM
 */


#include <xc.h>

void main(void) 
{
    TRISB = 0x00;
    PORTB = 0x00;

    unsigned long int delay = 0;
    int i = 0;

    while(1)
    {
        if(++delay >= 10000)
        {
            delay = 0;

            if(i < 8)
            {
                PORTB = (unsigned char)((PORTB << 1) | 0x01);
            }
            else if(i < 16)
            {
                PORTB = (unsigned char)(PORTB << 1); 
            }
            else if(i < 24)
            {
                PORTB = (unsigned char)((PORTB >> 1) | 0x80);
            }
            else if(i < 32)
            {
                PORTB = (unsigned char)(PORTB >> 1);
            }
            else
            {
                i = 0;
            }
            i++;
        }
    }
}
