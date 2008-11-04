#ifndef __OS_CPU_H__
#define __OS_CPU_H__
/*
#ifdef  OS_CPU_GLOBALS
#define OS_CPU_EXT
#else
#define OS_CPU_EXT  extern
#endif
*/
#include "os_cfg_r.h"
/* data type */
typedef unsigned char 	BOOLEAN;
typedef unsigned char 	INT8U;
typedef signed char   	INT8S;
typedef unsigned short 	INT16U;
typedef signed short 	INT16S;
typedef unsigned int	INT32U;
typedef signed int	INT32S;

typedef unsigned int 	OS_STK; 

#define OS_ENTER_CRITICAL()  _disable()
#define OS_EXIT_CRITICAL()  _enable()

#define OS_STK_GROWTH		1


#define OS_TASK_SW() OSCtxSw()

#define OS_TASK_TMR_PRIO 	52

//defined by paul.zhang 2008.09.30
#define INITTASKSTKP	0xA1000000   //0xa phase 32M tail
#define TASKSTKSIZE		0x1000		//4K
//private of arc process
#define	VECTORBASE		0xa0000000
/* auxiliary register for timer0*/
#define REG_TIMER0_COUNT   	(0x21)     /*Initial Timer Count Value*/
#define REG_TIMER0_CONTROL  (0x22)     /*Timer Operating Mode*/
#define REG_TIMER0_LIMIT    (0x23)     /*Counting Limit Value*/

#define get_arc_aux(aux_reg) \
   (INT32U)_lr((unsigned)(aux_reg))

#define set_arc_aux(aux_reg,value) \
   _sr((unsigned)(value),(unsigned)(aux_reg))
#endif
