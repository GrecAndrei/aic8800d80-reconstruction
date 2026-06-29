// sub_119888 @ 0x119888, size 80 bytes
// Doc: rf_chan_set_check [rf]: Validate and apply channel configuration bits
// rf_chan_set_check [rf]: Validate and apply channel configuration bits
__int16 * sub_119888(__int16 *result)
{
  int v1; // r2
  int v2; // r1
  uint32_t *v3; // r4
  int v4; // r3

  v1 = *((uint32_t *)result + 19);
  if ( *(uint32_t *)(v1 + 28) )
  {
    v2 = *((uint32_t *)off_1198D8 + 43);
    v3 = result;
    result = *(__int16 **)off_1198DC;
    do
    {
      v4 = v3[9] & 0x380000;
      *(uint32_t *)(*(uint32_t *)(v1 + 32) - 3) = v2;
      if ( v4 == 3670016 )
        break;
      v3 = (uint32_t *)*v3;
      if ( *result < 0 && !v3 )
      {
        sub_12F694(dword_1198E4, dword_1198E0, 909);
        __und(0xFFu);
      }
      v1 = v3[19];
    }
    while ( *(uint32_t *)(v1 + 28) );
  }
  return result;
}

