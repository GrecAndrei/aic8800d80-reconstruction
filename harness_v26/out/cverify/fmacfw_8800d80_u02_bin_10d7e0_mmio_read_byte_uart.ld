PROVIDE(off_10D7F0 = 0x0010d7f0);
PROVIDE(off_10D7F4 = 0x0010d7f4);
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
