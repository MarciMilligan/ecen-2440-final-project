/*
 * thermistor.h
 *
 *  Created on: Nov 15, 2020
 *      Author: j_ram
 */

#ifndef THERMISTOR_H_
#define THERMISTOR_H_

void config_analog_pin(void); // sets up pin 6 for analog read
void adc_setup(void); //setup ADC
int adc_convert(void); //get ADC value
int pet_check(void); //determines if robot is currently getting pet



#endif /* THERMISTOR_H_ */
