// sub_12C7EC @ 0x12c7ec, size 82 bytes
int  sub_12C7EC(__int16 a1, __int16 a2, __int16 a3, unsigned int a4)
{
  int v8; // r0
  int v9; // r4

  v8 = ((int ( *)(unsigned int))loc_12C9A4)(a4 + 12);
  v9 = v8;
  if ( **(__int16 **)off_12C840 < 0 && !v8 )
    sub_12F32C(dword_12C848, dword_12C844, 145);
  *(uint16_t *)(v9 + 4) = a1;
  *(uint16_t *)(v9 + 6) = a2;
  *(uint16_t *)(v9 + 8) = a3;
  *(uint16_t *)(v9 + 10) = a4;
  *(uint32_t *)v9 = 0;
  sub_100200((int *)(v9 + 12), 0, a4);
  return v9 + 12;
}

