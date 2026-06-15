// v23 annotated: sub_136BD4 @ 0x136bd4
// Original: 136bd4_sub_136BD4.c
// Primary struct: <unclustered>
//
// sub_136BD4 @ 0x136bd4, size 84 bytes
int __fastcall sub_136BD4(int result, int a2)
{
  int v2; // r4
  char v3; // r1
  int v4; // r0
  __int16 v5; // r1

  if ( *(_BYTE *)(result + 106) == 2 )
  {
    v2 = dword_136C28 + 696 * a2;
    result = sub_11F28C(result, v2, 0);
    v3 = *(_BYTE *)(v2 + 53);
    if ( (v3 & 0xA) != 0 )
    {
      *(_BYTE *)(v2 + 53) = v3 & 0xF5;
      if ( (v3 & 0xF5) == 0 )
      {
        v4 = sub_12C7EC(65, 0, 5, 4u);
        v5 = *(_WORD *)(v2 + 32);
        *(_BYTE *)(v4 + 3) = *(_BYTE *)(v2 + 34);
        *(_BYTE *)(v4 + 2) = 0;
        *(_WORD *)v4 = v5;
        return sub_12C84C(v4);
      }
    }
  }
  return result;
}

