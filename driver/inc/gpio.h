#ifndef __GPIO_H__
#define __GPIO_H__

#include "global.h"
#define GPIO_BASE 0x81006000
/* GPIO Register Structures */ 
typedef struct {
    VF_REG dr;      // port A/B data              
    VF_REG ddr;     // port A/B data direction    
    VF_REG srcctrl; // port A/B data source       
}GPIO_REGS_T;    
//GPIO common register structure
typedef struct {
    VF_REG inten;         // interrupt enable         (0x30)
    VF_REG intmask;       // interrupt mask           (0x34)
    VF_REG inttype_level; // interrupt level          (0x38)
    VF_REG int_polarity;  // interrupt polarity       (0x3c)
    VF_REG intstatus;     // port A irq status        (0x40)
    VF_REG rawintstatus;  // port A raw irq status    (0x44)
    VF_REG debounce;      // debounce enable          (0x48)
    VF_REG porta_eoi;     // port A interrupt clear   (0x4c)
    VF_REG ext_porta;     // port A external port     (0x50)
    VF_REG ext_portb;     // port B external port     (0x54)
    VF_REG ext_portc;     // port C external port     (0x58)
    VF_REG ext_portd;     // port D external port     (0x5c)
    VF_REG ls_sync;       // level-sensitive          (0x60)
                          // synchronization enable
    VF_REG id_code;       // user-specified ID code   (0x64)
    VF_REG reserved1;     // reserved                 (0x68)
    VF_REG old_comp_version; // component version     (0x6c)
    VF_REG reserved2[32]; // reserved          (0x70 - 0xec)
    VF_REG comp_params_2; // component parameters 2   (0xf0)
    VF_REG comp_params_1; // component parameters 1   (0xf4)
    VF_REG comp_version;  // component version        (0xf8)
    VF_REG comp_type;     // component type           (0xfc)
}GPIO_CMN_REGS_T;


/*
 * The names and usage of the bit fields in these registers is
 * implementation specific, so no bit field constants are defined.
 */ 

/* Macro pointing to GPIO A registers */
#define GPIO_A   ((GPIO_REGS_T *)(GPIO_BASE))
/* Macro pointing to GPIO B registers */
#define GPIO_B   ((GPIO_REGS_T *)(GPIO_BASE+0x0c))
/* Macro pointing to GPIO C registers */
#define GPIO_C   ((GPIO_REGS_T *)(GPIO_BASE+0x18))
/* Macro pointing to GPIO D registers */
#define GPIO_D   ((GPIO_REGS_T *)(GPIO_BASE+0x24))
/* Macro pointing to GPIO common registers */
#define GPIO_CMN ((GPIO_CMN_REGS_T *)(GPIO_BASE+0x030))
#endif
