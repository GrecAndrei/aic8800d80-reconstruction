// sub_130148 @ 0x130148, size 50 bytes
void sub_130148()
{
  _DWORD *v0; // r4
  unsigned int v1; // r0

  v0 = off_13017C;
  while ( (*v0 & 1) == 0 )
  {
    if ( (*v0 & 0xF) == 4 )
    {
      v1 = sub_10D6A0();
      if ( sub_12FED8(v1) > 0 )
      {
        if ( *(_BYTE *)off_130180 )
          sub_130030();
        return;
      }
    }
  }
}

