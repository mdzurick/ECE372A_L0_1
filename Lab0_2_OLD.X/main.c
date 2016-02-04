/* 
 * File:   main.c
 * Author: mdzurick
 * Description: lab 0.
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
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.

    initLEDs();
    initSwitch1();
    initTimer1();
    
    while(1){
        switch (state) {
            case led0:
                turnOnLED(0);
                currLED = 0;
                longer = 0;
                break;
                
            case led1:
                turnOnLED(1);
                currLED = 1;
                longer = 0;
                break;
                
            case led2:
                turnOnLED(2);
                currLED = 2;
                longer = 0;
                break;
                
            case debouncePress:
                startTimer1();
                delayMs(50);
                state = waitRelease;
                break;
                
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
                
            case waitRelease:
                break;
                
        }
    }
    
    return 0;
}

void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interrupt() {
    
    TIMER1_FLAG = DOWN;
    
    longer = 1;
    T1CONbits.TON = TIMER_OFF;
    
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

/*
void __ISR(_TIMER_2_VECTOR, IPL7SRS) _T2Interrupt() {
    
    TIMER2_FLAG = DOWN;

}
*/