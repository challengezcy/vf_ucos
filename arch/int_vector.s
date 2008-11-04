.section  ".vect",text

	.global     _reset 
	.extern     OSTickISR
_reset:         JAL _start	;vector 0
.align 8
mem_ex: 		JAL mem_ex_handler	;vector 1 
.align 8
ins_err:		JAL ins_err_handler 	;vector 2
.align 8
ivect3: 		JAL OSTickISR 		; (Ilink1) ARC timer to drive uc/OS-II	
.align 8
ivect4: 		JAL vector4_handler	;vector 4, ilink1
.align 8
ivect5: 		JAL vector3_handler 		; (Ilink1) ARC timer to drive uc/OS-II	
.align 8
ivect6: 		JAL vector3_handler 		; (Ilink1) ARC timer to drive uc/OS-II	
mem_ex_handler:			;vector 1, system interrupt no return
   flag 1
   nop
   nop
   nop
ins_err_handler:		;vector 2, system interrupt no return
   flag 1
   nop
   nop
   nop
vector3_handler:		;vector , ilink1
   flag 1
   nop
   nop
   nop
vector4_handler:		;vector , ilink1
   flag 1
   nop
   nop
   nop
vector5_handler:		;vector , ilink1
   flag 1
   nop
   nop
   nop
