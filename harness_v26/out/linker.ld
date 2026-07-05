ENTRY(start)
PROVIDE(off_1006D4 = 0x001006d4);
PROVIDE(off_101884 = 0x00101884);
PROVIDE(off_101950 = 0x00101950);
PROVIDE(off_101A98 = 0x00101a98);
PROVIDE(off_101AC0 = 0x00101ac0);
PROVIDE(off_1029F4 = 0x001029f4);
PROVIDE(off_10D7AC = 0x0010d7ac);
PROVIDE(off_10D7B0 = 0x0010d7b0);
PROVIDE(off_11769C = 0x0011769c);
PROVIDE(off_12EA4C = 0x0012ea4c);
SECTIONS
{
  . = 0x100;
  .text : ALIGN(2)
  {
    KEEP(*(.text.v26))
    *(.text*)
    *(.rodata*)
  }
  /DISCARD/ :
  {
    *(.comment)
    *(.ARM.attributes)
    *(.note*)
  }
}
