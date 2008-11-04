	.text
	.extern main
	.global _start
	.type	_start, @function
_start:
	mov r0, 0
	mov r1, 0

	mov	sp, _estack	
	bl main

	.global 	OSStartHighRdy
OSStartHighRdy:
	mov r0, OSTCBHighRdy
	ld r1, [r0]
	ld sp, [r1]
	pop r0
	pop r1
	pop r2
	pop r3
	pop r4
	pop r5
	pop r6
	pop r7	
	pop r8
	pop r9
	pop r10
	pop r11
	pop r12
	pop r13
	pop r14
	pop r15	
	pop r16
	pop r17
	pop r18
	pop r19
	pop r20
	pop r21
	pop r22
	pop r23	
	pop r24
	pop r25
	
	pop gp
	pop fp

	pop blink

	j  [blink]	
	nop

	
	.global 	OSCtxSw
OSCtxSw:
	push blink

	push fp
	push gp
	
	push r25
	push r24
	push r23
	push r22
	push r21
	push r20
	push r19
	push r18
	push r17
	push r16
	push r15
	push r14
	push r13
	push r12
	push r11
	push r10
	push r9
	push r8
	push r7
	push r6
	push r5
	push r4
	push r3
	push r2
	push r1
	push r0
	mov r0, OSTCBCur
	ld r1, [r0]
	st sp, [r1]	
	
	mov r0, OSTCBHighRdy
	ld  r1, [r0]
	mov r0, OSTCBCur
	st  r1, [r0]
	mov r0, OSPrioHighRdy
	ld  r1, [r0]
	mov  r0, OSPrioCur
	st  r1, [r0]
	
	b OSStartHighRdy

	.end
