// sub_131474 @ 0x131474, size 88 bytes
int  sub_131474(unsigned __int8 *a1, int a2, int a3, uint8_t *a4)
{
  int result; // r0
  char v7; // r2
  int v8; // r2
  int v9; // r7
  int v10; // r5
  int v11; // r3

  result = (int)sdio_buffer_prepare_e188(a1, a2);
  *a4 = 0;
  if ( result )
  {
    v7 = *(uint8_t *)(result + 3);
    if ( *(uint8_t *)(a3 + 17) == (v7 & 0xF) )
    {
      return 1;
    }
    else
    {
      *a4 = 1;
      *(uint8_t *)(a3 + 16) = v7;
      *(uint8_t *)(a3 + 17) = v7 & 0xF;
      v8 = *(unsigned __int16 *)(result + 8);
      v9 = *(unsigned __int16 *)(result + 11);
      v10 = *(unsigned __int16 *)(result + 14);
      *(uint32_t *)(a3 + 4) = *(unsigned __int8 *)(result + 4) | (*(unsigned __int16 *)(result + 5) << 8);
      *(uint32_t *)a3 = *(unsigned __int8 *)(result + 7) | (v8 << 8);
      *(uint32_t *)(a3 + 8) = *(unsigned __int8 *)(result + 10) | (v9 << 8);
      v11 = *(unsigned __int8 *)(result + 13) | (v10 << 8);
      result = 1;
      *(uint32_t *)(a3 + 12) = v11;
    }
  }
  return result;
}

