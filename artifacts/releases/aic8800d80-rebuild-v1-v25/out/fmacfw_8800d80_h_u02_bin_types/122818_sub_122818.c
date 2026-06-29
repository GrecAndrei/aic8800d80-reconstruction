// sub_122818 @ 0x122818, size 90 bytes
int  sub_122818(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r3
  int v7; // r2
  int v8; // r2
  int v9; // r1

  v5 = sub_12C7EC(118, a4, a3, 12);
  v6 = dword_122874 + 696 * *a2;
  v7 = *(unsigned __int8 *)(v6 + 34);
  if ( v7 == 255 )
    goto LABEL_4;
  v8 = dword_122878 + 1320 * v7;
  v9 = *(unsigned __int8 *)(v8 + 106);
  *(uint32_t *)v5 = *(uint32_t *)(*(uint32_t *)(v6 + 336) + 20);
  *(uint32_t *)(v5 + 4) = 0;
  if ( !v9 )
  {
    *(uint8_t *)(v5 + 8) = *(uint8_t *)(v8 + 142);
LABEL_4:
    sub_12C84C(v5);
    return 0;
  }
  *(uint8_t *)(v5 + 8) = *(uint8_t *)(v6 + 689);
  sub_12C84C(v5);
  return 0;
}

