// v23 annotated: sub_123358 @ 0x123358
// Original: 123358_sub_123358.c
// Primary struct: <unclustered>
//
// sub_123358 @ 0x123358, size 50 bytes
void sub_123358()
{
  _DWORD *v0; // r4
  unsigned int v1; // r0

  v0 = off_12338C;
  while ( (*v0 & 1) == 0 )
  {
    if ( (*v0 & 0xF) == 4 )
    {
      v1 = sub_10D680();
      if ( rf_init_or_reset(v1) > 0 )
      {
        if ( *(_BYTE *)off_123390 )
          sub_123240();
        return;
      }
    }
  }
}

