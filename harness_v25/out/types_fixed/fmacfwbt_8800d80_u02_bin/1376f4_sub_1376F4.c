// sub_1376F4 @ 0x1376f4, size 76 bytes
int __fastcall sub_1376F4(unsigned __int16 *a1, int a2)
{
  int v2; // r3
  int v3; // r4

  v2 = dword_137740;
  v3 = dword_137740 + 3840;
  do
  {
    while ( !*(_BYTE *)v2 )
    {
      if ( a2 )
      {
        *(_BYTE *)(v2 + 56) = 0x80;
        return v2;
      }
LABEL_3:
      v2 += 60;
      if ( v2 == v3 )
        return 0;
    }
    if ( *(unsigned __int16 *)(v2 + 2) != *a1 || *(unsigned __int16 *)(v2 + 4) != *(_DWORD *)(a1 + 0x4) )
      goto LABEL_3;
    if ( *(unsigned __int16 *)(v2 + 6) == *(_DWORD *)(a1 + 0x8) )
      return v2;
    v2 += 60;
  }
  while ( v2 != v3 );
  return 0;
}

