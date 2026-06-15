// v23 annotated: sub_115398 @ 0x115398
// Original: 115398_sub_115398.c
// Primary struct: <unclustered>
//
// sub_115398 @ 0x115398, size 180 bytes
int sub_115398()
{
  _BYTE *v0; // r4
  int result; // r0
  _DWORD *v2; // r3
  int v3; // r3

  v0 = off_11544C;
  if ( !*(_BYTE *)off_11544C && *(_BYTE *)off_115450 )
  {
    result = sub_12EB90(2, dword_11545C);
    v2 = off_115460;
    *v0 = 1;
    if ( (unsigned __int16)*v2 )
    {
      switch ( *(_BYTE *)off_115464 )
      {
        case 1:
          v3 = 700 * (unsigned __int16)*(_DWORD *)off_115460;
          break;
        case 2:
          v3 = 500 * (unsigned __int16)*(_DWORD *)off_115460;
          break;
        case 3:
          v3 = 300 * (unsigned __int16)*(_DWORD *)off_115460;
          break;
        case 4:
          v3 = 200 * (unsigned __int16)*(_DWORD *)off_115460;
          break;
        case 5:
          v3 = 100 * (unsigned __int16)*(_DWORD *)off_115460;
          break;
        default:
          v3 = 100 * (unsigned __int16)*(_DWORD *)off_115460;
          break;
      }
      return sub_124BFC(dword_11546C, *((_DWORD *)off_115468 + 4) + v3);
    }
  }
  else
  {
    result = sub_12EB90(2, dword_115454);
    if ( *((_BYTE *)off_115458 + 18) )
      *v0 = 0;
  }
  return result;
}

