// rf_level_step_04e0 @ 0x1304e0, size 44 bytes
// Doc: rf_level_step_04e0 [rf]: Step RF TX power level by configured delta
// rf_level_step_04e0 [rf]: Step RF TX power level by configured delta
unsigned int rf_level_step_04e0()
{
  unsigned __int8 *v0; // r4
  unsigned int result; // r0
  unsigned int v2; // r3
  unsigned __int8 v3; // r0

  v0 = (unsigned __int8 *)off_13050C;
  result = *((unsigned __int8 *)off_13050C + 6);
  v2 = *((unsigned __int8 *)off_13050C + 5);
  if ( result != v2 )
  {
    if ( result >= v2 )
      v3 = result - 1;
    else
      v3 = result + 1;
    *((uint8_t *)off_13050C + 6) = v3;
    sub_10ED90(v3);
    return sub_12ECB0(dword_130510, v0[5], v0[6]);
  }
  return result;
}

