// sub_127228 @ 0x127228, size 114 bytes
int __fastcall sub_127228(int a1)
{
  int v1; // r5
  unsigned int v3; // r7
  int v4; // r6
  int v5; // r7
  int v6; // r0
  int v8; // r0

  v1 = (unsigned __int8)((unsigned int)a1 >> 23) - 127;
  v3 = a1 & 0x7FFFFFFF;
  if ( v1 > 22 )
  {
    if ( v3 >= 0x7F800000 )
      return sub_127C90(a1, a1);
    return a1;
  }
  v4 = a1;
  if ( v1 < 0 )
  {
    v8 = sub_127C90(a1, dword_1272A0);
    if ( sub_127F78(v8, 0) )
    {
      if ( a1 >= 0 )
        return 0;
      if ( v3 )
        return dword_1272A4;
    }
    return a1;
  }
  v5 = dword_12729C >> v1;
  if ( (a1 & (dword_12729C >> v1)) == 0 )
    return a1;
  v6 = sub_127C90(a1, dword_1272A0);
  if ( !sub_127F78(v6, 0) )
    return a1;
  if ( a1 < 0 )
    v4 += 0x800000 >> v1;
  return v4 & ~v5;
}

