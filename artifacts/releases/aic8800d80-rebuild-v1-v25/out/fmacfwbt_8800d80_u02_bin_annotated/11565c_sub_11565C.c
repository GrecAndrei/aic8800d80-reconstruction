// fwstruct annotate: 11565c_sub_11565C.c
// sub_11565C @ 0x11565c, size 230 bytes
// Doc: patch_apply_n1d8 [patch]: Apply firmware patch table entry by index
// patch_apply_n1d8 [patch]: Apply firmware patch table entry by index
int sub_11565C()
{
  int v0; // r4
  _DWORD *v1; // r3
  _DWORD *v2; // r2
  _DWORD *v3; // r3
  _DWORD *v4; // r3
  int v6; // r1
  int v7; // r1
  _DWORD *v8; // r2

  if ( **(_BYTE **)patch_xor_apply_loop == 2 )
  {
    if ( rf_bus_reset_short() )
      v0 = *((_DWORD *)patch_apply_n27c_5764 + 87);
    else
      v0 = 16;
    rf_bus_reset_844();
    *((_DWORD *)off_115750 + 34) = 1;
    __dsb(0xFu);
    __isb(0xFu);
    sub_12ECB0(dword_115758, v6, 1);
    v8 = patch_apply_n274;
    *((_DWORD *)patch_apply_n274 + 513) |= 2u;
    v8[4] |= 1u;
    while ( (v8[4] & 1) != 0 )
      ;
    sub_12ECB0(patch_apply_n278, v7, v8);
  }
  else
  {
    v0 = 16;
  }
  v1 = patch_apply_n260;
  if ( (*((_DWORD *)patch_apply_n260 + 74) & 0x80) != 0 )
  {
    v2 = patch_apply_n264;
    *((_DWORD *)patch_apply_n260 + 74) = 128;
    if ( (v2[1] & 0x20000) != 0 )
    {
      v1[65] = 2;
      v2[1] &= ~0x20000u;
      v2[1] |= 0x40000u;
    }
  }
  v3 = patch_apply_n264;
  if ( (*((_DWORD *)patch_apply_n264 + 2) & 0x20000) != 0 )
  {
    *((_DWORD *)patch_apply_n260 + 65) = 8;
    v3[2] &= ~0x20000u;
    v3[2] |= 0x40000u;
  }
  v4 = off_115750;
  *((_DWORD *)off_115750 + 34) = 2;
  __dsb(0xFu);
  __isb(0xFu);
  v4[34] = 1;
  __dsb(0xFu);
  __isb(0xFu);
  nvic_irq_enable_8000();
  if ( *(_BYTE *)(*(_DWORD *)patch_apply_5754 + 3) )
    rf_bus_write2_n482();
  __disable_irq();
  return v0;
}

