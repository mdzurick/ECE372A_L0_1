/* 
 * File:   main.c
 * Author: mdzurickh
 * Description: lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

/**************************************************/

#include <xc.h>
#include <sys/attribs.h>
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

/**************************************************/

#define DOWN 0

#define TIMER1_FLAG IFS0bits.T1IF

/**************************************************/

typedef enum stateTypeEnum {
    led0, led1, led2
} stateType;

/**************************************************/

volatile stateType state = led0;

/**************************************************/

int main() {
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.

    initLEDs();
    initTimer1();
    
    while(1){
        switch (state) {
            case led0:
                turnOnLED(0);
                break;
            case led1:
                turnOnLED(1);
                break;
            case led2:
                turnOnLED(2);
                break;
        }
    }
    
    return 0;
}

void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interrupt() {
    
    TIMER1_FLAG = DOWN;
    
    if (state == led0) {
        state = led1;
    }
    else if (state == led1) {
        state = led2;
    }
    else if (state == led2) {
        state = led0;
    }
    
}