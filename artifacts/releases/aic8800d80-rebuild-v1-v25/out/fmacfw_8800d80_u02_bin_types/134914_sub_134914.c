// sub_134914 @ 0x134914, size 314 bytes
int sub_134914()
{
  uint16_t *v0; // r6
  int v1; // r4
  int v2; // r5
  __int16 v3; // r7
  uint32_t *v4; // r1
  int *v5; // r2
  int *v6; // r3
  unsigned int v7; // r2
  int result; // r0
  uint32_t *v9; // r12
  int *v10; // r0
  int v11; // r1

  v0 = off_134A50;
  v1 = *((uint32_t *)off_134A50 + 2);
  feature_guard_check(256, dword_134A54);
  v2 = sub_12C92C(6149, 13, 6, 6u);
  if ( *((uint8_t *)v0 + 4) )
    v3 = 0;
  else
    v3 = v0[6];
  *(uint8_t *)(v1 + 149) = 0;
  timestamp_remove(v1 + 152);
  v6 = *((int **)off_134A58 + 2);
  if ( !v6 )
  {
LABEL_14:
    mmio_init_or_reset(0, (int)v4, (int)v5);
    goto LABEL_15;
  }
  v4 = nullptr;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( !*((uint8_t *)v6 + 106) )
      {
        if ( !*((uint8_t *)v6 + 108) )
          goto LABEL_8;
        v4 = (uint32_t *)((char *)v4 + 1);
        if ( (int *)v1 == v6 )
          goto LABEL_8;
        break;
      }
      if ( (int *)v1 == v6 )
        goto LABEL_8;
      if ( *((uint8_t *)v6 + 108) )
        break;
      v6 = (int *)*v6;
      if ( !v6 )
      {
LABEL_13:
        v5 = *(int **)off_134A5C;
        if ( *(int *)off_134A5C < 0 && v4 == (uint32_t *)1 )
        {
          v4 = off_134A64;
          *((uint8_t *)off_134A60 + 2) = (uint8_t)v6;
          v5 = (int *)off_134A68;
          *v4 |= 0x80000000;
          *v5 = (HIWORD(*v5) << 16) | 0x5DC;
        }
        goto LABEL_14;
      }
    }
    v7 = *((unsigned __int16 *)v6 + 208);
    if ( v7 <= 0x1387 )
      break;
LABEL_8:
    v6 = (int *)*v6;
    if ( !v6 )
      goto LABEL_13;
  }
  if ( *(int *)off_134A5C < 0 && v4 == (uint32_t *)1 )
  {
    v9 = off_134A64;
    *((uint8_t *)off_134A60 + 2) = 0;
    v10 = (int *)off_134A68;
    *v9 |= 0x80000000;
    v11 = (HIWORD(*v10) << 16) | 0x5DC;
    *v10 = v11;
    mmio_init_or_reset(v7 | (*((unsigned __int8 *)v6 + 413) << 16) | 0x80000000, v11, v7);
  }
  else
  {
    mmio_init_or_reset(v7 | (*((unsigned __int8 *)v6 + 413) << 16) | 0x80000000, (int)v4, v7);
  }
LABEL_15:
  sub_12077C((int *)v1, 0, 0);
  result = sub_134800(v1);
  *(uint16_t *)v2 = v3;
  *(uint8_t *)(v2 + 2) = *(uint8_t *)(v1 + 107);
  *(uint8_t *)(v2 + 4) = *((uint8_t *)v0 + 33);
  *(uint32_t *)v0 = v2 - 12;
  return result;
}

