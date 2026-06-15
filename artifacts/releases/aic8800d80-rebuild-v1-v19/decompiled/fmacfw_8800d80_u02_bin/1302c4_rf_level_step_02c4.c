// rf_level_step_02c4 @ 0x1302c4, size 44 bytes
// Doc: rf_level_step_02c4 [rf]: Compares two RF level bytes from a control struct
// rf_level_step_02c4 [rf]: Compares two RF level bytes from a control struct
unsigned int rf_level_step_02c4()
{
  unsigned __int8 *v0; // r4
  unsigned int result; // r0
  unsigned int v2; // r3
  unsigned __int8 v3; // r0

  v0 = (unsigned __int8 *)off_1302F0;
  result = *((unsigned __int8 *)off_1302F0 + 6);
  v2 = *((unsigned __int8 *)off_1302F0 + 5);
  if ( result != v2 )
  {
    if ( result >= v2 )
      v3 = result - 1;
    else
      v3 = result + 1;
    *((_BYTE *)off_1302F0 + 6) = v3;
    rf_reg_write_masked(v3);
    return msg_parse(dword_1302F4, v0[5], v0[6]);
  }
  return result;
}

