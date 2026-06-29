// sub_1270CC @ 0x1270cc, size 144 bytes
// Doc: sub_12270CC [unknown]: Load pointer from table and access field at offset 0x2c
// sub_12270CC [unknown]: Load pointer from table and access field at offset 0x2c
int  sub_1270CC(int result)
{
  uint32_t *v1; // r5
  int v2; // r4
  int v3; // r6
  uint8_t *v4; // r0
  int *v5; // r6
  int v6; // r3
  int v7; // r2
  uint32_t *v8; // r0

  v1 = off_12715C;
  v2 = result;
  if ( *((uint32_t *)off_12715C + 11) )
  {
    *((uint32_t *)off_12715C + 11) = result;
  }
  else
  {
    v3 = *((uint32_t *)off_12715C + 10);
    if ( v3 == result )
    {
      *(uint8_t *)(v3 + 16) = 4;
    }
    else
    {
      if ( v3 && *(uint8_t *)(v3 + 24) != 3 )
      {
        v4 = (uint8_t *)sub_12C92C(69, 13, 0, 1);
        *v4 = *(uint8_t *)(v3 + 24);
        sdio_buffer_prepare_n_4e8(v4);
      }
      if ( *((int *)off_127160 + 1) > 0 )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(uint32_t *)off_127164 = 1;
        }
        v5 = (int *)off_127168;
        ++*(uint32_t *)off_127168;
        rf_set_bit_flag(4);
        category_dispatch_5way(4);
        if ( *v5 )
        {
          v6 = *v5 - 1;
          v7 = *(uint32_t *)off_127164;
          *v5 = v6;
          if ( !v6 )
          {
            if ( v7 )
              __enable_irq();
          }
        }
      }
      v1[11] = v2;
      *(uint8_t *)(v2 + 16) = 2;
      v8 = (uint32_t *)sub_12C92C(140, 0, 255, 4);
      *v8 = dword_12716C;
      return sdio_buffer_prepare_n_4e8(v8);
    }
  }
  return result;
}

