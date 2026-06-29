// fwstruct annotate: 1267a8_bt_rf_calibrate_or_setup.c
// bt_rf_calibrate_or_setup @ 0x1267a8, size 378 bytes
// Doc: bt_rf_calibrate_or_setup [bt]: BT-side RF calibration/setup routine using MMIO table
// bt_rf_calibrate_or_setup [bt]: BT-side RF calibration/setup routine using MMIO table
int __fastcall bt_rf_calibrate_or_setup(int a1, int a2, int a3)
{
  _DWORD *v3; // r10
  int v4; // r5
  int v7; // r11
  int v8; // r8
  int v9; // r3
  int v10; // r0
  int v11; // r4
  int v12; // r8
  int v13; // r3
  int result; // r0
  _DWORD *v15; // r9
  int v16; // r4
  int v17; // r4
  unsigned int v18; // r4
  int v19; // r3
  bool v20; // zf
  int v21; // r3
  int v22; // r4
  int v23; // [sp+4h] [bp-8h]

  v3 = off_126934;
  v23 = a3;
  v4 = dword_126924;
  v7 = a1 + 76;
  if ( !a3 )
    goto LABEL_30;
  while ( 1 )
  {
    v8 = *(_DWORD *)(a1 + 72);
    if ( !v3[8] )
      break;
    v15 = (_DWORD *)v3[9];
    v16 = v15[1];
    v17 = v16 + 4000 + sub_10186C();
    if ( v8 != v15[2] )
    {
      v17 += 4000 + sub_10186C();
      if ( v15[3] )
        v17 += 10000;
    }
    v18 = (unsigned int)(a2 - v17) >> 31;
LABEL_18:
    if ( !v18 )
      goto LABEL_5;
    v11 = 0;
LABEL_20:
    if ( *(_BYTE *)(a1 + 1224) && *(_BYTE *)(dword_12692C + 140 * *(unsigned __int8 *)(a1 + 1225) + 112) == 1 )
      rf_bus_reset_n19a_6698(a1, a2, v11);
    v19 = *(unsigned __int8 *)(a1 + 106);
    if ( *(_BYTE *)(a1 + 106) )
    {
      v20 = v19 == 2;
      if ( v19 == 2 )
        v21 = *(unsigned __int16 *)(a1 + 222);
      else
        v21 = 102400;
      if ( v20 )
        v21 <<= 10;
    }
    else
    {
      v21 = *(_DWORD *)(dword_126930 + 696 * *(unsigned __int8 *)(a1 + 116) + 8);
    }
    a2 += v21;
    if ( !++v23 )
    {
LABEL_30:
      if ( (*(_BYTE *)(a1 + 85) & 1) != 0 )
      {
        list_remove_node_d510(dword_126928, v7);
        *(_BYTE *)(a1 + 85) &= ~1u;
      }
    }
  }
  v9 = v3[20];
  if ( v9 && v8 != v9 )
  {
    v22 = v3[21];
    v18 = (unsigned int)(a2 - v22 - 4000 - sub_10186C()) >> 31;
    goto LABEL_18;
  }
LABEL_5:
  *(_DWORD *)(a1 + 80) = a2;
  v10 = sub_10186C();
  v11 = v3[4];
  v12 = a2 + 13999 + v10;
  if ( v11 )
  {
    while ( 1 )
    {
      v13 = *(_DWORD *)(v11 + 4);
      if ( v12 - v13 < 0 )
        break;
      if ( *(_DWORD *)(v4 + 1320 * *(unsigned __int8 *)(a1 + 84) + 72) != *(_DWORD *)(v4
                                                                                    + 1320
                                                                                    * *(unsigned __int8 *)(v11 + 8)
                                                                                    + 72) )
      {
        if ( sub_125FEC(v7, v11) )
          goto LABEL_20;
        v13 = *(_DWORD *)(v11 + 4);
      }
      if ( a2 - v13 < 0 )
        break;
      v11 = *(_DWORD *)v11;
      if ( !v11 )
        goto LABEL_33;
    }
  }
  else
  {
LABEL_33:
    v11 = 0;
  }
  result = sub_12D62C(dword_126928, v11, v7);
  *(_BYTE *)(a1 + 85) |= 1u;
  return result;
}

