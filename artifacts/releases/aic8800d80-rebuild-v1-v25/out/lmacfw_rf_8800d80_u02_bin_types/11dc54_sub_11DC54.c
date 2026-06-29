// sub_11DC54 @ 0x11dc54, size 152 bytes
int  sub_11DC54(int result, int a2)
{
  int *v2; // r5
  uint32_t *v3; // r6
  int v4; // r4
  int v5; // r3
  int v6; // r3
  int v7; // r2
  int v8; // r7
  int v9; // r0

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11DCEC = 1;
  }
  v2 = (int *)off_11DCF0;
  v3 = off_11DCF4;
  v4 = *((uint32_t *)off_11DCF4 + 5);
  v5 = *(uint32_t *)off_11DCF0 + 1;
  *(uint32_t *)off_11DCF0 = v5;
  if ( v4 )
  {
    if ( *(unsigned __int16 *)(v4 + 4) == result && *(unsigned __int16 *)(v4 + 6) == a2 )
    {
      sub_11E7AC(v3 + 5);
      v8 = v3[5];
      v9 = (int)(v3 + 8);
      if ( v8 )
      {
        sub_11AB18(v9, *(uint32_t *)(v8 + 8));
        if ( **(__int16 **)off_11DD00 < 0 && *(uint32_t *)(v8 + 8) - *((uint32_t *)off_11DD04 + 4) < 0 )
          sub_1219C4(dword_11DD0C, dword_11DD08, 232);
      }
      else
      {
        sub_11AC10(v9);
      }
    }
    else
    {
      result = sub_11DEEC(dword_11DCFC, dword_11DCF8, a2 | (result << 16));
      v4 = result;
      if ( !result )
      {
        v5 = *v2;
        goto LABEL_8;
      }
    }
    result = sub_11E078(v4);
    v5 = *v2;
  }
LABEL_8:
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(uint32_t *)off_11DCEC;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

