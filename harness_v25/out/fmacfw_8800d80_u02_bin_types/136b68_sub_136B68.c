// sub_136B68 @ 0x136b68, size 100 bytes
int  sub_136B68(int result, int a2)
{
  int v3; // r3
  int v4; // r0

  if ( (*(uint16_t *)(result + 30) & 0x1000) != 0 )
  {
    v3 = *(unsigned __int8 *)(a2 + 310);
    if ( ((unsigned __int8)v3 & *(uint8_t *)(dword_136BCC + *(unsigned __int8 *)(result + 27))) != 0 )
    {
      if ( (*(uint8_t *)(a2 + 53) & 8) == 0 )
      {
        *(uint8_t *)(a2 + 53) |= 8u;
        if ( v3 == 15 )
          goto LABEL_5;
      }
    }
    else if ( (*(uint8_t *)(a2 + 53) & 2) == 0 )
    {
      *(uint8_t *)(a2 + 53) |= 2u;
LABEL_5:
      v4 = sub_12C92C(65, 0, 5, 4u);
      *(uint16_t *)v4 = *(uint16_t *)(a2 + 32);
      *(uint8_t *)(v4 + 3) = *(uint8_t *)(a2 + 34);
      *(uint8_t *)(v4 + 2) = 1;
      return sdio_buffer_prepare_n_4e8(v4);
    }
  }
  return result;
}

