// sub_115F78 @ 0x115f78, size 58 bytes
int __fastcall sub_115F78(int a1)
{
  _DWORD *v1; // r6
  _DWORD *v2; // r7
  int v3; // r2
  _DWORD *v4; // r4
  int result; // r0
  int *v6; // r1
  int v7; // r3
  int v8; // t1

  v1 = off_115FB4;
  v2 = off_115FB8;
  v3 = a1 - 4;
  v4 = off_115FB4;
  result = a1 + 12;
  v6 = (int *)off_115FB8;
  do
  {
    v8 = *(_DWORD *)(v3 + 4);
    v3 += 4;
    v7 = v8;
    if ( !v8 )
      v7 = *v6;
    *v4++ = 1000 * v7;
    ++v6;
  }
  while ( v3 != result );
  v1[4] = 1000 * v2[4];
  return result;
}

