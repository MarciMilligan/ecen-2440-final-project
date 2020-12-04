#include "msp.h"
#include "Actions.h"
#include "oled.h"

/**
 * main.c
 *  
 * Created on 11/23/20
 * Code by Joshua Dinerman
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	oled_begin();
	//config_piezo_pin();
	config_LIS3MDL();
	while(true){
	    Actions();
	}
}
