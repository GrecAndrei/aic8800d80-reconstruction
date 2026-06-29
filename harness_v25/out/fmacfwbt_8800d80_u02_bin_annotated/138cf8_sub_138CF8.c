// fwstruct annotate: 138cf8_sub_138CF8.c
// sub_138CF8 @ 0x138cf8, size 170 bytes
int __fastcall sub_138CF8(_WORD *a1)
{
  int v2; // r7
  int v3; // r5
  int i; // r4
  int v6; // r10
  _DWORD *v7; // r4

  if ( *((unsigned __int8 *)off_138DA4 + 16) == 255 || (*a1 & 0xEC) != 0xC4 )
  {
    v2 = dword_138DA8;
    v3 = 0;
    for ( i = dword_138DA8; ; i += 1320 )
    {
      if ( *(_BYTE *)(i + 108) )
      {
        if ( *(_BYTE *)(i + 106) == 2 )
        {
          v6 = 1320 * v3;
          if ( !sub_1437AC(a1 + 2, i + 100, 6) )
            break;
        }
      }
      if ( ++v3 == 4 )
        return 0;
    }
    v7 = *(_DWORD **)(v2 + v6 + 240);
    if ( v7 )
    {
      while ( sub_1437AC(a1 + 5, (char *)v7 + 38, 6) )
      {
        v7 = (_DWORD *)*v7;
        if ( !v7 )
          goto LABEL_14;
      }
      sub_12ECB0(dword_138DAC, (unsigned __int16)a1[5], (unsigned __int16)a1[6], (unsigned __int16)a1[7]);
    }
    else
    {
LABEL_14:
      sub_12ECB0(dword_138DB4, dword_138DB0, (unsigned __int16)a1[5], (unsigned __int16)a1[6], (unsigned __int16)a1[7]);
      sub_136E98(v2 + v6, (int)(a1 + 5));
    }
  }
  return 0;
}

