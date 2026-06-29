// sub_1404B0 @ 0x1404b0, size 94 bytes
int  sub_1404B0(int a1, int a2, int a3)
{
  int v3; // r3
  int v4; // r4
  unsigned __int8 *v5; // r2
  unsigned __int8 *v6; // r0
  int v7; // t1
  unsigned __int8 *v9; // r2
  unsigned __int8 *v10; // r3
  int v11; // t1

  if ( !a3 )
    return 1;
  v3 = *(uint32_t *)(a3 + 8);
  if ( v3 )
  {
    if ( a1 != 255 )
    {
      if ( v3 > 0 )
      {
        v9 = (unsigned __int8 *)(a3 + 12);
        v10 = &v9[v3];
        while ( 1 )
        {
          v11 = *v9++;
          if ( v11 == a1 )
            break;
          if ( v9 == v10 )
            return 0;
        }
        return 1;
      }
      return 0;
    }
    v4 = *(uint32_t *)(a3 + 20);
LABEL_5:
    if ( v4 > 0 )
    {
      v5 = (unsigned __int8 *)(a3 + 24);
      v6 = &v5[v4];
      while ( 1 )
      {
        v7 = *v5++;
        if ( a2 == v7 )
          break;
        if ( v5 == v6 )
          return 0;
      }
      return 1;
    }
    return 0;
  }
  v4 = *(uint32_t *)(a3 + 20);
  if ( !v4 )
    return 1;
  if ( a1 == 255 )
    goto LABEL_5;
  return *(uint32_t *)(a3 + 8);
}

