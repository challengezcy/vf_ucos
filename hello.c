#include "ucos_ii.h"
#include "gpio.h"

#define OS_TASK_MAIN_STK_SIZE    128    /* Timer      task stack size (# of OS_STK wide entries)        */
#define OS_TASK_FIRST_STK_SIZE   128    /* Statistics task stack size (# of OS_STK wide entries)        */
#define OS_TASK_SECOND_STK_SIZE   128    /* Idle       task stack size (# of OS_STK wide entries)      */
OS_STK            OSTaskMainStk[OS_TASK_MAIN_STK_SIZE];      /* Idle task stack                */
OS_STK            OSTaskFirstStk[OS_TASK_FIRST_STK_SIZE];      /* Idle task stack                */
OS_STK            OSTaskSecondStk[OS_TASK_SECOND_STK_SIZE];      /* Idle task stack                */
#define OS_TASK_MAIN_PRIO		48
#define OS_TASK_FIRST_PRIO		49
#define OS_TASK_SECOND_PRIO	50
#define  OS_TASK_MAIN_ID          	65525u                /* ID numbers for Idle, Stat and Timer tasks   */
#define  OS_TASK_FIRST_ID          	65524u
#define  OS_TASK_SECOND_ID        65523u

void main_task(void * arg)
{
	int flag = 0;
	test_gpio();
	for(;;){
		if(flag == 0){
			GPIO_A->dr |= (0x1);
			flag = 1;
			OSTimeDly(2);
		}else{
			GPIO_A->dr &= ~(0x1);		
			flag = 0;		
			OSTimeDly(2);
		}



	}
}

void first_task(void * arg)
{
	int flag = 0;
	for(;;){
		if(flag == 0){
			GPIO_A->dr |= (0x2);
			flag = 1;
			OSTimeDly(4);			
		}else{
			GPIO_A->dr &= ~(0x2);			
			flag = 0;		
			OSTimeDly(4);
		}
	}
}

void second_task(void * arg)
{
	int flag = 0;
	for(;;)
		if(flag == 0){
			GPIO_A->dr |= (0x4);
			flag = 1;
			OSTimeDly(6);			
		}else{
			GPIO_A->dr &= ~(0x4);			
			flag = 0;		
			OSTimeDly(6);
		}
}

void third_task(void * arg)
{
	for(;;)
		OSTimeDly(1000);
}

int main(int argc, char **argv)
{	
	init_sys();
	OS_ENTER_CRITICAL();
	OSInit();
       (void)OSTaskCreateExt(main_task,
                          (void *)0,                                 /* No arguments passed to OS_TaskIdle() */
                          &OSTaskMainStk[OS_TASK_MAIN_STK_SIZE - 1], /* Set Top-Of-Stack                     */
                          OS_TASK_MAIN_PRIO,                         /* Lowest priority level                */
                          OS_TASK_MAIN_ID,
                          &OSTaskMainStk[0],                         /* Set Bottom-Of-Stack                  */
                          OS_TASK_MAIN_STK_SIZE,
                          (void *)0,                                 /* No TCB extension                     */
                          OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);/* Enable stack checking + clear stack  */	
      (void)OSTaskCreateExt(first_task,
                          (void *)0,                                 /* No arguments passed to OS_TaskIdle() */
                          &OSTaskFirstStk[OS_TASK_FIRST_STK_SIZE - 1], /* Set Top-Of-Stack                     */
                          OS_TASK_FIRST_PRIO,                         /* Lowest priority level                */
                          OS_TASK_FIRST_ID,
                          &OSTaskFirstStk[0],                         /* Set Bottom-Of-Stack                  */
                          OS_TASK_FIRST_STK_SIZE,
                          (void *)0,                                 /* No TCB extension                     */
                          OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);/* Enable stack checking + clear stack  */	 	
   (void)OSTaskCreateExt(second_task,
                          (void *)0,                                 /* No arguments passed to OS_TaskIdle() */
                          &OSTaskSecondStk[OS_TASK_SECOND_STK_SIZE - 1], /* Set Top-Of-Stack                     */
                          OS_TASK_SECOND_PRIO,                         /* Lowest priority level                */
                          OS_TASK_SECOND_ID,
                          &OSTaskSecondStk[0],                         /* Set Bottom-Of-Stack                  */
                          OS_TASK_SECOND_STK_SIZE,
                          (void *)0,                                 /* No TCB extension                     */
                          OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);/* Enable stack checking + clear stack  */	 	
	//OSTaskCreateExt(main_task, (void *)0, (OS_STK *)(0xA2000000), 50);
	//OSTaskCreate(first_task, (void *)0, (OS_STK *)(0xA2000000 - TASKSTKSIZE), 49);
	//OSTaskCreate(second_task, (void *)0, (OS_STK *)(0xA2000000 -2*TASKSTKSIZE), 48);
	//OSTaskCreate(third_task, (void *)0, (OS_STK *)(0xA2000000 - 3*TASKSTKSIZE), 47);	
	TickInit();
	OS_EXIT_CRITICAL();	
	OSStart();
	return 0;
}

