// log_pool_alloc2_a18 @ 0x10fa18, size 396 bytes
// Doc: log_pool_alloc2_a18 [util]: Allocates an entry from the firmware log pool
// log_pool_alloc2_a18 [util]: Allocates an entry from the firmware log pool
uint32_t * log_pool_alloc2_a18(int a1, unsigned int a2)
{
  unsigned int v2; // r6
  uint32_t *v3; // r5
  unsigned __int16 *v4; // r4
  unsigned int v5; // r3
  int *v6; // r6
  int v7; // r3
  int v8; // r2
  unsigned int *v9; // r7
  unsigned int v10; // r2
  int v11; // r1
  int v12; // r3
  int v13; // r2
  unsigned __int16 v14; // r3
  bool v15; // cc
  unsigned int v16; // r3
  int *v18; // r3
  int v19; // r3
  int v20; // r3
  int v21; // r2

  v2 = *(unsigned __int8 *)(a1 + 8);
  if ( !*(uint8_t *)(a1 + 8) )
  {
LABEL_57:
    sub_10DA6C(dword_10FBCC);
    return nullptr;
  }
  v3 = *(uint32_t **)(a1 + 12);
  if ( !v3 )
  {
    sub_10DA6C(dword_10FBBC);
    return v3;
  }
  v4 = *(unsigned __int16 **)(a1 + 12);
  v5 = 1;
  while ( v4[2] < a2 )
  {
    if ( v2 <= v5 )
      goto LABEL_11;
    v4 = (unsigned __int16 *)&v3[3 * v5];
LABEL_7:
    v5 = (unsigned __int8)(v5 + 1);
  }
  if ( *v4 )
    goto LABEL_12;
  if ( v2 > v5 )
  {
    v4 = (unsigned __int16 *)&v3[3 * v5];
    goto LABEL_7;
  }
LABEL_11:
  if ( v2 == v5 )
    goto LABEL_57;
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10FBA4 = 1;
  }
  v6 = (int *)off_10FBA8;
  v7 = *v4;
  v3 = *(uint32_t **)off_10FBA8;
  v8 = *(uint32_t *)off_10FBA8 + 1;
  *(uint32_t *)off_10FBA8 = v8;
  if ( !v7 )
  {
    if ( v8 )
    {
      v18 = (int *)off_10FBA4;
      *v6 = (int)v3;
      v19 = *v18;
      if ( !v3 )
      {
        if ( v19 )
          goto LABEL_43;
      }
    }
    return nullptr;
  }
  v9 = (unsigned int *)off_10FBAC;
  v3 = *((uint32_t **)v4 + 2);
  v10 = *(uint32_t *)off_10FBAC;
  if ( *(uint32_t *)off_10FBAC <= (unsigned int)v3 && (unsigned int)v3 <= *((uint32_t *)off_10FBAC + 1) + v10
    || (unsigned int)v3 >= *(uint32_t *)off_10FBB0
    && (unsigned int)v3 <= *(uint32_t *)off_10FBB0 + *((uint32_t *)off_10FBB0 + 1) )
  {
    *((uint32_t *)v4 + 2) = *v3;
    *v4 = v7 - 1;
    if ( v10 <= (unsigned int)v3 )
      goto LABEL_18;
  }
  else
  {
    sub_10DA6C(dword_10FBB4, *((uint32_t *)v4 + 2));
    v10 = *v9;
    v14 = *v4 - 1;
    v15 = *v9 > (unsigned int)v3;
    *((uint32_t *)v4 + 2) = 0;
    *v4 = v14;
    if ( !v15 )
    {
LABEL_18:
      if ( v9[1] + v10 >= (unsigned int)v3 )
      {
        v11 = *((unsigned __int8 *)v3 - 3);
        if ( v11 == 85 )
          goto LABEL_20;
        goto LABEL_45;
      }
    }
  }
  v16 = *(uint32_t *)off_10FBB0;
  if ( *(uint32_t *)off_10FBB0 > (unsigned int)v3 || *((uint32_t *)off_10FBB0 + 1) + v16 < (unsigned int)v3 )
  {
    sub_10DA6C(dword_10FBC0, v3);
    v11 = 0;
    goto LABEL_45;
  }
  v11 = *((unsigned __int8 *)v3 - 3);
  if ( v11 != 85 )
  {
LABEL_45:
    if ( *v6 )
    {
      v20 = *v6 - 1;
      v21 = *(uint32_t *)off_10FBA4;
      *v6 = v20;
      if ( !v20 )
      {
        if ( v21 )
          __enable_irq();
      }
    }
    sub_10DA6C(dword_10FBC4, v11, v3);
    return nullptr;
  }
  if ( v10 > (unsigned int)v3 )
    goto LABEL_36;
  if ( (unsigned int)v3 <= v10 + v9[1] )
    goto LABEL_20;
  if ( (unsigned int)v3 < v16 )
  {
LABEL_37:
    sub_10DA6C(dword_10FBB8, v3);
  }
  else
  {
LABEL_36:
    if ( (unsigned int)v3 > v16 + *((uint32_t *)off_10FBB0 + 1) )
      goto LABEL_37;
LABEL_20:
    *((uint8_t *)v3 - 3) = -86;
  }
  if ( (unsigned int)v3 >= *v9 && (unsigned int)v3 <= *v9 + v9[1]
    || (unsigned int)v3 >= *(uint32_t *)off_10FBB0
    && (unsigned int)v3 <= *(uint32_t *)off_10FBB0 + *((uint32_t *)off_10FBB0 + 1) )
  {
    *((uint8_t *)v3 - 2) = 1;
  }
  else
  {
    sub_10DA6C(dword_10FBC8, v3);
  }
  if ( *v6 )
  {
    v12 = *v6 - 1;
    v13 = *(uint32_t *)off_10FBA4;
    *v6 = v12;
    if ( !v12 )
    {
      if ( v13 )
LABEL_43:
        __enable_irq();
    }
  }
  return v3;
}

