/*
 * Piezo.c
 *
 *  Created on: Nov 15, 2020
 *      Author: j_ram
 */
#include "msp.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>

int i;
int SCARED;
int SUPRISED;
int HAPPY;
// *****ALL BITMASKS NEED TO BE SERIOUSLY LOOKED AT AND ADJUSTED******
void config_piezo_pin(void){
    P4 -> DIR |= BIT0; // sets p4 direction register to 1, meaning pin 4 is an output **BIT MASK MAY BE WRONG**
    P4 -> OUT &= BIT0; //set p4 out to 0 just so the piezo isn't making noise **BIT MASK MAY BE WRONG**
    P4 -> SEL0 &= BIT0;
    P4 -> SEL1 &= BIT0; //both of these commands should set the bit to 0 to ensure normal I/O functionality **may not actually be neccesary depending on default state of the register
}

void piezo_noise(int outputEmotion){ //taking the emotion string as an input parameter
    if (outputEmotion == HAPPY){
        P4 -> OUT |= BIT0; //Piezo starts buzzing, bit needs to be 1
        for (i = 1; i == 2000; i++){ //will this work with out timer situation?
        ;
        }
        P4 -> OUT ^= BIT0;
        //maybe a longer noise like a purr??
    }
    else if (outputEmotion == SCARED){
        P4 -> OUT |= BIT0;
        for (i = 1; i == 500; i++){
        ;
        }
        P4 -> OUT ^= BIT0;
        //maybe a short note like a gasp
    }
    else if (outputEmotion == SUPRISED){
        P4 -> OUT |= BIT0;
        for (i = 1; i == 1000; i++){
        }
        P4 -> OUT ^= BIT0;
        for (i = 1; i == 1000; i++){
        ;
        }
        P4 -> OUT ^= BIT0;
        for (i = 1; i == 1000; i++){
        ;
        }
        P4 -> OUT ^= BIT0;
    }
    else {
        ; // nothing should happen
    }
}

