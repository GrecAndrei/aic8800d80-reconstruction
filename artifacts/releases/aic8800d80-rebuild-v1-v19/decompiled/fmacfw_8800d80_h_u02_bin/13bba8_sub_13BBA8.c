// sub_13BBA8 @ 0x13bba8, size 108 bytes
int __fastcall sub_13BBA8(int result)
{
  int v1; // r4
  int v2; // r5
  int v3; // r10
  int v4; // r7
  __int16 v5; // r9
  int v6; // r6
  int v7; // t1

  v1 = dword_13BC14;
  v2 = dword_13BC18;
  v3 = dword_13BC1C;
  v4 = result;
  v5 = -128 * dword_13BC14;
  v6 = dword_13BC14 + 64;
  do
  {
    v7 = *(unsigned __int16 *)(v1 + 2);
    v1 += 2;
    if ( v7 )
    {
      if ( *(unsigned __int8 *)(v2 + 16) == v4 )
      {
        sub_12CBF4((unsigned __int16)(v5 + ((_WORD)v1 << 7) - 256) | 8, 4);
        *(_BYTE *)(v2 + 25) = 0;
        result = sub_13B558(v4, v2, 2, 0, 0, 39, v3);
      }
    }
    v2 += 32;
  }
  while ( v1 != v6 );
  return result;
}

