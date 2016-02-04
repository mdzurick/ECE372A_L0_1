/* 
 * File:   timer.h
 * Author: mdzurick
 * Description: Header file to do with timers.
 * Created on August 27, 2015, 3:26 PM
 */

/**************************************************/

#ifndef TIMER_H
#define	TIMER_H

/**************************************************/

#define TMR1_TURNON T1CONbits.TON
#define TMR2_TURNON T2CONbits.TON 

#define TMR1_INTERRUPT_FLAG IFS0bits.T1IF
#define TMR2_INTERRUPT_FLAG IFS0bits.T2IF

#define TIMER_OFF 0

#define DOWN 0

/**************************************************/

void initTimer1();
void initTimer2();
void delayMs(int ms);
void startTimer1();

/**************************************************/

#endif	/* TIMER_H */

