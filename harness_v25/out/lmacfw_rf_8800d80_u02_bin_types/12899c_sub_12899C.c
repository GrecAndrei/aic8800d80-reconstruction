// sub_12899C @ 0x12899c, size 80 bytes
int  sub_12899C(unsigned __int8 *a1, unsigned __int8 *a2, int a3)
{
  unsigned __int8 *v3; // r5
  unsigned __int8 *v4; // r7
  int v5; // r3
  int v6; // r3
  int v7; // t1
  int v8; // r2
  int v9; // t1
  int v10; // r4
  int result; // r0
  int v12; // r2

  if ( a3 )
  {
    v3 = a1;
    v4 = &a1[a3];
    while ( 1 )
    {
      v7 = *v3++;
      v6 = v7;
      v9 = *a2++;
      v8 = v9;
      v10 = *(uint8_t *)(dword_1289EC + v9) & 3;
      if ( (*(uint8_t *)(dword_1289EC + v6) & 3) == 1 )
        v6 += 32;
      result = v8;
      if ( v10 == 1 )
      {
        v12 = v8 + 32;
        result = v6 - v12;
        if ( v6 != v12 )
          return result;
      }
      else
      {
        v5 = v6 - v8;
        if ( v5 )
          return v5;
        if ( !v8 )
          return result;
      }
      if ( v3 == v4 )
        return 0;
    }
  }
  return 0;
}

