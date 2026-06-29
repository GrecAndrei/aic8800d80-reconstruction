// sub_14274C @ 0x14274c, size 114 bytes
int  sub_14274C(int a1)
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
      return sub_1431B4(a1, a1);
    return a1;
  }
  v4 = a1;
  if ( v1 < 0 )
  {
    v8 = sub_1431B4(a1, dword_1427C4);
    if ( sub_14349C(v8, 0) )
    {
      if ( a1 >= 0 )
        return 0;
      if ( v3 )
        return dword_1427C8;
    }
    return a1;
  }
  v5 = dword_1427C0 >> v1;
  if ( (a1 & (dword_1427C0 >> v1)) == 0 )
    return a1;
  v6 = sub_1431B4(a1, dword_1427C4);
  if ( !sub_14349C(v6, 0) )
    return a1;
  if ( a1 < 0 )
    v4 += 0x800000 >> v1;
  return v4 & ~v5;
}

