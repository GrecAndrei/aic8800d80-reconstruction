// v23 annotated: sub_129194 @ 0x129194
// Original: 129194_sub_129194.c
// Primary struct: <unclustered>
//
// sub_129194 @ 0x129194, size 150 bytes
void __fastcall sub_129194(int a1)
{
  _BYTE *v1; // r2
  int v2; // r3
  int v3; // r3
  int v4; // r1
  int v5; // r0
  _DWORD *v6; // r3

  v1 = off_12922C;
  if ( *(_BYTE *)off_12922C )
  {
    v2 = *(unsigned __int8 *)(a1 + 29);
    if ( v2 != 255 && *(unsigned __int8 *)(a1 + 27) != 255 )
    {
      v3 = dword_129234 + 1320 * *(unsigned __int8 *)(dword_129230 + 696 * v2 + 34);
      if ( !*(_BYTE *)(v3 + 106) )
      {
        if ( *(_BYTE *)(v3 + 108) )
        {
          v4 = *((_DWORD *)off_12923C + 4);
          v5 = *(unsigned __int16 *)(*(_DWORD *)off_129238 + 54);
          *((_DWORD *)off_12922C + 5) = v3;
          v1[29] = 3;
          sub_124BFC((int)(v1 + 12), v4 + v5);
          if ( (*(_DWORD *)off_129240 & 4) != 0 )
          {
            if ( *((_BYTE *)off_129244 + 190) )
            {
              if ( **(_BYTE **)off_129248 == 2 )
              {
                v6 = off_129250;
                *(_DWORD *)off_12924C &= ~0x200u;
                *v6 &= ~1u;
                *v6 &= ~0x80u;
              }
            }
            sub_128D60();
          }
        }
      }
    }
  }
}

