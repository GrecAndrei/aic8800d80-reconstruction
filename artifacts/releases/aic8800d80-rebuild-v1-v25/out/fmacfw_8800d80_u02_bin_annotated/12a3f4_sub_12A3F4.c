// fwstruct annotate: 12a3f4_sub_12A3F4.c
// sub_12A3F4 @ 0x12a3f4, size 106 bytes
// Doc: sub_122A3F4 [util]: Check byte field against 0x7f and branch accordingly
// sub_122A3F4 [util]: Check byte field against 0x7f and branch accordingly
int __fastcall sub_12A3F4(int result, _BYTE *a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r6
  int v6; // r5
  int v7; // [sp+4h] [bp-4h]

  if ( a2[24] == 127 && !a2[29] && (unsigned __int8)a2[31] == 221 && a2[36] == 9 )
  {
    v4 = (int)(a2 + 37);
    if ( a2[37] == 12 )
    {
      v5 = *(unsigned __int8 *)(result + 1225);
      v6 = result;
      if ( **(__int16 **)off_12A460 < 0 )
      {
        if ( *(_BYTE *)(result + 106) )
        {
          v7 = a4;
          sub_12F46C(dword_12A468, dword_12A464, 64);
          a4 = v7;
        }
      }
      return sub_129D88(v5, v4, *(_DWORD *)(v6 + 132) + a4);
    }
  }
  return result;
}

