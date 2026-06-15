// sub_1119C0 @ 0x1119c0, size 162 bytes
// Doc: rf_bus_write_n98 [rf]: Writes data word to RF bus
// rf_bus_write_n98 [rf]: Writes data word to RF bus
int *__fastcall sub_1119C0(int a1, int a2, int a3)
{
  _DWORD *v3; // r6
  int *v4; // r5
  int v5; // r7
  _DWORD *v6; // r4

  if ( a1 )
  {
    v3 = (_DWORD *)(rf_bus_write_na4 + 32 * (a1 - 1) + 8);
    v4 = (int *)(rf_bus_write_na4 + 32 * (a1 - 1));
  }
  else
  {
    v3 = (_DWORD *)dword_111A70;
    v4 = (int *)dword_111A74;
  }
  v5 = *v4;
  if ( (*v4 & 0x80008000) != 0 && ((rf_bus_setup_n_2f0 & v5) != 0x20000 || a2 != 0x8000000 || a3) )
  {
    v6 = rf_bus_write2_n_c;
    *((_DWORD *)rf_bus_write2_n_c + 513) |= 0x200u;
    while ( (v6[5] & 0x80) == 0 )
      ;
    *v4 |= a2 | 0x8008000;
    if ( a3 )
      *v4 &= ~a3;
    if ( !a1 )
      goto rf_msg_handler_n_26d;
    if ( v5 < 0 )
    {
      *v3 = 2;
      *v4 |= 0x40000000u;
      while ( (*v3 & 2) == 0 )
        ;
      if ( (v5 & 0x8000) != 0 )
        goto rf_msg_handler_n_26d;
    }
    else if ( (v5 & 0x8000) != 0 )
    {
rf_msg_handler_n_26d:
      *((_DWORD *)rf_bus_write2_n_c + 513) |= 0x400u;
      return sub_1117C8(a1);
    }
    *v4 &= ~0x8000u;
    goto rf_msg_handler_n_26d;
  }
  return sub_1117C8(a1);
}

