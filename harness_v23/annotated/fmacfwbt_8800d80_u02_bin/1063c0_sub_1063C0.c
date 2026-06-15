// v23 annotated: sub_1063C0 @ 0x1063c0
// Original: 1063c0_sub_1063C0.c
// Primary struct: <unclustered>
//
// sub_1063C0 @ 0x1063c0, size 124 bytes
// Doc: sub_12063C0 [util]: Init/setup wrapper calling address-table lookup and helper routines
// sub_12063C0 [util]: Init/setup wrapper calling address-table lookup and helper routines
int __fastcall sub_1063C0(int a1, int a2, int a3)
{
  __int64 v5; // r0
  int v6; // r0
  int v7; // r9
  int v8; // r0
  int v9; // r7
  float v10; // r0
  __int64 v11; // kr00_8
  int v12; // r5

  v5 = sub_142A70(a2);
  v6 = sub_142D98(v5, HIDWORD(v5), dword_106448, dword_10644C);
  v7 = a1 + 4 * a3;
  v8 = sub_143108(v6);
  v9 = *(_DWORD *)(v7 + 140);
  v10 = COERCE_FLOAT(rf_state_check_n3ea_d908(v8));
  v11 = *(_QWORD *)(a1 + 164);
  v12 = (int)(float)(v10 * 20.0);
  if ( SHIDWORD(v11) < v12 )
  {
    feature_guard_sdio(1, dword_106440);
    if ( *(_DWORD *)(a1 + 172) <= v12 )
      goto LABEL_3;
LABEL_5:
    feature_guard_sdio(1, dword_106444);
    goto LABEL_3;
  }
  if ( *(_DWORD *)(a1 + 172) > v12 )
    goto LABEL_5;
LABEL_3:
  *(_DWORD *)(v7 + 140) = v9 + v11 - v12;
  return log_free_pool_dispatch2_n4e6(a1, a3);
}

