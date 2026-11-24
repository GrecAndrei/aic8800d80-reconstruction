// sub_114EE0 @ 0x114ee0, size 230 bytes
int sub_114EE0()
{
  int v0; // r4
  _DWORD *v1; // r3
  _DWORD *v2; // r2
  _DWORD *v3; // r3
  _DWORD *v4; // r3
  int v6; // r1
  int v7; // r1
  _DWORD *v8; // r2

  if ( **(_BYTE **)off_114FC8 == 2 )
  {
    if ( sub_112B5C() )
      v0 = *((_DWORD *)off_114FE8 + 87);
    else
      v0 = 16;
    sub_1128A8();
    *((_DWORD *)off_114FD4 + 34) = 1;
    __dsb(0xFu);
    __isb(0xFu);
    sub_12E948(dword_114FDC, v6, 1);
    v8 = off_114FE0;
    *((_DWORD *)off_114FE0 + 513) |= 2u;
    *(_DWORD *)(v8 + 0x10) |= 1u;
    while ( (*(_DWORD *)(v8 + 0x10) & 1) != 0 )
      ;
    sub_12E948(dword_114FE4, v7, v8);
  }
  else
  {
    v0 = 16;
  }
  v1 = off_114FCC;
  if ( (*((_DWORD *)off_114FCC + 74) & 0x80) != 0 )
  {
    v2 = off_114FD0;
    *((_DWORD *)off_114FCC + 74) = 128;
    if ( (*(_DWORD *)(v2 + 0x4) & 0x20000) != 0 )
    {
      *(_DWORD *)(v1 + 0x104) = 2;
      *(_DWORD *)(v2 + 0x4) &= ~0x20000u;
      *(_DWORD *)(v2 + 0x4) |= 0x40000u;
    }
  }
  v3 = off_114FD0;
  if ( (*((_DWORD *)off_114FD0 + 2) & 0x20000) != 0 )
  {
    *((_DWORD *)off_114FCC + 65) = 8;
    *(_DWORD *)(v3 + 0x8) &= ~0x20000u;
    *(_DWORD *)(v3 + 0x8) |= 0x40000u;
  }
  v4 = off_114FD4;
  *((_DWORD *)off_114FD4 + 34) = 2;
  __dsb(0xFu);
  __isb(0xFu);
  *(_DWORD *)(v4 + 0x88) = 1;
  __dsb(0xFu);
  __isb(0xFu);
  sub_10D644();
  if ( *(_BYTE *)(*(_DWORD *)off_114FD8 + 3) )
    sub_1145B0();
  __disable_irq();
  return v0;
}

