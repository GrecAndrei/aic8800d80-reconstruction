// v23 annotated: sub_1304A4 @ 0x1304a4
// Original: 1304a4_sub_1304A4.c
// Primary struct: <unclustered>
//
// sub_1304A4 @ 0x1304a4, size 50 bytes
void sub_1304A4()
{
  _DWORD *v0; // r4
  unsigned int u8; // r0

  v0 = off_1304D8;
  while ( (*v0 & 1) == 0 )
  {
    if ( (*v0 & 0xF) == 4 )
    {
      u8 = mmio_read_u8();
      if ( sub_130234(u8) > 0 )
      {
        if ( *(_BYTE *)off_1304DC )
          sub_13038C();
        return;
      }
    }
  }
}

