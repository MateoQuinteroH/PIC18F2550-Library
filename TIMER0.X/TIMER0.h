/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */
 
//#ifndef XC_HEADER_TEMPLATE_H
//#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define PRE256 7
#define PRE128 6
#define PRE64 5
#define PRE32 4
#define PRE16 3
#define PRE8 2
#define PRE4 1
#define PRE2 0

/*
void TMR0on(); // Function to start timer0
void TMR0config(int bits, int clock_source, int source_edge, int psa); // Function to config timer0
*/
void TMR0on()
{
    T0CONbits.TMR0ON=1;
    TMR0=0;
}

void TMR0off()
{
    T0CONbits.TMR0ON=0;
}
    
// bits: 8 for 8 bit timer, 16 for 16 bit timer
// clock_source: 1 for TOCKI, 1 for CLKO
// source_edge: 1 High to low T0CKI, Low to high TOCKI
// psa: 1 for not prescaler, 0 for prescaler
// prescaler: 2,4,8,16,32,64,128,256
// interrupts: 1 for use interrupts, 0 for dont use interrupts
void TMR0config(int bits, int clock_source, int source_edge, int psa, int prescaler, int interrupts)
{
    if(bits==8)
    {
        T0CONbits.T08BIT=1;
    }
    if(bits==16)
    {
        T0CONbits.T08BIT=0;
    }
    T0CONbits.T0CS=clock_source;
    T0CONbits.T0SE=source_edge;
    T0CONbits.PSA=psa;
    T0CON |= prescaler;
    
    if(interrupts==1)
    {
        INTCONbits.GIE=1; // Activate global interrupts
        INTCONbits.T0IE=1; // Activate timer 0 interrupt
    }
    if(interrupts==0)
    {
        INTCONbits.GIE=0; // Activate global interrupts
        INTCONbits.T0IE=0; // Activate timer 0 interrupt
    }
    
    
}
