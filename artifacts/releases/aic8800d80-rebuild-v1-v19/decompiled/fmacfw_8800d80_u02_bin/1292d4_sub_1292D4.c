// sub_1292D4 @ 0x1292d4, size 150 bytes
void __fastcall sub_1292D4(int a1)
{
  _BYTE *v1; // r2
  int v2; // r3
  int v3; // r3
  int v4; // r1
  int v5; // r0
  _DWORD *v6; // r3

  v1 = off_12936C;
  if ( *(_BYTE *)off_12936C )
  {
    v2 = *(unsigned __int8 *)(a1 + 29);
    if ( v2 != 255 && *(unsigned __int8 *)(a1 + 27) != 255 )
    {
      v3 = dword_129374 + 1320 * *(unsigned __int8 *)(dword_129370 + 696 * v2 + 34);
      if ( !*(_BYTE *)(v3 + 106) )
      {
        if ( *(_BYTE *)(v3 + 108) )
        {
          v4 = *((_DWORD *)off_12937C + 4);
          v5 = *(unsigned __int16 *)(*(_DWORD *)off_129378 + 54);
          *((_DWORD *)off_12936C + 5) = v3;
          v1[29] = 3;
          timestamp_update((int)(v1 + 12), v4 + v5);
          if ( (*(_DWORD *)off_129380 & 4) != 0 )
          {
            if ( *((_BYTE *)off_129384 + 190) )
            {
              if ( **(_BYTE **)off_129388 == 2 )
              {
                v6 = off_129390;
                *(_DWORD *)off_12938C &= ~0x200u;
                *v6 &= ~1u;
                *v6 &= ~0x80u;
              }
            }
            sub_128EA0();
          }
        }
      }
    }
  }
}

