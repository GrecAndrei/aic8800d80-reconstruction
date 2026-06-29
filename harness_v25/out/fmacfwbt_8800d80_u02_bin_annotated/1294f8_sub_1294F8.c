// fwstruct annotate: 1294f8_sub_1294F8.c
// sub_1294F8 @ 0x1294f8, size 150 bytes
void __fastcall sub_1294F8(int a1)
{
  _BYTE *v1; // r2
  int v2; // r3
  int v3; // r3
  int v4; // r1
  int v5; // r0
  _DWORD *v6; // r3

  v1 = off_129590;
  if ( *(_BYTE *)off_129590 )
  {
    v2 = *(unsigned __int8 *)(a1 + 29);
    if ( v2 != 255 && *(unsigned __int8 *)(a1 + 27) != 255 )
    {
      v3 = dword_129598 + 1320 * *(unsigned __int8 *)(dword_129594 + 696 * v2 + 34);
      if ( !*(_BYTE *)(v3 + 106) )
      {
        if ( *(_BYTE *)(v3 + 108) )
        {
          v4 = *((_DWORD *)off_1295A0 + 4);
          v5 = *(unsigned __int16 *)(*(_DWORD *)off_12959C + 54);
          *((_DWORD *)off_129590 + 5) = v3;
          v1[29] = 3;
          sub_124F60((int)(v1 + 12), v4 + v5);
          if ( (*(_DWORD *)off_1295A4 & 4) != 0 )
          {
            if ( *((_BYTE *)off_1295A8 + 190) )
            {
              if ( **(_BYTE **)off_1295AC == 2 )
              {
                v6 = off_1295B4;
                *(_DWORD *)off_1295B0 &= ~0x200u;
                *v6 &= ~1u;
                *v6 &= ~0x80u;
              }
            }
            sub_1290C4();
          }
        }
      }
    }
  }
}

