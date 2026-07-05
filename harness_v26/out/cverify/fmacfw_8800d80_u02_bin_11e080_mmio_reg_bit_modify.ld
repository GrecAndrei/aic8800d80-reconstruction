PROVIDE(off_11E0AC = 0x0011e0ac);
PROVIDE(off_11E0B0 = 0x0011e0b0);
SECTIONS
{
  . = 0;
  .text : ALIGN(2)
  {
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
