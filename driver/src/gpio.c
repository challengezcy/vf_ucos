#include "gpio.h"

void test_gpio()
{
	  GPIO_A->srcctrl = 0x0;
	  GPIO_A->ddr = 0xffff;	    
}
