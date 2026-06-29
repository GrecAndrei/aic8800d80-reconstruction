// sub_136D14 @ 0x136d14, size 84 bytes
int  sub_136D14(int result, int a2)
{
  int v2; // r4
  char v3; // r1
  int v4; // r0
  __int16 v5; // r1

  if ( *(uint8_t *)(result + 106) == 2 )
  {
    v2 = dword_136D68 + 696 * a2;
    result = sub_11F3CC(result, v2, 0);
    v3 = *(uint8_t *)(v2 + 53);
    if ( (v3 & 0xA) != 0 )
    {
      *(uint8_t *)(v2 + 53) = v3 & 0xF5;
      if ( (v3 & 0xF5) == 0 )
      {
        v4 = sub_12C92C(65, 0, 5, 4u);
        v5 = *(uint16_t *)(v2 + 32);
        *(uint8_t *)(v4 + 3) = *(uint8_t *)(v2 + 34);
        *(uint8_t *)(v4 + 2) = 0;
        *(uint16_t *)v4 = v5;
        return sdio_buffer_prepare_n_4e8(v4);
      }
    }
  }
  return result;
}

