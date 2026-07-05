PROVIDE(off_115D5C = 0x00115d5c);
PROVIDE(off_115D60 = 0x00115d60);
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
