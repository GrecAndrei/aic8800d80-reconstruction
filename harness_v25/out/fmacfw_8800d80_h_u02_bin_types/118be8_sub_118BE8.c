// sub_118BE8 @ 0x118be8, size 134 bytes
uint32_t *sub_118BE8()
{
  int *v0; // r8
  int *v1; // r7
  int v2; // r6
  uint32_t *v3; // r5
  uint32_t *result; // r0
  uint32_t *v5; // r4
  int v6; // r3
  int v7; // r2
  void ( *v8)(uint32_t, uint32_t); // r2

  sub_12D00C(0x20000);
  v0 = (int *)off_118C80;
  v1 = (int *)off_118C70;
  v2 = dword_118C74;
  v3 = off_118C78;
  while ( 1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *v1 = 1;
    }
    ++*v0;
    result = (uint32_t *)sub_12D190(v2);
    v5 = result;
    if ( *v0 )
    {
      v6 = *v0 - 1;
      v7 = *v1;
      *v0 = v6;
      if ( !v6 )
      {
        if ( v7 )
          __enable_irq();
      }
    }
    if ( !result )
      break;
    v8 = (void ( *)(uint32_t, uint32_t))result[22];
    --v3[126];
    if ( v8 && (v8(result[23], *(uint32_t *)(result[19] + 72)), *((uint8_t *)v5 + 98)) )
    {
      *((uint8_t *)v5 + 98) = 0;
    }
    else if ( !*((uint8_t *)v5 + 96) )
    {
      sub_12D108(dword_118C7C);
    }
  }
  return result;
}

