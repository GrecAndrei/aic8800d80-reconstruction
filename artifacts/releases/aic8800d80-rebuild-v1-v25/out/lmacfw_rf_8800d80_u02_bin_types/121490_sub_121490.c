// sub_121490 @ 0x121490, size 72 bytes
int  sub_121490(int a1, int *a2, __int16 a3, __int16 a4)
{
  int v5; // r0
  uint32_t *v6; // r1
  uint32_t *v7; // r4
  int v9; // r0

  v5 = rf_setup_dispatch(1025, a4, a3, 8u);
  v6 = (uint32_t *)*a2;
  v7 = (uint32_t *)v5;
  if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    v9 = sub_10EFBC(*a2, 1);
    v6 = (uint32_t *)*a2;
    v7[1] = v9;
  }
  else
  {
    *(uint32_t *)(v5 + 4) = *v6;
  }
  *v7 = v6;
  msg_parse(dword_1214D8);
  sub_11DE50((int)v7);
  return 0;
}

