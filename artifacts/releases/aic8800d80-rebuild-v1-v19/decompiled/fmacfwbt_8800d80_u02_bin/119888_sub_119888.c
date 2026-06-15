// sub_119888 @ 0x119888, size 80 bytes
// Doc: rf_chan_set_check [rf]: Validate and apply channel configuration bits
// rf_chan_set_check [rf]: Validate and apply channel configuration bits
__int16 *__fastcall sub_119888(__int16 *result)
{
  int v1; // r2
  int v2; // r1
  _DWORD *v3; // r4
  int v4; // r3

  v1 = *((_DWORD *)result + 19);
  if ( *(_DWORD *)(v1 + 28) )
  {
    v2 = *((_DWORD *)off_1198D8 + 43);
    v3 = result;
    result = *(__int16 **)off_1198DC;
    do
    {
      v4 = v3[9] & 0x380000;
      *(_DWORD *)(*(_DWORD *)(v1 + 32) - 3) = v2;
      if ( v4 == 3670016 )
        break;
      v3 = (_DWORD *)*v3;
      if ( *result < 0 && !v3 )
      {
        sub_12F694(dword_1198E4, dword_1198E0, 909);
        __und(0xFFu);
      }
      v1 = v3[19];
    }
    while ( *(_DWORD *)(v1 + 28) );
  }
  return result;
}

