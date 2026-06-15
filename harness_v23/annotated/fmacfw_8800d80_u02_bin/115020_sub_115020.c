// v23 annotated: sub_115020 @ 0x115020
// Original: 115020_sub_115020.c
// Primary struct: <unclustered>
//
// sub_115020 @ 0x115020, size 230 bytes
int sub_115020()
{
  int v0; // r4
  _DWORD *v1; // r3
  _DWORD *v2; // r2
  _DWORD *v3; // r3
  _DWORD *v4; // r3
  int v6; // r1
  int v7; // r1
  _DWORD *v8; // r2

  if ( **(_BYTE **)off_115108 == 2 )
  {
    if ( sub_112C9C() )
      v0 = *((_DWORD *)off_115128 + 87);
    else
      v0 = 16;
    sub_1129E8();
    *((_DWORD *)off_115114 + 34) = 1;
    __dsb(0xFu);
    __isb(0xFu);
    sub_12EA88(dword_11511C, v6, 1);
    v8 = off_115120;
    *((_DWORD *)off_115120 + 513) |= 2u;
    v8[4] |= 1u;
    while ( (v8[4] & 1) != 0 )
      ;
    sub_12EA88(dword_115124, v7, v8);
  }
  else
  {
    v0 = 16;
  }
  v1 = off_11510C;
  if ( (*((_DWORD *)off_11510C + 74) & 0x80) != 0 )
  {
    v2 = off_115110;
    *((_DWORD *)off_11510C + 74) = 128;
    if ( (v2[1] & 0x20000) != 0 )
    {
      v1[65] = 2;
      v2[1] &= ~0x20000u;
      v2[1] |= 0x40000u;
    }
  }
  v3 = off_115110;
  if ( (*((_DWORD *)off_115110 + 2) & 0x20000) != 0 )
  {
    *((_DWORD *)off_11510C + 65) = 8;
    v3[2] &= ~0x20000u;
    v3[2] |= 0x40000u;
  }
  v4 = off_115114;
  *((_DWORD *)off_115114 + 34) = 2;
  __dsb(0xFu);
  __isb(0xFu);
  v4[34] = 1;
  __dsb(0xFu);
  __isb(0xFu);
  sub_10D784();
  if ( *(_BYTE *)(*(_DWORD *)off_115118 + 3) )
    sub_1146F0();
  __disable_irq();
  return v0;
}

