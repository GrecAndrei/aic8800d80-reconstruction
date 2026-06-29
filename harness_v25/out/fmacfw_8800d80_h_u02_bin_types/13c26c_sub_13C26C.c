// sub_13C26C @ 0x13c26c, size 72 bytes
int  sub_13C26C(int a1)
{
  int v1; // r5
  int result; // r0
  __int16 v4; // r2
  int v5; // r3
  bool v6; // zf

  v1 = *(uint32_t *)(a1 + 28);
  sub_100200((int *)(v1 + 6), 0, 0x100u);
  result = 348;
  v4 = *(uint16_t *)(dword_13C2B4 + 2 * (*(unsigned __int8 *)(a1 + 22) + 348 * *(unsigned __int8 *)(a1 + 16)) + 316);
  *(uint8_t *)(v1 + 262) = 0;
  v5 = *(unsigned __int8 *)(a1 + 20);
  *(uint16_t *)(v1 + 4) = v4;
  v6 = ((v5 - 1) & v5) == 0;
  *(uint8_t *)(v1 + 263) = v5;
  if ( ((v5 - 1) & v5) != 0 )
    v5 = dword_13C2B8;
  else
    *(uint8_t *)(v1 + 264) = v5 - 1;
  if ( v6 )
    v5 = dword_13C2BC;
  *(uint32_t *)v1 = v5;
  return result;
}

