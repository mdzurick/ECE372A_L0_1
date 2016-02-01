/* 
 * File:   led.c
 * Author: mdzurick
 * Description: Initialize the LEDs.  Turn on LED specified.
 * Created on August 27, 2015, 3:15 PM
 */

/**************************************************/

#include <xc.h>
#include "led.h"

/**************************************************/

#define LED0 LATDbits.LATD0
#define LED1 LATDbits.LATD1
#define LED2 LATDbits.LATD2

#define LED0_TRIS TRISDbits.TRISD0
#define LED1_TRIS TRISDbits.TRISD1
#define LED2_TRIS TRISDbits.TRISD2

#define ON 1
#define OFF 0

#define OUTPUT 0

/**************************************************/

/* Initializes all 3 LEDs. */
void initLEDs(){
    
    LED0_TRIS = OUTPUT;
    LED1_TRIS = OUTPUT;
    LED2_TRIS = OUTPUT;
    
}

/* Turns on the specified LED (0 thru 2). */
void turnOnLED(int led){
    
    if (led == 0) {
        LED0 = ON;
        LED1 = OFF;
        LED2 = OFF;
    }
    else if (led == 1) {
        LED0 = OFF;
        LED1 = ON;
        LED2 = OFF;
    }
    else if (led == 2) {
        LED0 = OFF;
        LED1 = OFF;
        LED2 = ON;
    }
    
}