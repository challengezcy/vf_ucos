#include "sys.h"

void init_sys()
{
	SYSCTRL->pll_cfg = 0x010a6a0a;
	delay(5, 100);
	SYSCTRL->clk_cfg = 0x20;

	SYSCTRL->clk_ctl = 0x1d;

	_sr(0x1, 0x48);	//0xc2
	_sr(0x2, 0x11);
}
