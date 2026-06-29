// sub_12135C @ 0x12135c, size 68 bytes
int  sub_12135C(int a1, uint32_t *a2, __int16 a3, __int16 a4)
{
  uint32_t *v5; // r0
  int v6; // r1
  unsigned int v7; // r2
  int v8; // r4

  v5 = (uint32_t *)rf_setup_dispatch(1060, a4, a3, 0x408u);
  v7 = a2[1];
  v6 = *a2;
  if ( v7 >= 0x400 )
    v7 = 1024;
  *v5 = v6;
  v5[1] = v7;
  v8 = (int)v5;
  sub_1282E8(v5 + 2, v6, v7);
  msg_parse(dword_1213A0, *a2, *(uint32_t *)(v8 + 4) + *a2, *(uint32_t *)(v8 + 8));
  sub_11DE50(v8);
  return 0;
}

