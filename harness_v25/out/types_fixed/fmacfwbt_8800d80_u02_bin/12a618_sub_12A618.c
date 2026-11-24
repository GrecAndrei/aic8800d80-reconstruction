// sub_12A618 @ 0x12a618, size 106 bytes
int __fastcall sub_12A618(int result, _BYTE *a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r6
  int v6; // r5
  int v7; // [sp+4h] [bp-4h]

  if ( *(_DWORD *)(a2 + 0x60) == 127 && !*(_DWORD *)(a2 + 0x74) && (unsigned __int8)*(_DWORD *)(a2 + 0x7c) == 221 && *(_DWORD *)(a2 + 0x90) == 9 )
  {
    v4 = (int)(a2 + 37);
    if ( *(_DWORD *)(a2 + 0x94) == 12 )
    {
      v5 = *(unsigned __int8 *)(result + 1225);
      v6 = result;
      if ( **(__int16 **)off_12A684 < 0 )
      {
        if ( *(_BYTE *)(result + 106) )
        {
          v7 = a4;
          sub_12F694(dword_12A68C, dword_12A688, 64);
          a4 = v7;
        }
      }
      return sub_129FAC(v5, v4, *(_DWORD *)(v6 + 132) + a4);
    }
  }
  return result;
}

