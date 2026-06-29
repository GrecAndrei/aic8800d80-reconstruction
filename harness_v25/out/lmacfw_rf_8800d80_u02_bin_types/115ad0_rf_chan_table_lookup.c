// rf_chan_table_lookup @ 0x115ad0, size 116 bytes
// Doc: rf_chan_table_lookup [rf]: Looks up channel entry in table indexed by 5-element stride
// rf_chan_table_lookup [rf]: Looks up channel entry in table indexed by 5-element stride
int  rf_chan_table_lookup(int a1)
{
  uint32_t *v1; // r5
  int v3; // r3
  int v4; // r4
  uint32_t *v5; // r2
  int *v6; // r5
  int v7; // r1
  int result; // r0
  int *v9; // r3
  int v10; // r3

  if ( a1 == 5 )
    v1 = (uint32_t *)dword_115B4C;
  else
    v1 = (uint32_t *)dword_115B48;
  if ( a1 != 5 )
    v1 += 7 * a1;
  rf_bus_write_60fc(a1, dword_115B44 + 8 * a1, 0);
  rf_bus_write_60fc(a1, v1 + 3, 0);
  *v1 = 0;
  v1[5] = 0;
  sub_1152D8(a1);
  v3 = *(uint32_t *)off_115B50;
  v4 = 1 << a1;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_115B54 = 1;
  }
  v5 = off_115B58;
  v6 = (int *)off_115B50;
  v7 = *(uint32_t *)off_115B58;
  result = *(uint32_t *)off_115B58 + 1;
  *(uint32_t *)off_115B58 = result;
  *v6 = v3 & ~v4;
  if ( result )
  {
    v9 = (int *)off_115B54;
    *v5 = v7;
    v10 = *v9;
    if ( !v7 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  *(uint32_t *)off_115B5C = v4;
  return result;
}

