#include "msp.h"
#include "Actions.h"
#include "oled.h"

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	oled_begin();
	config_piezo_pin();
	while(true){
	    Actions();
	}
}
