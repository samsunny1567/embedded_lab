/*
 * peripherals.c
 *
 * Created: 1/10/2024 11:36:25 AM
 *  Author: samsunny
 */ 


#include "headers.h"


void initialize_peripherals()
{
	
	// System resources
	//-------------------

	mcu_init();

	CPUINT_init();

	// CPU clock
	SYSTEMCONFIG.clkCtrl.MCLKCTRLB.PDIV = 0x2 << 1;
	SYSTEMCONFIG.clkCtrl.MCLKCTRLA.CLKSEL = CLKCTRL_CLKSEL_EXTCLK_gc;
	SYSTEMCONFIG.clkCtrl.MCLKCTRLB.PEN = false;
	CLKCTRL_init();

	// SLPCTRL
	SLPCTRL_init();

	// BOD
	BOD_init();
		
		
		
		// Initialize all pins 
		
		instantiatePin(&GPIO_0, PIN_PORTA, 5);
		initializeOutputPin(GPIO_0 , false , PORT_PULL_OFF);
		
		instantiatePin(&GPIO_1, PIN_PORTF, 3);
		initializeOutputPin(GPIO_0 , false , PORT_PULL_OFF);
		
		instantiatePin(&EN , PIN_PORTF, 2);
		initializeOutputPin(EN , false , PORT_PULL_OFF);
		
		instantiatePin(&INT,PIN_PORTA,6);
		initializeInputPin(INT,PORT_PULL_OFF);
		
		instantiatePin(&COM0, PIN_PORTA,4);
		initializeOutputPin(COM0,false,PORT_PULL_OFF);


// Initialize I2C

instantiatePin(&SDA , PIN_PORTA, 2);
initializeOutputPin(SDA , false , PORT_PULL_OFF);

instantiatePin(&SCL , PIN_PORTA , 32);
initializeOutputPin(SCL , false , PORT_PULL_OFF);

instantiateTWI(&TMF_SENSOR,&TWI0,F_CPU,BAUD_RATE);
initializeI2cMaster(&TMF_SENSOR);

}