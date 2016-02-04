/* 
 * File:   timer.c
 * Author: mdzurick
 * Description: This will initialize the one second timer for this lab.
 * Created on August 27, 2015, 3:26 PM
 */

/**************************************************/

#include <xc.h>
#include "timer.h"

/**************************************************/

#define PRESCALAR_256 3

#define ON 1

#define TMR1_REG TMR1
#define TMR1_PRESCALAR T1CONbits.TCKPS
#define TMR1_OSCILLATOR T1CONbits.TCS
#define TMR1_PERIOD_REG PR1
#define TMR1_TURNON T1CONbits.TON
#define TMR1_INTERRUPT_FLAG IFS0bits.T1IF
#define TMR1_INTERRUPT IEC0bits.T1IE
#define TMR1_INTERRUPT_PRIORITY IPIC1bits.T1IP

/**************************************************/

/* Initializes Timer 1 and starts it. */
void initTimer1(){
    TMR1_REG = 0; // Reset the count value to 0.
    
    TMR1_PRESCALAR = PRESCALAR_256; // Configure how fast the timer is ticking.
    TMR1_OSCILLATOR = 0; // Oscillator choice.
    
    TMR1_PERIOD_REG = 39062; // Set period register (Number to count to).
    
    TMR1_TURNON = 1; // Turn on the timer.
    TMR1_INTERRUPT_FLAG = DOWN; // Sets flag down.
    TMR1_INTERRUPT = 1; // Enables the interrupt.
    TMR1_INTERRUPT_PRIORITY = 7; // Interrupt priority at 7.
}