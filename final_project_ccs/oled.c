/*
 * oled.c
 *
 *  Created on: Nov 23, 2020
 *      Author: Mason Milligan
 *      Derived from Sparkfun's Micro OLED library: https://github.com/sparkfun/SparkFun_Micro_OLED_Arduino_Library
 */

#include "oled.h"


void oled_begin(void) {
    // Display Init sequence for 64x48 OLED module
    // forming arrays ahead of function call to avoid overwriting before sending via I2C
    uint8_t i2c_buffer_0[] = {I2C_COMMAND, DISPLAYOFF};
    uint8_t i2c_buffer_1[] = {I2C_COMMAND, SETDISPLAYCLOCKDIV};
    uint8_t i2c_buffer_2[] = {I2C_COMMAND, 0x80};
    uint8_t i2c_buffer_3[] = {I2C_COMMAND, SETMULTIPLEX};
    uint8_t i2c_buffer_4[] = {I2C_COMMAND, 0x2F};
    uint8_t i2c_buffer_5[] = {I2C_COMMAND, SETDISPLAYOFFSET};
    uint8_t i2c_buffer_6[] = {I2C_COMMAND, 0x00};
    uint8_t i2c_buffer_7[] = {I2C_COMMAND, SETSTARTLINE};
    uint8_t i2c_buffer_8[] = {I2C_COMMAND, CHARGEPUMP};
    uint8_t i2c_buffer_9[] = {I2C_COMMAND, 0x14};
    uint8_t i2c_buffer_10[] = {I2C_COMMAND, NORMALDISPLAY};
    uint8_t i2c_buffer_11[] = {I2C_COMMAND, DISPLAYALLONRESUME};
    uint8_t i2c_buffer_12[] = {I2C_COMMAND, SEGREMAP|0x01};
    uint8_t i2c_buffer_13[] = {I2C_COMMAND, COMSCANDEC};
    uint8_t i2c_buffer_14[] = {I2C_COMMAND, SETCOMPINS};
    uint8_t i2c_buffer_15[] = {I2C_COMMAND, 0x12};
    uint8_t i2c_buffer_16[] = {I2C_COMMAND, SETCONTRAST};
    uint8_t i2c_buffer_17[] = {I2C_COMMAND, 0x8F};
    uint8_t i2c_buffer_18[] = {I2C_COMMAND, SETPRECHARGE};
    uint8_t i2c_buffer_19[] = {I2C_COMMAND, 0xF1};
    uint8_t i2c_buffer_20[] = {I2C_COMMAND, SETVCOMDESELECT};
    uint8_t i2c_buffer_21[] = {I2C_COMMAND, 0x40};
    uint8_t i2c_buffer_22[] = {I2C_COMMAND, DISPLAYON};
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_0, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_1, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_2, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_3, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_4, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_5, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_6, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_7, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_8, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_9, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_10, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_11, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_12, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_13, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_14, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_15, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_16, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_17, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_18, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_19, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_20, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_21, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_22, 2, 0x00);

    oled_clear();                       // Erase hardware memory inside the OLED controller to avoid random data in memory.
}


void oled_clear(void) {
    int i, j;
    for (i=0;i<6; i++) {
        oled_setPageAddress(i);
        for (j=0; j<64; j++) {
            uint8_t i2c_buffer[] = {0x40, 0x00};
            i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer, 2, 0x00);
        }
    }
}


void oled_display(uint8_t* bitArray) {
    oled_clear();
    int i, j;
    for (i=0; i<6; i++) {
        oled_setPageAddress(i);
        for (j=0;j<16;j++) {
            uint8_t i2c_buffer_0[] = {0x40, bitArray[i*64+4*j]};
            i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_0, 2, 0x00);
            uint8_t i2c_buffer_1[] = {0x40, bitArray[i*64+j*4+1]};
            i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_1, 2, 0x00);
            uint8_t i2c_buffer_2[] = {0x40, bitArray[i*64+j*4+2]};
            i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_2, 2, 0x00);
            uint8_t i2c_buffer_3[] = {0x40, bitArray[i*64+j*4+3]};
            i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_3, 2, 0x00);
        }
    }
}


void oled_setPageAddress(uint8_t add) {
    uint8_t i2c_buffer_0[] = {I2C_COMMAND, 0xB0|add};
    uint8_t i2c_buffer_1[] = {I2C_COMMAND, 0x12};
    uint8_t i2c_buffer_2[] = {I2C_COMMAND, 0x00};
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_0, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_1, 2, 0x00);
    i2c_start(EUSCI_B0, I2C_ADDRESS_SA0_1, WRITE, i2c_buffer_2, 2, 0x00);
}
