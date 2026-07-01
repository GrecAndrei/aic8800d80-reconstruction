/* AIC8800D80 firmware linker script
 * Target: ARM Cortex-R5 (Thumb-2)
 * Loads at chip addr 0x100000 in SRAM
 * MMIO region at 0x40000000 (volatile peripheral space)
 */
ENTRY(Reset_Handler)

MEMORY
{
    RAM (rwx)  : ORIGIN = 0x100000, LENGTH = 0x100000
    MMIO (rw)  : ORIGIN = 0x40000000, LENGTH = 0x20000000
}

_estack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
    .header : {
        KEEP(*(.header))
    } > RAM

    .startup : {
        KEEP(*(.startup))
    } > RAM

    .text : {
        *(.text*)
        *(.rodata*)
    } > RAM

    .data : {
        _sdata = .;
        *(.data*)
        _edata = .;
    } > RAM

    .bss : {
        _sbss = .;
        *(.bss*)
        *(COMMON)
        _ebss = .;
    } > RAM
}
