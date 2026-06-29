// sub_1213A4 @ 0x1213a4, size 82 bytes
int  sub_1213A4(int a1, uint32_t *a2, __int16 a3, __int16 a4)
{
  uint32_t *v5; // r5
  int v6; // r0
  bool v7; // zf
  int v8; // r2

  v5 = (uint32_t *)rf_setup_dispatch(1036, a4, a3, 4u);
  v6 = *a2;
  v7 = *a2 << 30 == 0;
  v8 = a2[1];
  *v5 = 0;
  if ( !v7 )
    *v5 = 255;
  if ( v8 << 30 )
    *v5 = 1;
  sub_1282E8(v6, a2 + 2, v8);
  msg_parse(dword_1213F8, *a2, a2[1] + *a2, a2[2], *v5);
  sub_11DE50((int)v5);
  return 0;
}

