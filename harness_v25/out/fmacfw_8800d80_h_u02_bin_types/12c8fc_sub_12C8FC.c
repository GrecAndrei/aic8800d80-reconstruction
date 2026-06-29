// sub_12C8FC @ 0x12c8fc, size 86 bytes
uint32_t * sub_12C8FC(int a1, int ( *a2)(uint32_t *, int), int a3)
{
  uint32_t *v3; // r4
  uint32_t *v7; // r8
  int i; // r0
  int v9; // r3

  v3 = *(uint32_t **)a1;
  if ( !*(uint32_t *)a1 )
    return nullptr;
  v7 = nullptr;
  for ( i = a2(v3, a3); ; i = a2(v3, a3) )
  {
    v9 = *v3;
    if ( i )
      break;
    v7 = v3;
    if ( !v9 )
      return nullptr;
    v3 = (uint32_t *)*v3;
  }
  if ( v7 )
  {
    *v7 = v9;
    if ( *v3 )
    {
LABEL_8:
      *v3 = 0;
      return v3;
    }
  }
  else
  {
    *(uint32_t *)a1 = v9;
    if ( v9 )
      goto LABEL_8;
  }
  *(uint32_t *)(a1 + 4) = v7;
  return v3;
}

