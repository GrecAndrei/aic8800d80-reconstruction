// fwstruct annotate: 105f40_sub_105F40.c
// sub_105F40 @ 0x105f40, size 124 bytes
int __fastcall sub_105F40(_DWORD *a1, int a2, int a3)
{
  __int64 v5; // r0
  int v6; // r0
  _DWORD *v7; // r9
  int v8; // r0
  int v9; // r7
  float v10; // r0
  int v11; // r2
  int v12; // r3
  int v13; // r5
  int v14; // r8
  int v15; // r2

  v5 = sub_12754C(a2);
  v6 = sub_127874(v5, HIDWORD(v5), dword_105FC8, dword_105FCC);
  v7 = &a1[a3];
  v8 = sub_127BE4(v6);
  v9 = v7[35];
  v10 = COERCE_FLOAT(sub_11EAA0(v8));
  v11 = a1[42];
  v12 = a1[41];
  v13 = (int)(float)(v10 * 20.0);
  v14 = v12 - v13;
  if ( v11 < v13 )
  {
    sub_11F74C(1, dword_105FC0, v11, v12);
    v15 = a1[43];
    if ( v15 <= v13 )
      goto LABEL_3;
LABEL_5:
    sub_11F74C(1, dword_105FC4, v15, v12);
    goto LABEL_3;
  }
  v15 = a1[43];
  if ( v15 > v13 )
    goto LABEL_5;
LABEL_3:
  v7[35] = v9 + v14;
  return crypto_table_copy_165d00((int)a1, a3);
}

