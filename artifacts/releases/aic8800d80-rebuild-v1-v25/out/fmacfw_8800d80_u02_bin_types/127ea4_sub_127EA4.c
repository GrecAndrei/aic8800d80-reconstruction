// sub_127EA4 @ 0x127ea4, size 136 bytes
int  sub_127EA4(unsigned __int8 *a1)
{
  int v1; // r4
  int result; // r0
  unsigned __int8 *v3; // r5
  int v4; // r6
  int v5; // r7
  int v6; // r1
  int v7; // r3
  int *v8; // r7
  int v9; // r3
  int v10; // r2

  v1 = *a1;
  v3 = a1 + 2;
  result = *(uint32_t *)(a1 + 2);
  v4 = dword_127F30;
  v5 = *((uint32_t *)off_127F2C + 10);
  v6 = *((uint32_t *)v3 + 1);
  v7 = dword_127F30 + 28 * v1 + 4;
  *(uint32_t *)v7 = result;
  *(uint32_t *)(v7 + 4) = v6;
  *(uint16_t *)(v7 + 8) = *((uint16_t *)v3 + 4);
  if ( v5 == v4 + 28 * v1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_127F34 = 1;
    }
    v8 = (int *)off_127F38;
    ++*(uint32_t *)off_127F38;
    mmio_toggle_bits_n1c4();
    sub_11DA70(0);
    if ( *v8 )
    {
      v9 = *v8 - 1;
      v10 = *(uint32_t *)off_127F34;
      *v8 = v9;
      if ( !v9 )
      {
        if ( v10 )
          __enable_irq();
      }
    }
    sub_102A20((unsigned __int16 *)v3, 0);
    return mac_rx_reorder(*(char *)(v4 + 28 * v1 + 12));
  }
  return result;
}

