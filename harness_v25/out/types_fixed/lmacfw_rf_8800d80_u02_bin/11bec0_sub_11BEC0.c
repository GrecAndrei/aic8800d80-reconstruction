// sub_11BEC0 @ 0x11bec0, size 102 bytes
int __fastcall sub_11BEC0(int result, int a2)
{
  int v2; // r4
  int v3; // r5
  int v5; // r7
  unsigned int v6; // r3
  int v7; // r8

  v2 = *(unsigned __int8 *)(result + 1);
  v3 = dword_11BF2C;
  if ( **(__int16 **)off_11BF28 < 0 )
  {
    v7 = dword_11BF2C + 28 * v2;
    v5 = 8 * v2;
    v6 = *(unsigned __int8 *)(v7 + 16);
    if ( !*(_BYTE *)(v7 + 16) )
    {
      result = sub_1219C4(dword_11BF34, dword_11BF30, 3289);
      if ( *(unsigned __int8 *)(v7 + 16) <= 3u )
        goto LABEL_4;
      return sub_11DED8(62, a2, 0);
    }
  }
  else
  {
    v5 = 8 * v2;
    v6 = *(unsigned __int8 *)(dword_11BF2C + 28 * v2 + 16);
  }
  if ( v6 <= 3 )
  {
LABEL_4:
    *(_WORD *)(v3 + 4 * (v5 - v2) + 14) = a2;
    return result;
  }
  return sub_11DED8(62, a2, 0);
}

