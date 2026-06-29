// sub_11849C @ 0x11849c, size 178 bytes
uint32_t *sub_11849C()
{
  uint32_t *result; // r0
  uint32_t *v1; // r4
  uint32_t *v2; // r0
  uint32_t *v3; // r5
  int *v4; // r2
  int v5; // r0
  int *v6; // r6
  uint32_t *v7; // r2
  int v8; // r1
  uint16_t *v9; // r4
  __int16 v10; // r2
  int v11; // r3
  uint32_t *v12; // r5
  int v13; // r1
  int v14; // r3
  int v15; // r3

  result = (uint32_t *)(*(int ( **)(uint32_t))(*((uint32_t *)off_118550 + 2) + 16))(*((uint32_t *)off_118550 + 1));
  if ( result )
  {
    v1 = result;
    v2 = (uint32_t *)log_free_dispatch_n2b4();
    v3 = v2;
    if ( v2 )
    {
      v4 = (int *)off_118554;
      *v2 = 0;
      v5 = *v4;
      v3[1] = 0;
      v3[2] = 0;
      *v3 = (char *)v1 + v5;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_118558 = 1;
      }
      v6 = (int *)off_11855C;
      v7 = off_118560;
      v8 = *(uint32_t *)off_11855C + 1;
      *(uint32_t *)off_11855C = v8;
      *v7 = 1;
      while ( (*v7 & 2) != 0 )
        ;
      if ( *(uint32_t *)off_118564 )
      {
        v9 = off_11856C;
        v15 = *((uint32_t *)off_11856C + 1);
        if ( v15 )
        {
          *(uint32_t *)(v15 + 4) = v3;
        }
        else
        {
          sub_12ECB0(dword_118578, v8, v7);
          v8 = *v6;
        }
      }
      else
      {
        if ( *(uint32_t *)off_118568 )
        {
          sub_12ECB0(dword_118574, v8, v7);
          v8 = *v6;
        }
        v9 = off_11856C;
        *(uint32_t *)off_118568 = v3;
      }
      result = off_118564;
      v10 = v9[6];
      v11 = *(uint32_t *)off_118564;
      *((uint32_t *)v9 + 1) = v3;
      v12 = off_118570;
      v9[6] = v10 + 1;
      *result = v11 + 1;
      *v12 = 1;
      if ( v8 )
      {
        v13 = v8 - 1;
        v14 = *(uint32_t *)off_118558;
        *v6 = v13;
        if ( !v13 )
        {
          if ( v14 )
            __enable_irq();
        }
      }
    }
    else
    {
      return (uint32_t *)log_free_dispatch_2(v1);
    }
  }
  return result;
}

