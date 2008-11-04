#include "ucos_ii.h"
#include "os_cpu.h"

void OSIntCtxSw()
{
}

void          OSInitHookBegin         (void)
{
}
void          OSInitHookEnd           (void)
{
}

void          OSTaskCreateHook        (OS_TCB          *ptcb)
{
}

void          OSTaskDelHook           (OS_TCB          *ptcb)
{
}

void          OSTaskIdleHook          (void)
{
}

void          OSTaskStatHook          (void)
{
}

OS_STK       *OSTaskStkInit           (void           (*task)(void *p_arg),
                                       void            *p_arg,
                                       OS_STK          *ptos,
                                       INT16U           opt)
{
	OS_STK *stk;
	INT32U task_addr;

	opt = opt;
	stk = ptos;
	task_addr = (INT32U)task;
	
	*(stk) = (INT32U)task_addr;

	*(--stk) = (INT32U)0x27272727;
	*(--stk) = (INT32U)0x26262626;
	
	*(--stk) = (INT32U)0x25252525;
	*(--stk) = (INT32U)0x24242424;
	*(--stk) = (INT32U)0x23232323;
	*(--stk) = (INT32U)0x22222222;
	*(--stk) = (INT32U)0x21212121;
	
	*(--stk) = (INT32U)0x20202020;
	*(--stk) = (INT32U)0x19191919;
	*(--stk) = (INT32U)0x18181818;
	*(--stk) = (INT32U)0x17171717;
	*(--stk) = (INT32U)0x16161616;
	*(--stk) = (INT32U)0x15151515;
	*(--stk) = (INT32U)0x14141414;
	*(--stk) = (INT32U)0x13131313;
	*(--stk) = (INT32U)0x12121212;	
	*(--stk) = (INT32U)0x11111111;	
	
	*(--stk) = (INT32U)0x10101010;
	*(--stk) = (INT32U)0x09090909;
	*(--stk) = (INT32U)0x08080808;
	*(--stk) = (INT32U)0x07070707;
	*(--stk) = (INT32U)0x06060606;
	*(--stk) = (INT32U)0x05050505;
	*(--stk) = (INT32U)0x04040404;
	*(--stk) = (INT32U)0x03030303;
	*(--stk) = (INT32U)0x02020202;
	*(--stk) = (INT32U)0x01010101;
	*(--stk) = (INT32U)p_arg;	

	return (stk);
	
}


void OSTCBInitHook(OS_TCB          *ptcb)
{
}

void OSTimeTickHook()
{
}

void OSTickISR()
{
	int i;
	//OS_ENTER_CRITICAL();
	
	_sr(0x3,0x22);  //clear interrupt
	OSTimeTick();
	
	OS_Sched();

	//OS_EXIT_CRITICAL();	
}

void TickInit()
{
	OS_ENTER_CRITICAL();

	set_arc_aux(0x25, VECTORBASE);
	    
	_sr(0x0,0x22);
	_sr(0x00ffffff,0x23);
	_sr(0x3,0x22);
	_sr(0,0x21); 


	OS_EXIT_CRITICAL();	
}
