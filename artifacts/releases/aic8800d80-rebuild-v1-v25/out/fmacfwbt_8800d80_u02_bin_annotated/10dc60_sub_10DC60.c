// fwstruct annotate: 10dc60_sub_10DC60.c
// sub_10DC60 @ 0x10dc60, size 18 bytes
int sub_10DC60()
{
  if ( *((_BYTE *)off_10DC74 + 369) )
    return irq_enable(2);
  else
    return sub_10DB6C(2);
}

