PROVIDE(off_10D64C = 0x0010d64c);
PROVIDE(off_10D650 = 0x0010d650);
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
