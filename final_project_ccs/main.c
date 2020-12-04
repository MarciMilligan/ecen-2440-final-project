#include "msp.h"
#include "Actions.h"
#include "oled.h"
#include "stIMU.h"
#include "i2c.h"

/**
 * main.c
 *  
 * Created on 11/23/20
 * Code by Joshua Dinerman
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//enable interrupts
	NVIC_EnableIRQ(PORT1_IRQn);
    __enable_irq();

    I2C_OPEN_STRUCT_TypeDef i2c_open_struct;

    i2c_open_struct.uca10 = 0;                              //no self 10-bit Address
    i2c_open_struct.ucsla10 = 0;                            //no 10-bit Addressing
    i2c_open_struct.ucmm = 0;                               //No Multi-Master
    i2c_open_struct.ucmst = EUSCI_B_CTLW0_MST;              //Master Mode
    i2c_open_struct.ucsselx = EUSCI_B_CTLW0_SSEL__SMCLK;    //SMCLK to be selected (3MHz)
    i2c_open_struct.ucbrx = 30;                             //Prescaler for Selected Clock.
                                                            //(100kHz)
    //This sets up the I2C driver to operate with the
    //correct settings.
    //EUSCI_B0 uses P1.7 as SCL and P1.6 as SDA
    i2c_open(EUSCI_B0, &i2c_open_struct);

	oled_begin();
	oled_clear();
	//config_piezo_pin();
	config_LIS3MDL();

	while(true){
	    Actions();
	}
}
