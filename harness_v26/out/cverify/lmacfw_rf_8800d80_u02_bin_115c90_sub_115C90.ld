PROVIDE(dword_115CA0 = 0x00115ca0);
PROVIDE(off_115C9C = 0x00115c9c);
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
