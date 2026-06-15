// sub_1042BC @ 0x1042bc, size 258 bytes
int sub_1042BC()
{
  BOOL v0; // r1
  int v1; // r2
  int *v2; // r4
  int v3; // r7
  int *v4; // r5
  int v5; // r6
  int v6; // lr
  int v7; // r12
  int v8; // r9
  int v9; // r8
  int v10; // r1
  int v11; // r0
  unsigned int v12; // r0
  unsigned int v13; // r3
  __int16 v14; // r2
  int result; // r0
  int v16; // r3

  v0 = (dword_100000[0] & 1) == 0;
  v1 = 0;
  v2 = (int *)(4 * (v0 + 0x40000));
  v3 = v0 + 278528;
  v4 = v2;
  v5 = 4 * (v0 + 278528);
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  do
  {
    v10 = (unsigned int)*v4 >> 20;
    if ( *v4 < 0 )
      v10 -= 4096;
    v11 = (unsigned __int16)*v4 >> 4;
    if ( (((unsigned int)*v4 >> 4) & 0x800) != 0 )
      v11 -= 4096;
    if ( v7 < v10 )
      v7 = v10;
    v4 += 2;
    if ( v6 < v11 )
      v6 = v11;
    if ( v1 >= v10 )
      v1 = v10;
    v9 += v10;
    v8 += v11;
  }
  while ( v4 != (int *)v5 );
  if ( v7 > 2040 || v6 > 2040 || v1 < -2040 )
    sub_12EB90(1, dword_1043C0);
  sub_12EB90(1, dword_1043C4);
  do
  {
    v12 = *v2;
    v13 = (unsigned int)*v2 >> 20;
    if ( *v2 < 0 )
      LOWORD(v13) = v13 - 4096;
    v14 = (unsigned __int16)v12 >> 4;
    result = v12 >> 4 << 20;
    v16 = (__int16)(v13 - v9 / 0x2000);
    if ( result < 0 )
      v14 -= 4096;
    *v2 = ((v16 + (v16 < 0 ? 0x1000 : 0)) << 20)
        + 65537
        + 16 * ((__int16)(v14 - v8 / 0x2000) + ((__int16)(v14 - v8 / 0x2000) < 0 ? 0x1000 : 0));
    v2 += 2;
  }
  while ( (int *)(4 * v3) != v2 );
  return result;
}

