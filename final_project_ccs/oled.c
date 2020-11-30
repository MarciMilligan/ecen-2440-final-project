/*
 * oled.c
 *
 *  Created on: Nov 23, 2020
 *      Author: Mason Milligan
 *      Derived from Sparkfun's Micro OLED library: https://github.com/sparkfun/SparkFun_Micro_OLED_Arduino_Library
 */

#include "oled.h"


void oled_begin() {
    // Display Init sequence for 64x48 OLED module
    oled_command(DISPLAYOFF);           // 0xAE
    oled_command(DISPLAYOFF);           // 0xAE running this twice due to problems with it running the first time

    oled_command(SETDISPLAYCLOCKDIV);   // 0xD5
    oled_command(0x80);                 // the suggested ratio 0x80

    oled_command(SETMULTIPLEX);         // 0xA8
    oled_command(0x2F);

    oled_command(SETDISPLAYOFFSET);     // 0xD3
    oled_command(0x00);                 // no offset

    oled_command(SETSTARTLINE);         // line #0

    oled_command(CHARGEPUMP);           // enable charge pump
    oled_command(0x14);

    oled_command(NORMALDISPLAY);        // 0xA6
    oled_command(DISPLAYALLONRESUME);   // 0xA4

    oled_command(SEGREMAP | 0x01);
    oled_command(COMSCANDEC);

    oled_command(SETCOMPINS);           // 0xDA
    oled_command(0x12);

    oled_command(SETCONTRAST);          // 0x81
    oled_command(0x8F);

    oled_command(SETPRECHARGE);         // 0xD9
    oled_command(0xF1);

    oled_command(SETVCOMDESELECT);      // 0xDB
    oled_command(0x40);

    oled_command(DISPLAYON);            //--turn on oled panel
    oled_clear();                       // Erase hardware memory inside the OLED controller to avoid random data in memory.
}


void oled_drawBitmap(uint8_t* bitArray) {
    int i;
    for (i=0; i<384; i++) {
        screenmemory[i] = bitArray[i];
    }
}


void oled_clear(void) {
    int i, j;
    for (i=0;i<6; i++) {
        oled_setPageAddress(i);
        oled_setColumnAddress();
        for (j=0; j<64; j++) {
            oled_data(0x00);
        }
    }
}


void oled_display(void) {
    int i, j;
    for (i=0; i<6; i++) {
        oled_setPageAddress(i);
        oled_setColumnAddress();
        for (j=0;j<64;j++) {
            oled_data(screenmemory[i*64+j]);
        }
    }
}


void oled_i2cWrite(uint8_t address, uint8_t dc, uint8_t data) {
    uint8_t send_array[] = {dc, data};
    i2c_start(EUSCI_B0, address, WRITE, send_array, 2, 0x00);
}


void oled_setPageAddress(uint8_t add) {
    oled_command(0xb0|add);
}


void oled_setColumnAddress(void) {
    oled_command(0x12);
    oled_command(0x00);
}


void oled_data(uint8_t c) {
    oled_i2cWrite(I2C_ADDRESS_SA0_1, I2C_DATA, c);
}


void oled_command(uint8_t c) {
    oled_i2cWrite(I2C_ADDRESS_SA0_1, I2C_COMMAND, c);
}
