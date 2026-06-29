// fwstruct annotate: 114b5c_rf_mode_check.c
// rf_mode_check @ 0x114b5c, size 230 bytes
// Doc: rf_mode_check [rf]: Check current RF mode/state byte
// rf_mode_check [rf]: Check current RF mode/state byte
int rf_mode_check()
{
  int v0; // r4
  _DWORD *v1; // r3
  _DWORD *v2; // r2
  _DWORD *v3; // r3
  _DWORD *v4; // r3
  int v6; // r1
  int v7; // r1
  _DWORD *v8; // r2

  if ( **(_BYTE **)off_114C44 == 2 )
  {
    if ( rf_bus_reset_n2b4() )
      v0 = *((_DWORD *)off_114C64 + 87);
    else
      v0 = 16;
    sub_1122F0();
    *((_DWORD *)off_114C50 + 34) = 1;
    __dsb(0xFu);
    __isb(0xFu);
    msg_parse(dword_114C58, v6);
    v8 = off_114C5C;
    *((_DWORD *)off_114C5C + 513) |= 2u;
    v8[4] |= 1u;
    while ( (v8[4] & 1) != 0 )
      ;
    msg_parse(dword_114C60, v7);
  }
  else
  {
    v0 = 16;
  }
  v1 = off_114C48;
  if ( (*((_DWORD *)off_114C48 + 74) & 0x80) != 0 )
  {
    v2 = off_114C4C;
    *((_DWORD *)off_114C48 + 74) = 128;
    if ( (v2[1] & 0x20000) != 0 )
    {
      v1[65] = 2;
      v2[1] &= ~0x20000u;
      v2[1] |= 0x40000u;
    }
  }
  v3 = off_114C4C;
  if ( (*((_DWORD *)off_114C4C + 2) & 0x20000) != 0 )
  {
    *((_DWORD *)off_114C48 + 65) = 8;
    v3[2] &= ~0x20000u;
    v3[2] |= 0x40000u;
  }
  v4 = off_114C50;
  *((_DWORD *)off_114C50 + 34) = 2;
  __dsb(0xFu);
  __isb(0xFu);
  v4[34] = 1;
  __dsb(0xFu);
  __isb(0xFu);
  nvic_irq_enable();
  if ( *(_BYTE *)(*(_DWORD *)off_114C54 + 3) )
    sub_1138F4();
  __disable_irq();
  return v0;
}

