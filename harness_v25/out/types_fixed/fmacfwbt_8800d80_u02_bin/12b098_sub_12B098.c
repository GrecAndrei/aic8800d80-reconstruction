// sub_12B098 @ 0x12b098, size 128 bytes
// Doc: sub_122B098 [util]: Branch on r1 == 0x1f, small utility stub
// sub_122B098 [util]: Branch on r1 == 0x1f, small utility stub
int __fastcall sub_12B098(int a1, unsigned int a2, int a3)
{
  int result; // r0
  int v4; // r1
  unsigned int v5; // r3
  int v6; // r1
  unsigned int v7; // r2
  int v8; // r2

  if ( a2 <= 0x1F )
  {
    if ( a3 )
    {
      result = dword_12B118 + 32 * a1;
      v4 = 3 * a2 + dword_12B11C;
      v5 = *(unsigned __int8 *)(v4 + 2);
      ++*(_DWORD *)(result + 20);
      if ( v5 <= 2 )
        *(_BYTE *)(v4 + 2) = v5 + 1;
    }
    else
    {
      result = dword_12B118 + 32 * a1;
      v6 = 3 * a2 + dword_12B11C;
      v7 = *(unsigned __int8 *)(v6 + 1);
      ++*(_DWORD *)(result + 16);
      if ( v7 <= 2 )
        *(_BYTE *)(v6 + 1) = v7 + 1;
    }
  }
  else
  {
    if ( a3 )
    {
      v8 = **(__int16 **)off_12B120;
      ++*(_DWORD *)(dword_12B118 + 32 * a1 + 20);
      if ( v8 < 0 )
        sub_12F694(dword_12B128, dword_12B124, 365);
      __und(0xFFu);
    }
    result = dword_12B118 + 32 * a1;
    ++*(_DWORD *)(result + 16);
  }
  return result;
}

