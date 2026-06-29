// fwstruct annotate: 105188_sub_105188.c
// sub_105188 @ 0x105188, size 154 bytes
int __fastcall sub_105188(int a1, int a2, int a3)
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
    v14 = sub_1429D4(a1);
    v15 = sub_1429D4(a2);
    v16 = sub_142CFC(v14, HIDWORD(v14), v15, HIDWORD(v15));
    v17 = sub_14306C(v16);
    v12 = COERCE_FLOAT(sub_12D6E0(v17));
    v13 = 20.0;
    goto LABEL_6;
  }
  if ( a1 < a2 )
  {
    v8 = sub_1429D4(a2);
    v9 = sub_1429D4(a1);
    v10 = sub_142CFC(v8, HIDWORD(v8), v9, HIDWORD(v9));
    v11 = sub_14306C(v10);
    v12 = COERCE_FLOAT(sub_12D6E0(v11));
    v13 = -20.0;
LABEL_6:
    v6 = v12 * v13;
    goto LABEL_4;
  }
  v6 = flt_105224;
LABEL_4:
  *(float *)(a3 + 96) = v6;
  return feature_guard_check(1, dword_105228);
}

