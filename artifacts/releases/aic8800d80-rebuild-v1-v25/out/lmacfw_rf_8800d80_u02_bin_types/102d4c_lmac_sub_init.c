// lmac_sub_init @ 0x102d4c, size 136 bytes
// Doc: lmac_sub_init [util]: Initialize LMAC subsystem with parameter check
// lmac_sub_init [util]: Initialize LMAC subsystem with parameter check
int  lmac_sub_init(int a1, int a2, unsigned int a3, int a4)
{
  int v6; // r6
  int v7; // r4
  int v8; // r10
  int v9; // r12
  int v10; // r2
  int v11; // r6
  int v12; // lr
  int *v13; // r7
  int *v14; // r1
  uint32_t *v15; // r4
  int v16; // t1
  int result; // r0

  if ( a1 )
  {
    v6 = 16 * (dword_102DDC + a2);
    v7 = 4;
    v8 = 3;
  }
  else
  {
    v6 = 32 * (dword_102DD4 + a2);
    v7 = 8;
    v8 = 5;
  }
  while ( !*(uint32_t *)off_102DD8 )
    ;
  sub_102ADC(a1);
  if ( a3 )
  {
    v9 = 0;
    v10 = 4 * (v7 - v8);
    v11 = v6 - a4;
    v12 = 0;
    v13 = (int *)(a4 + 4 * v8);
    do
    {
      v14 = (int *)(a4 + 4 * v9);
      do
      {
        v15 = (int *)((char *)v14 + v11);
        v16 = *v14++;
        *v15 = v16;
      }
      while ( v13 != v14 );
      ++v12;
      v9 += v8;
      v11 += v10;
      v13 += v8;
    }
    while ( a3 > (unsigned __int8)v12 );
  }
  result = sub_102B40(a1);
  *(uint32_t *)off_102DD8 = 1;
  return result;
}

