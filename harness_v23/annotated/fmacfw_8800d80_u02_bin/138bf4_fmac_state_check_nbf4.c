// v23 annotated: fmac_state_check_nbf4 @ 0x138bf4
// Original: 138bf4_fmac_state_check_nbf4.c
// Primary struct: <unclustered>
//
// fmac_state_check_nbf4 @ 0x138bf4, size 170 bytes
// Doc: fmac_state_check_nbf4 [util]: Check FMAC state flag and dispatch
// fmac_state_check_nbf4 [util]: Check FMAC state flag and dispatch
int __fastcall fmac_state_check_nbf4(_WORD *a1)
{
  int v2; // r7
  int v3; // r5
  int i; // r4
  int v6; // r10
  _DWORD *v7; // r4

  if ( *((unsigned __int8 *)off_138CA0 + 16) == 255 || (*a1 & 0xEC) != 0xC4 )
  {
    v2 = dword_138CA4;
    v3 = 0;
    for ( i = dword_138CA4; ; i += 1320 )
    {
      if ( *(_BYTE *)(i + 108) )
      {
        if ( *(_BYTE *)(i + 106) == 2 )
        {
          v6 = 1320 * v3;
          if ( !sub_143710(a1 + 2, i + 100, 6) )
            break;
        }
      }
      if ( ++v3 == 4 )
        return 0;
    }
    v7 = *(_DWORD **)(v2 + v6 + 240);
    if ( v7 )
    {
      while ( sub_143710(a1 + 5, (char *)v7 + 38, 6) )
      {
        v7 = (_DWORD *)*v7;
        if ( !v7 )
          goto LABEL_14;
      }
      msg_parse(dword_138CA8, (unsigned __int16)a1[5], (unsigned __int16)a1[6], (unsigned __int16)a1[7]);
    }
    else
    {
LABEL_14:
      msg_parse(dword_138CB0, dword_138CAC, (unsigned __int16)a1[5], (unsigned __int16)a1[6], (unsigned __int16)a1[7]);
      sub_136D6C(v2 + v6, (int)(a1 + 5));
    }
  }
  return 0;
}

