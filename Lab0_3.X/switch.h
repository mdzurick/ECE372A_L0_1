/* 
 * File:   switch.h
 * Author: mdzurick
 * Description: Header file to do with switches.
 * Created on August 27, 2015, 3:26 PM
 */

/**************************************************/

#ifndef SWITCH_H
#define	SWITCH_H

/**************************************************/

#define SW1 PORTDbits.RD6

#define PRESSED 0
#define UNPRESSED 1

#define SW1_FLAG IFS1bits.CNDIF

/**************************************************/

void initSwitch1();

/**************************************************/

#endif	/* SWITCH_H */

