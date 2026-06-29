// sub_1149FC @ 0x1149fc, size 218 bytes
unsigned __int8 *sub_1149FC()
{
  int *v0; // r4
  unsigned __int8 *result; // r0
  int v2; // r2
  int v3; // r1
  int v4; // r3
  unsigned __int8 *v5; // r5
  int v6; // r0
  int v7; // r2
  int v8; // r0
  int v9; // r2
  int v10; // r0
  int v11; // r3
  int v12; // r2
  int v13; // r3
  int v14; // r2
  int *v15; // r3
  int v16; // r3

  sub_12D374(16);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_114AD8 = 1;
  }
  v0 = (int *)off_114ADC;
  result = (unsigned __int8 *)off_114AE0;
  v2 = *(uint32_t *)off_114ADC;
  v3 = *((uint32_t *)off_114AE0 + 4);
  v4 = *(uint32_t *)off_114ADC + 1;
  *(uint32_t *)off_114ADC = v4;
  if ( v3 )
  {
    result = (unsigned __int8 *)sub_12D4F8(result + 16);
    v5 = result;
    if ( *v0 )
    {
      v13 = *v0 - 1;
      v14 = *(uint32_t *)off_114AD8;
      *v0 = v13;
      if ( !v13 )
      {
        if ( v14 )
          __enable_irq();
      }
    }
    if ( result )
    {
      v6 = sub_114790(result + 4);
      if ( v6 < 0 )
      {
        return (unsigned __int8 *)sub_12ECB0(dword_114AEC, v5[4], v7);
      }
      else
      {
        *(uint32_t *)v5 = v6;
        v8 = sub_114944(17, 3090, v5);
        if ( v8 )
        {
          sub_12ECB0(dword_114AE4, v8, v9);
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(uint32_t *)off_114AD8 = 1;
          }
          v10 = dword_114AE8;
          ++*v0;
          bt_state_check_or_init(v10, v5);
          if ( *v0 )
          {
            v11 = *v0 - 1;
            v12 = *(uint32_t *)off_114AD8;
            *v0 = v11;
            if ( !v11 )
            {
              if ( v12 )
                __enable_irq();
            }
          }
          return (unsigned __int8 *)irq_nesting_or(16);
        }
        else
        {
          sub_114710();
          return (unsigned __int8 *)patch_helper(0);
        }
      }
    }
  }
  else if ( v4 )
  {
    v15 = (int *)off_114AD8;
    *v0 = v2;
    v16 = *v15;
    if ( !v2 )
    {
      if ( v16 )
        __enable_irq();
    }
  }
  return result;
}

