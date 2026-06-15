// v23 annotated: sub_11E100 @ 0x11e100
// Original: 11e100_sub_11E100.c
// Primary struct: <unclustered>
//
// sub_11E100 @ 0x11e100, size 188 bytes
// Doc: sub_121E100 [unknown]: Small helper reading halfword from offset 0x30
// sub_121E100 [unknown]: Small helper reading halfword from offset 0x30
int __fastcall sub_11E100(int a1)
{
  int v1; // r4
  int v2; // r3
  int v3; // r2
  int v4; // r3
  unsigned int v5; // r3
  _DWORD *v6; // r1
  int v7; // r2
  bool v8; // cf
  unsigned int v9; // r2
  int v11; // r1
  int v12; // r0
  int v13; // r2
  int v14; // [sp+4h] [bp-4h]
  int v15; // [sp+4h] [bp-4h]

  if ( *(_WORD *)(a1 + 48) )
  {
    v1 = *(_DWORD *)(a1 + 28);
    v2 = **(__int16 **)off_11E1BC;
    if ( v2 < 0 && !v1 )
    {
      v11 = dword_11E1C4;
      v12 = dword_11E1CC;
      v13 = 393;
      return fmac_phy_op_handler(v12, v11, v13, v2);
    }
    v3 = *(_DWORD *)(a1 + 84);
    v4 = **(_WORD **)(v1 + 8) & 0xFC;
    *(_DWORD *)(a1 + 84) = v3 & 0xFEFFFFFF;
    if ( v4 == 36 )
    {
      if ( (v3 & 0x2000) != 0 )
      {
        v14 = a1;
        rf_bus_reset_n_1d2(a1);
        a1 = v14;
      }
    }
    else if ( v4 == 148 && (~v3 & 0x2002) == 0 )
    {
      v15 = a1;
      fw_state_check_init(a1, v3 & 0xFEFFFFFF, v3, 0);
      a1 = v15;
    }
    v5 = (*(_DWORD *)(v1 + 12) & 0xFFFFFFFC) + 4;
  }
  else
  {
    if ( **(__int16 **)off_11E1BC < 0 )
    {
      v2 = *(_DWORD *)(a1 + 28);
      if ( v2 )
      {
        v11 = dword_11E1C4;
        v12 = dword_11E1C8;
        v13 = 436;
        return fmac_phy_op_handler(v12, v11, v13, v2);
      }
    }
    v5 = a1 + 160;
  }
  v6 = off_11E1C0;
  v7 = *((_DWORD *)off_11E1C0 + 5);
  if ( *((_DWORD *)off_11E1C0 + 4) == v5 )
    v5 = *((_DWORD *)off_11E1C0 + 3);
  *(_DWORD *)(a1 + 152) = v5;
  v8 = v5 >= (v7 & 0x7FFFFFFFu);
  v9 = v7 & 0x80000000;
  if ( !v8 )
    v9 += 0x80000000;
  v6[5] = v5 | v9;
  return sub_11E0B4(a1);
}

