#ifndef __SYS_H__
#define __SYS_H__
#include "global.h"

#define SYSCTRL_BASE	0x80009000

typedef struct 
{  	             
 VF_REG rst_ctl; //0x0
 VF_REG pll_cfg;//0x4
 VF_REG clk_cfg;//0x8
 VF_REG chip_status;//0xc
 VF_REG device_cfg;//0x10
 VF_REG clk_ctl;//0x14
 VF_REG pwr_ctl;//0x18
 VF_REG int_ctl0;//0x1c
 VF_REG int_ctl1;//0x20
 VF_REG int_clr;//0x24
 VF_REG ext_int_ctl;//0x28
 VF_REG int_msk;//0x2c
} SYSCTRL_REGS_T;

/* Macro pointing to System control registers */
#define SYSCTRL   ((SYSCTRL_REGS_T *)(SYSCTRL_BASE))

void init_sys();
#endif
