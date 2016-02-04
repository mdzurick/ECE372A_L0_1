/* 
 * File:   switch.c
 * Author: mdzurick
 * Description: This is the code used to initialize and take use of the switch.
 * Created on August 27, 2015, 3:26 PM
 */

/**************************************************/

#include <xc.h>

/**************************************************/

#define SW1_TRIS TRISDbits.TRISD6
#define SW1_PULLUP CNPUDbits.CNPUD6

#define INPUT 1
#define ENABLE 1

/**************************************************/

/* Initializes switch 1. */
void initSwitch1 () {
    
    SW1_TRIS = INPUT; // Configures switch tristate as an input.
    CNCONDbits.ON = 1;
    CNENDbits.CNIED6 = 1;
    
    IEC1bits.CNDIE = ENABLE; // Enables the interrupt.
    IFS1bits.CNDIF = 0;
    IPC8bits.CNIP = 7;
    
    SW1_PULLUP = ENABLE; // Uses a pull-up resistor on the switch.
    
}