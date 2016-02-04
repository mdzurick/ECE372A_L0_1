/* 
 * File:   switch.c
 * Author: mdzurick
 * Description: This is the code used to initialize and take use of the switch.
 * Created on August 27, 2015, 3:26 PM
 */

/**************************************************/

#include <xc.h>
#include "switch.h"

/**************************************************/

#define SW1_TRIS TRISDbits.TRISD6
#define SW1_PULLUP CNPUDbits.CNPUD6
#define SW1_CN_CONFIG CNCONDbits.ON
#define SW1_CN_ENABLE CNENDbits.CNIED6
#define SW1_INTERRUPT IEC1bits.CNDIE
#define SW1_INTERRUPT_FLAG IFS1bits.CNDIF
#define SW1_INTERRUPT_PRIORITY IPC8bits.CNIP 

#define INPUT 1
#define ENABLE 1

#define DOWN 0

/**************************************************/

/* Initializes switch 1. */
void initSwitch1 () {
    
    SW1_TRIS = INPUT; // Configures switch tristate as an input.
    SW1_CN_CONFIG = ENABLE; // Change notification configuration bit.
    SW1_CN_ENABLE = ENABLE; // Change notification enable.
    
    SW1_INTERRUPT = ENABLE; // Enables the interrupt.
    SW1_INTERRUPT_FLAG = DOWN; // Puts down interrupt flag.
    SW1_INTERRUPT_PRIORITY = 7; // Sets interrupt priority.
    
    SW1_PULLUP = ENABLE; // Uses a pull-up resistor on the switch.
    
}