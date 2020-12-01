/*
 * oled.h
 *
 *  Created on: Nov 23, 2020
 *      Author: Mason Milligan
 *      Derived from Sparkfun's Micro OLED library: https://github.com/sparkfun/SparkFun_Micro_OLED_Arduino_Library
 */

#ifndef OLED_H_
#define OLED_H_

#include "i2c.h"

#define I2C_ADDRESS_SA0_1   0b0111101
#define I2C_COMMAND         0x00
#define I2C_DATA            0x40
#define LCDWIDTH            64
#define LCDHEIGHT           48
#define DISPLAYOFF          0xAE
#define DISPLAYON           0xAF
#define SETDISPLAYCLOCKDIV  0xD5
#define SETSTARTLINE        0x40
#define CHARGEPUMP          0x8D
#define NORMALDISPLAY       0xA6
#define DISPLAYALLONRESUME  0xA4
#define SEGREMAP            0xA0
#define SETMULTIPLEX        0xA8
#define SETDISPLAYOFFSET    0xD3
#define COMSCANDEC          0xC8
#define SETCOMPINS          0xDA
#define SETCONTRAST         0x81
#define SETPRECHARGE        0xD9
#define SETVCOMDESELECT     0xDB

void oled_begin(void);
void oled_clear(void);
void oled_display(uint8_t* bitArray);
void oled_setPageAddress(uint8_t add);

#endif /* OLED_H_ */
