/*
 * Range.h
 *
 *  Created on: Dec 4, 2020
 *      Author: mason
 */

#ifndef RANGE_H_
#define RANGE_H_

void initiateTrigger(void);
static void Delay(uint32_t loop);
void range_begin(void);
int range(uint32_t* sense_out);
int uart_puts(const char *str);
void PORT2_IRQHandler(void);
void TA0_0_IRQHandler(void);

int miliseconds;
int distance;
long sensor;

#endif /* RANGE_H_ */
