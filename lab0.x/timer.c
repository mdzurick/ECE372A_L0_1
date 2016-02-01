/* 
 * File:   timer.c
 * Author: gvanhoy
 * Description: This will initialize the one second timer for this lab.
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>

void initTimer1(){
    TMR1 = 0; // Reset the count value to 0.
    T1CONbits.TCKPS = 3; // Configure how fast the timer is ticking.
    PR1 = 10; // Set period register.
    
    T1CONbits.ON = 1; // Turn on the timer.
    IFS0bits.T1IF = 0; // Sets flag down.
    IEC0bits.T1IE = 1; // Enables the interrupt.
    IPC1bits.T1IP = 7; // ?
}