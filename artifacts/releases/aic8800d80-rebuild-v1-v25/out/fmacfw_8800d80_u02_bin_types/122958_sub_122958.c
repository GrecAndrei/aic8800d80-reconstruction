// sub_122958 @ 0x122958, size 90 bytes
int  sub_122958(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r3
  int v7; // r2
  int v8; // r2
  int v9; // r1

  v5 = sub_12C92C(118, a4, a3, 12);
  v6 = dword_1229B4 + 696 * *a2;
  v7 = *(unsigned __int8 *)(v6 + 34);
  if ( v7 == 255 )
    goto LABEL_4;
  v8 = dword_1229B8 + 1320 * v7;
  v9 = *(unsigned __int8 *)(v8 + 106);
  *(uint32_t *)v5 = *(uint32_t *)(*(uint32_t *)(v6 + 336) + 20);
  *(uint32_t *)(v5 + 4) = 0;
  if ( !v9 )
  {
    *(uint8_t *)(v5 + 8) = *(uint8_t *)(v8 + 142);
LABEL_4:
    sdio_buffer_prepare_n_4e8(v5);
    return 0;
  }
  *(uint8_t *)(v5 + 8) = *(uint8_t *)(v6 + 689);
  sdio_buffer_prepare_n_4e8(v5);
  return 0;
}

