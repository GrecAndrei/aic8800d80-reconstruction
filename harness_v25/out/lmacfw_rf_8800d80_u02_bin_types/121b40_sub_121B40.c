// sub_121B40 @ 0x121b40, size 144 bytes
// Doc: rf_mem_write_n_496 [rf]: Write aligned RF memory block
// rf_mem_write_n_496 [rf]: Write aligned RF memory block
unsigned int  sub_121B40(unsigned int a1, int a2, int a3)
{
  unsigned int v3; // r7
  int *v4; // r5
  uint8_t *v8; // r9
  int v9; // r3
  int v10; // r8
  unsigned __int8 *v11; // r4
  unsigned __int8 *v12; // r6
  int v13; // t1

  v3 = a2 - 1;
  if ( *(uint8_t *)(a2 - 1) == 9 )
  {
    v4 = (int *)off_121BD0;
    if ( a3 < *(uint32_t *)off_121BD0 )
    {
      v8 = (uint8_t *)dword_121BD8;
      do
      {
        uart_puts(v8);
        v9 = *v4 - 1;
        *v4 = v9;
      }
      while ( v9 > a3 );
    }
    if ( v3 > a1 )
    {
      v10 = dword_121BDC;
      v11 = (unsigned __int8 *)(a1 - 1);
      v12 = (unsigned __int8 *)(a2 - 2);
      do
      {
        while ( 1 )
        {
          v13 = *++v11;
          if ( v13 == 9 )
            break;
          ++*v4;
          uart_putc(*v11);
          if ( v11 == v12 )
            goto rf_cmd_dispatch_n_392;
        }
        uart_puts((uint8_t *)((*v4 & 7) + v10));
        *v4 = (*v4 & 0xFFFFFFF8) + 8;
      }
      while ( v11 != v12 );
    }
  }
  else
  {
    uart_puts((uint8_t *)dword_121BD8);
    --*(uint32_t *)off_121BD0;
  }
rf_cmd_dispatch_n_392:
  --*(uint32_t *)off_121BD4;
  return v3;
}

