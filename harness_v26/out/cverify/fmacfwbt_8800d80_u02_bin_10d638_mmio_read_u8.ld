PROVIDE(off_10D648 = 0x0010d648);
PROVIDE(off_10D64C = 0x0010d64c);
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
