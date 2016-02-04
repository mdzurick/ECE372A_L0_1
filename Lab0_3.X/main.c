/* 
 * File:   main.c
 * Author: mdzurick
 * Description: main.c file for the 3rd part of lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

/**************************************************/

#include <xc.h>
#include <sys/attribs.h>
#include "timer.h"
#include "led.h"
#include "switch.h"
#include "interrupt.h"
#include "config.h"

/**************************************************/



/**************************************************/

typedef enum stateTypeEnum {
    led0, led1, led2, debounceRelease, debouncePress, waitRelease
} stateType;

/**************************************************/

volatile stateType state = led1;
volatile int currLED = 0;
volatile int longer = 0;

/**************************************************/

int main() {
    
    /* Enables interrupt and sets up clock. */
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.

    /* Initialize timers and switches. */
    initLEDs();
    initSwitch1();
    initTimer1();
    
    while(1){
        switch (state) {
            /* Turns on the LED 0. */
            case led0:
                turnOnLED(0);
                currLED = 0;
                longer = 0;
                break;
                
            /* Turns on the LED 1. */
            case led1:
                turnOnLED(1);
                currLED = 1;
                longer = 0;
                break;
                
            /* Turns on the LED 2. */
            case led2:
                turnOnLED(2);
                currLED = 2;
                longer = 0;
                break;
                
            /* Debounces the press of the switch. */
            case debouncePress:
                startTimer1();
                delayMs(50);
                state = waitRelease;
                break;
                
            /* Debounces the release of the switch. */
            case debounceRelease:
                delayMs(50);
                if (longer == 1) {
                    if (currLED == 0) {
                        state = led2;
                    }
                    else if (currLED == 1) {
                        state = led0;
                    }
                    else if (currLED ==2) {
                        state = led1;
                    }
                }
                else if (longer == 0) {
                    if (currLED == 0) {
                        state = led1;
                    }
                    else if (currLED == 1) {
                        state = led2;
                    }
                    else if (currLED == 2) {
                        state = led0;
                    }
                }
                break;
                
            /* Waits for the release of the switch.  Will utilize ISR to switch. */
            case waitRelease:
                break;
                
        }
    }
    
    return 0;
}

void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interrupt() {
    
    TMR1_INTERRUPT_FLAG = DOWN;
    
    longer = 1;
    TMR1_TURNON = TIMER_OFF;
    
}

void __ISR(_CHANGE_NOTICE_VECTOR, IPL7SRS) _SW1Interrupt() {
    
    SW1_FLAG = DOWN;
    
    if (SW1 == PRESSED) {
        state = debouncePress;
    }
    else if (SW1 == UNPRESSED) {
        state = debounceRelease;
    }
    
}