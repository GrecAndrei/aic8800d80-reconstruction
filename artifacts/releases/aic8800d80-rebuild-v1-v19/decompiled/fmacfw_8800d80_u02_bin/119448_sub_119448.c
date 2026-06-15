// sub_119448 @ 0x119448, size 80 bytes
// Doc: fmac_status_check_or_set [mac]: Checks a status bitmask (0x380000) and stores a parameter
// fmac_status_check_or_set [mac]: Checks a status bitmask (0x380000) and stores a parameter
__int16 *__fastcall sub_119448(__int16 *result)
{
  int v1; // r2
  int v2; // r1
  _DWORD *v3; // r4
  int v4; // r3

  v1 = *((_DWORD *)result + 19);
  if ( *(_DWORD *)(v1 + 28) )
  {
    v2 = *((_DWORD *)off_119498 + 43);
    v3 = result;
    result = *(__int16 **)off_11949C;
    do
    {
      v4 = v3[9] & 0x380000;
      *(_DWORD *)(*(_DWORD *)(v1 + 32) - 3) = v2;
      if ( v4 == 3670016 )
        break;
      v3 = (_DWORD *)*v3;
      if ( *result < 0 && !v3 )
      {
        sub_12F46C(dword_1194A4, dword_1194A0, 909);
        __und(0xFFu);
      }
      v1 = v3[19];
    }
    while ( *(_DWORD *)(v1 + 28) );
  }
  return result;
}

