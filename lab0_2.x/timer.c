/* 
 * File:   timer.c
 * Author: mdzurick
 * Description: This will initialize the one second timer for this lab.
 * Created on August 27, 2015, 3:26 PM
 */

/**************************************************/

#include <xc.h>

/**************************************************/

#define T1_PRESCALAR_256 3
#define T2_PRESCALAR_256 7
#define FREQ 625000
#define TIMER_ON 1
#define TIMER_OFF 0
#define DOWN 0
#define TIMER2_FLAG IFS0bits.T2IF

/**************************************************/

void initTimer1() {
    
    TMR1 = 0; // Reset the count value to 0.
    
    T1CONbits.TCKPS = T1_PRESCALAR_256; // Configure how fast the timer is ticking.
    T1CONbits.TCS = 0; // Oscillator choice.
    
    PR1 = 39062; // Set period register (Number to count to).
    
    T1CONbits.ON = TIMER_ON; // Turn on the timer.
    IFS0bits.T1IF = 0; // Sets flag down.
    IEC0bits.T1IE = 1; // Enables the interrupt.
    IPC1bits.T1IP = 7; // Interrupt priority at 7.
    
}

void initTimer2() {
    
    TMR2 = 0; // Reset the count value to 0.
    
    T2CONbits.TCKPS = T2_PRESCALAR_256; // Configure how fast the timer is ticking.
    T2CONbits.TCS = 0; // Oscillator choice.
    
    IFS0bits.T2IF = 0; // Sets flag down.
    IEC0bits.T2IE = 1; // Enables the interrupt.
    IPC2bits.T2IP = 7; // Interrupt priority at 7.

}

void delayMs(int ms) {
    
    unsigned int PR_value = (unsigned int)((FREQ*ms)/(256*1000)) - 1;
    PR2 = PR_value;
    
    TMR2 = 0;
    
    TIMER2_FLAG = DOWN;
    T2CONbits.ON = TIMER_ON;
    
    while (TIMER2_FLAG == DOWN) {}
    
    TIMER2_FLAG = DOWN;
    
    T2CONbits.TON = TIMER_OFF;
    
}