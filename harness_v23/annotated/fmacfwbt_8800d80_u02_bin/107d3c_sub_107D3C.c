// v23 annotated: sub_107D3C @ 0x107d3c
// Original: 107d3c_sub_107D3C.c
// Primary struct: <unclustered>
//
// sub_107D3C @ 0x107d3c, size 104 bytes
int *__fastcall sub_107D3C(int *a1)
{
  int v1; // r2
  int v2; // r7
  int v3; // r1
  int v4; // r12
  int v5; // r5
  int v6; // r6
  int *result; // r0
  int i; // r4
  int v9; // r2
  int *v10; // r3

  v1 = a1[1];
  v2 = ((unsigned __int64)(dword_107DA8 * (__int64)v1) >> 32) - (v1 >> 31);
  v3 = a1[3] - v1 / 2 + v2 + (v1 >> 31) - ((unsigned __int64)(dword_107DA4 * (__int64)v1) >> 32);
  v4 = ((unsigned __int64)(dword_107DA8 * (__int64)*a1) >> 32) - (*a1 >> 31);
  v5 = (*a1 >> 31) - ((unsigned __int64)(dword_107DA4 * (__int64)*a1) >> 32);
  v6 = a1[2] - *a1 / 2 + v4;
  result = a1 + 7;
  for ( i = 0; i != 9; i += 3 )
  {
    v9 = v6 + v5;
    v10 = result - 3;
    do
    {
      *v10++ = v9;
      v9 += v4;
      v10[8] = v3;
    }
    while ( v10 != result );
    v3 += v2;
    result = v10 + 3;
  }
  return result;
}

