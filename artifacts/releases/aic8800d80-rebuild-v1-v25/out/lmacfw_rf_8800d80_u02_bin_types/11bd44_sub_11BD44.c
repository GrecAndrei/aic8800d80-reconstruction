// sub_11BD44 @ 0x11bd44, size 54 bytes
// Doc: sub_121BD44 [util]: LMAC RF helper: load constant and tail-call helper
// sub_121BD44 [util]: LMAC RF helper: load constant and tail-call helper
int  sub_11BD44(int a1, uint8_t *a2)
{
  int v4; // r0
  char v5; // r2
  int v6; // r1

  v4 = sub_11E7AC(dword_11BD7C);
  if ( !v4 )
    return 1;
  v5 = dword_11BD84 * ((v4 - dword_11BD80) >> 2);
  *(uint8_t *)(v4 + 24) = v5;
  *a2 = v5;
  v6 = *(uint32_t *)(a1 + 4);
  *(uint32_t *)(v4 + 4) = *(uint32_t *)a1;
  *(uint32_t *)(v4 + 8) = v6;
  *(uint16_t *)(v4 + 12) = *(uint16_t *)(a1 + 8);
  return 0;
}

