PROVIDE(off_10D604 = 0x0010d604);
PROVIDE(off_10D608 = 0x0010d608);
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
