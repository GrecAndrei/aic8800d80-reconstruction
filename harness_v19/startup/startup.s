@ AIC8800D80 startup — Thumb-2
@ Host loader writes firmware to 0x100000, then
@ branches here. We set up stack, zero BSS, copy data, then call start().
    .syntax unified
    .arch armv7-r
    .thumb

    .section .startup, "x", %progbits

    .global Reset_Handler
    .type Reset_Handler, %function
Reset_Handler:
    @ Set stack pointer to top of firmware RAM
    ldr sp, =_estack

    @ Clear BSS
    ldr r0, =_sbss
    ldr r1, =_ebss
    movs r2, #0
0:  cmp r0, r1
    bcs 1f
    str r2, [r0], #4
    b 0b

1:  @ Call C entry point: int start(int, int, uint32_t*)
    movs r0, #0
    movs r1, #0
    mov r2, sp
    bl start

    @ If start returns, loop forever
    b .

    .size Reset_Handler, .-Reset_Handler
