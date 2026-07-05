PROVIDE(off_11EF6C = 0x0011ef6c);
PROVIDE(off_11EF70 = 0x0011ef70);
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
