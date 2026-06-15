// v23 annotated: sub_104B60 @ 0x104b60
// Original: 104b60_sub_104B60.c
// Primary struct: <unclustered>
//
// sub_104B60 @ 0x104b60, size 154 bytes
// Doc: sub_1204B60 [util]: Helper routine comparing two pointers with stack frame save
// sub_1204B60 [util]: Helper routine comparing two pointers with stack frame save
int __fastcall sub_104B60(int a1, int a2, int a3)
{
  float v6; // s14
  __int64 v8; // r8
  __int64 v9; // r0
  int v10; // r0
  int v11; // r0
  float v12; // r0
  float v13; // s14
  __int64 v14; // r8
  __int64 v15; // r0
  int v16; // r0
  int v17; // r0

  if ( a1 > a2 )
  {
    v14 = sub_12754C(a1);
    v15 = sub_12754C(a2);
    v16 = sub_127874(v14, HIDWORD(v14), v15, HIDWORD(v15));
    v17 = sub_127BE4(v16);
    v12 = COERCE_FLOAT(sub_11EAA0(v17));
    v13 = 20.0;
    goto LABEL_6;
  }
  if ( a1 < a2 )
  {
    v8 = sub_12754C(a2);
    v9 = sub_12754C(a1);
    v10 = sub_127874(v8, HIDWORD(v8), v9, HIDWORD(v9));
    v11 = sub_127BE4(v10);
    v12 = COERCE_FLOAT(sub_11EAA0(v11));
    v13 = -20.0;
LABEL_6:
    v6 = v12 * v13;
    goto LABEL_4;
  }
  v6 = flt_104BFC;
LABEL_4:
  *(float *)(a3 + 96) = v6;
  return sub_11F74C(1, dword_104C00, a1, a2);
}

