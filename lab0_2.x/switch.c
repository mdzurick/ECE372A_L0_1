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
#define ON 1

/**************************************************/

/* Initializes switch 1. */
void initSwitch1 () {
    
    SW1_TRIS = INPUT; // Configures switch tristate as an input.
    SW1_PULLUP = ON; // Uses a pull-up resistor on the switch.
    
}