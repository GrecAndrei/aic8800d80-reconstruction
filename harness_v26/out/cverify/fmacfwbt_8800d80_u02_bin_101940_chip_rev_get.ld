PROVIDE(off_101950 = 0x00101950);
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
