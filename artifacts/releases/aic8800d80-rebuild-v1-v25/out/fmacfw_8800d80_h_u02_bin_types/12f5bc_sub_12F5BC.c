// sub_12F5BC @ 0x12f5bc, size 134 bytes
int  sub_12F5BC(unsigned __int8 *a1, int a2)
{
  int v2; // r4
  unsigned __int8 *v4; // r0
  int v5; // r2
  int v6; // t1
  int v7; // r3
  int v8; // r5
  int v9; // r6
  int v10; // t1
  unsigned __int8 *v12; // r2
  int v13; // r3
  int v14; // t1

  v2 = 0;
  while ( 1 )
  {
    do
    {
      do
      {
        v4 = a1;
        v6 = *a1++;
        v5 = v6;
      }
      while ( v6 == 32 );
    }
    while ( v5 == 9 );
    if ( !v5 )
    {
      *(uint32_t *)(a2 + 4 * v2) = 0;
      return v2;
    }
    if ( v5 == 34 )
      break;
    *(uint32_t *)(a2 + 4 * v2) = v4;
    v7 = *v4;
    v8 = v2 + 1;
    v9 = v2 + 1;
    if ( !*v4 )
      goto LABEL_20;
    while ( v7 != 32 && v7 != 9 )
    {
      v10 = *++v4;
      v7 = v10;
      if ( !v10 )
        goto LABEL_20;
    }
LABEL_11:
    if ( !*v4 )
      goto LABEL_20;
    *v4 = 0;
    a1 = v4 + 1;
    v2 = v9;
    if ( v9 == 16 )
    {
      sub_10D674((uint8_t *)dword_12F644);
      return 16;
    }
  }
  v12 = v4 + 1;
  *(uint32_t *)(a2 + 4 * v2) = v4 + 1;
  v13 = v4[1];
  v8 = v2 + 1;
  v9 = v2 + 1;
  if ( v4[1] )
  {
    while ( v13 != 34 )
    {
      v14 = *++v12;
      v13 = v14;
      if ( !v14 )
        goto LABEL_20;
    }
    v4 = v12;
    goto LABEL_11;
  }
LABEL_20:
  *(uint32_t *)(a2 + 4 * v9) = 0;
  return v8;
}

