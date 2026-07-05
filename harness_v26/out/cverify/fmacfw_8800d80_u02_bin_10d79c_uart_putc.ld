PROVIDE(off_10D7AC = 0x0010d7ac);
PROVIDE(off_10D7B0 = 0x0010d7b0);
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
