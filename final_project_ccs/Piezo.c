/*
 * Piezo.c
 *
 *  Created on: Nov 15, 2020
 *      Author: j_ram
 */
#include "msp.h"
#include "time.h"
#include "stdio.h"


// *****ALL BITMASKS NEED TO BE SERIOUSLY LOOKED AT AND ADJUSTED******
void config_piezo_pin(void){
    P4 -> DIR |= BIT1; // sets p4 direction register to 1, meaning pin 4 is an output **BIT MASK MAY BE WRONG**
    P4 -> OUT |= BIT1; //set p4 out to 0 just so the piezo isn't making noise **BIT MASK MAY BE WRONG**
    P4 -> SEL0 |= BIT1;
    P4 -> SEL1 |= BIT1; //both of these commands should set the bit to 0 to ensure normal I/O functionality **may not actually be neccesary depending on default state of the register
}

void piezo_noise(outputEmotion){ //taking the emotion string as an input parameter
    if (outputEmotion == "happy"){
        P4 -> OUT |= BIT1; //Piezo starts buzzing, bit needs to be 1
        delay(2); //will this work with out timer situation?
        P4 -> OUT |= BIT1;
        //maybe a longer noise like a purr??
    }
    else if (outputEmotion == "suprised"){
        P4 -> OUT |= BIT1;
        delay(.5);
        P4 -> OUT |= BIT1;
        //maybe a short note like a gasp
    }
    else {
        ; // nothing should happen
    }
}

