// sub_10DC78 @ 0x10dc78, size 18 bytes
int sub_10DC78()
{
  if ( *((_BYTE *)off_10DC8C + 369) )
    return irq_enable(1);
  else
    return sub_10DB6C(1);
}

