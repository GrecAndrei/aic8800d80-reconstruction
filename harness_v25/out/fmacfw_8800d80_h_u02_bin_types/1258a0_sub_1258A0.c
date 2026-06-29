// sub_1258A0 @ 0x1258a0, size 94 bytes
int  sub_1258A0(int a1)
{
  int *v1; // r5
  int v2; // r6
  int v4; // r2
  int v5; // r3
  int v6; // r6
  int v7; // r2

  v1 = (int *)off_125900;
  v2 = *(uint32_t *)off_125900;
  sub_12C8D0(64, *(unsigned __int16 *)(*(uint32_t *)off_125900 - 4), 0);
  sub_1253D0(a1, *v1);
  v4 = *v1;
  *(uint8_t *)(a1 + 231) = 0;
  v5 = *(unsigned __int8 *)(v4 + 10);
  *(uint8_t *)(a1 + 232) = v5;
  *(uint8_t *)(a1 + 233) = *(uint8_t *)(v4 + 11);
  v6 = v2 - 12;
  if ( v5 )
    *(uint8_t *)(a1 + 231) = *(uint8_t *)(*(uint32_t *)(*(uint32_t *)(a1 + 192) + 28) + v5) + 1;
  v7 = *((unsigned __int8 *)v1 + 8);
  *((uint8_t *)v1 + 9) = 0;
  if ( v7 )
    sub_125780();
  *v1 = 0;
  return sub_12C8F8(v6);
}

