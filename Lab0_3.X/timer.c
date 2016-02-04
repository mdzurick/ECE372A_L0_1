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

#define T1_PRESCALAR_256 3
#define T2_PRESCALAR_256 7
#define FREQ 625000
#define TIMER_ON 1
#define TIMER_OFF 0
#define ENABLE 1

#define TMR1_REG TMR1
#define TMR1_PRESCALAR T1CONbits.TCKPS
#define TMR1_OSCILLATOR T1CONbits.TCS
#define TMR1_PERIOD_REG PR1
#define TMR1_TURNON T1CONbits.TON
#define TMR1_INTERRUPT_FLAG IFS0bits.T1IF
#define TMR1_INTERRUPT IEC0bits.T1IE
#define TMR1_INTERRUPT_PRIORITY IPC1bits.T1IP

#define TMR2_REG TMR2
#define TMR2_PRESCALAR T2CONbits.TCKPS
#define TMR2_OSCILLATOR T2CONbits.TCS
#define TMR2_PERIOD_REG PR2
#define TMR2_TURNON T2CONbits.TON
#define TMR2_INTERRUPT IEC0bits.T2IE
#define TMR2_INTERRUPT_PRIORITY IPC2bits.T2IP

/**************************************************/

void initTimer1() {
    
    TMR1_REG = 0; // Reset the count value to 0.
    
    TMR1_PRESCALAR = T1_PRESCALAR_256; // Configure how fast the timer is ticking.
    TMR1_OSCILLATOR = 0; // Oscillator choice.
    
    TMR1_PERIOD_REG = 39062; // Set period register (Number to count to).
    
    TMR1_TURNON = TIMER_ON; // Turn on the timer.
    TMR1_INTERRUPT_FLAG = DOWN; // Sets flag down.
    TMR1_INTERRUPT = ENABLE; // Enables the interrupt.
    TMR1_INTERRUPT_PRIORITY = 7; // Interrupt priority at 7.
    
}

/* Initializes the second timer. */
void initTimer2() {
    
    TMR2_REG = 0; // Reset the count value to 0.
    
    TMR2_PRESCALAR = T2_PRESCALAR_256; // Configure how fast the timer is ticking.
    TMR2_OSCILLATOR = 0; // Oscillator choice.
    
    TMR2_INTERRUPT_FLAG = DOWN; // Sets flag down.
    TMR2_INTERRUPT = ENABLE; // Enables the interrupt.
    TMR2_INTERRUPT_PRIORITY = 7; // Interrupt priority at 7.

}

/* Creates a millisecond delay of specified ms length. */
void delayMs(int ms) {
    
    unsigned int PR_value = (unsigned int)((FREQ*ms)/(256*1000)) - 1;
    TMR2_PERIOD_REG = PR_value;
    
    TMR2_REG = 0; // Reset the count value to 0.
    
    TMR2_INTERRUPT_FLAG = DOWN;
    TMR2_TURNON = TIMER_ON;
    
    while (TMR2_INTERRUPT_FLAG == DOWN) {}
    
    TMR2_INTERRUPT_FLAG = DOWN;
    
    TMR2_TURNON = TIMER_OFF;
    
}

/* Starts the count to a second. */
void startTimer1() {
    
    TMR1_REG = 0;
    TMR1_INTERRUPT_FLAG = DOWN;
    TMR1_TURNON = TIMER_ON;
    
}