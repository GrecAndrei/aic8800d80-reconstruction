// fwstruct annotate: 106450_sub_106450.c
// sub_106450 @ 0x106450, size 124 bytes
int __fastcall sub_106450(int a1, int a2, int a3)
{
  __int64 v5; // r0
  int v6; // r0
  int v7; // r9
  int v8; // r0
  int v9; // r7
  float v10; // r0
  __int64 v11; // kr00_8
  int v12; // r5

  v5 = sub_142894(a2);
  v6 = sub_142BBC(v5, HIDWORD(v5), dword_1064D8, dword_1064DC);
  v7 = a1 + 4 * a3;
  v8 = sub_142F2C(v6);
  v9 = *(_DWORD *)(v7 + 140);
  v10 = COERCE_FLOAT(sub_12D5A0(v8));
  v11 = *(_QWORD *)(a1 + 164);
  v12 = (int)(float)(v10 * 20.0);
  if ( SHIDWORD(v11) < v12 )
  {
    sub_12EB90(1, dword_1064D0);
    if ( *(_DWORD *)(a1 + 172) <= v12 )
      goto LABEL_3;
LABEL_5:
    sub_12EB90(1, dword_1064D4);
    goto LABEL_3;
  }
  if ( *(_DWORD *)(a1 + 172) > v12 )
    goto LABEL_5;
LABEL_3:
  *(_DWORD *)(v7 + 140) = v9 + v11 - v12;
  return sub_1063A4(a1, a3);
}

