// sub_106568 @ 0x106568, size 124 bytes
// Doc: sub_1206568 [util]: Helper: invoke MMIO/set call with relocated constants
// sub_1206568 [util]: Helper: invoke MMIO/set call with relocated constants
int  sub_106568(int a1, int a2, int a3)
{
  uint64_t v5; // r0
  int v6; // r0
  int v7; // r9
  int v8; // r0
  int v9; // r7
  float v10; // r0
  uint64_t v11; // kr00_8
  int v12; // r5

  v5 = sub_1429D4(a2);
  v6 = sub_142CFC(v5, HIDWORD(v5), dword_1065F0, dword_1065F4);
  v7 = a1 + 4 * a3;
  v8 = sub_14306C(v6);
  v9 = *(uint32_t *)(v7 + 140);
  v10 = COERCE_FLOAT(sub_12D6E0(v8));
  v11 = *(QWORD *)(a1 + 164);
  v12 = (int)(float)(v10 * 20.0);
  if ( SHIDWORD(v11) < v12 )
  {
    feature_guard_check(1, dword_1065E8);
    if ( *(uint32_t *)(a1 + 172) <= v12 )
      goto LABEL_3;
LABEL_5:
    feature_guard_check(1, dword_1065EC);
    goto LABEL_3;
  }
  if ( *(uint32_t *)(a1 + 172) > v12 )
    goto LABEL_5;
LABEL_3:
  *(uint32_t *)(v7 + 140) = v9 + v11 - v12;
  return sub_1064BC(a1, a3);
}

