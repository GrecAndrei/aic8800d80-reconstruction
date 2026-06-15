// rf_level_step @ 0x126da4, size 44 bytes
// Doc: rf_level_apply_n_a [rf]: applies RF level/threshold configuration
// rf_level_apply_n_a [rf]: applies RF level/threshold configuration
unsigned int rf_level_step()
{
  unsigned __int8 *v0; // r4
  unsigned int result; // r0
  unsigned int v2; // r3
  unsigned __int8 v3; // r0

  v0 = (unsigned __int8 *)rf_level_apply_n_8;
  result = *((unsigned __int8 *)rf_level_apply_n_8 + 6);
  v2 = *((unsigned __int8 *)rf_level_apply_n_8 + 5);
  if ( result != v2 )
  {
    if ( result >= v2 )
      v3 = result - 1;
    else
      v3 = result + 1;
    *((_BYTE *)rf_level_apply_n_8 + 6) = v3;
    sub_10F170(v3);
    return msg_parse(dword_126DD4, v0[5], v0[6]);
  }
  return result;
}

