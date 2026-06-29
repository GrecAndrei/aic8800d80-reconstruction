// fwstruct annotate: 130288_sub_130288.c
// sub_130288 @ 0x130288, size 50 bytes
void sub_130288()
{
  _DWORD *v0; // r4
  unsigned int byte_uart; // r0

  v0 = off_1302BC;
  while ( (*v0 & 1) == 0 )
  {
    if ( (*v0 & 0xF) == 4 )
    {
      byte_uart = mmio_read_byte_uart();
      if ( sub_130018(byte_uart) > 0 )
      {
        if ( *(_BYTE *)off_1302C0 )
          sub_130170();
        return;
      }
    }
  }
}

