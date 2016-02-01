/* 
 * File:   timer.c
 * Author: mdzurick
 * Description: This will initialize the one second timer for this lab.
 * Created on August 27, 2015, 3:26 PM
 */

/**************************************************/

#include <xc.h>

/**************************************************/

#define PRESCALAR_256 3

/**************************************************/

void initTimer1(){
    TMR1 = 0; // Reset the count value to 0.
    
    T1CONbits.TCKPS = PRESCALAR_256; // Configure how fast the timer is ticking.
    T1CONbits.TCS = 0; // Oscillator choice.
    
    PR1 = 39062; // Set period register (Number to count to).
    
    T1CONbits.ON = 1; // Turn on the timer.
    IFS0bits.T1IF = 0; // Sets flag down.
    IEC0bits.T1IE = 1; // Enables the interrupt.
    IPC1bits.T1IP = 7; // Interrupt priority at 7.
}