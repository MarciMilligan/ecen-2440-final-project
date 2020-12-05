/*
 * thermistor.c
 *
 *  Created on: Nov 15, 2020
 *      Author: j_ram
 */

#include "msp.h"
float ADC_reading; // Analog to Digital Conversion Value
float thermistor_resistance;
int val;

void config_analog_pin(void){
    P6->SEL1 |= BIT0; //sets bit SEL1.0 to 1
    P6->SEL0 |= BIT0; //sets bit SEL0.0 to 1
    //with both of these bits = 1, pin 6 should be in analog in function
return;
}

void adc_setup(void){
    ADC14->CTL0 = 0x44000210;
    ADC14->CTL1 = 0x00000020;
    ADC14->MCTL[0] = 0x00000000;
    ADC14->CTL0 |= 0x00000002;
    //should configure ADC to the setting we need (single conversion) **ONE OF THE FIRST PLACES TO CHECK IF THERMISTOR NOT WORKING**
    //if we want to change this from a function we call to figure out if the robot is being pet to a function that continuosly checks we can do so, we just have to add interupts
return;
}


int adc_convert(void){
    ADC14->CTL0 |= 0x00000001;

    while (!ADC14->IFGR0){
        ;
    }
    return ADC14->MEM[0];
    //should read analog pin, convert the value (to some sort of hex value) and then store it to ADC14 mem
}


int pet_check(void){
    val = ADC14->MEM[0];
    if (val <= 100){ //I need to setup and test this
        return 1;
    }
    else {
        return 0;
    }
}

