// sub_107214 @ 0x107214, size 164 bytes
// Doc: sub_1207214 [util]: Utility function loading constant and calling helper
// sub_1207214 [util]: Utility function loading constant and calling helper
int  sub_107214(unsigned int a1, uint32_t *a2, int a3, int a4)
{
  int v4; // r8
  int v8; // r3
  int v9; // s15
  int v10; // r3
  int v11; // r3
  int v12; // r2
  int v13; // r2

  v4 = *(uint32_t *)(a3 + 8);
  sub_11F74C(1, dword_1072B8, v4, a4);
  sub_11F74C(1, dword_1072BC, a1, v8);
  v9 = (int)(float)(COERCE_FLOAT(((int ( *)(uint32_t))sub_11EAA0)(vcvts_n_f32_u32(a1, 0xEu))) * 10.0);
  sub_11F74C(1, dword_1072C0, v9, v10);
  v12 = a2[8];
  if ( v12 < v9 )
  {
    sub_11F74C(1, dword_1072C4, v12, v11);
    v13 = a2[9];
    if ( v13 <= v9 )
      goto LABEL_3;
LABEL_5:
    sub_11F74C(1, dword_1072C8, v13, v11);
    goto LABEL_3;
  }
  v13 = a2[9];
  if ( v13 > v9 )
    goto LABEL_5;
LABEL_3:
  *(uint32_t *)(a3 + 8) = (int)((float ( *)(uint32_t))sub_11EAC8)((float)(unsigned int)(a2[7] - v9 + v4));
  return sub_107150(a3);
}

