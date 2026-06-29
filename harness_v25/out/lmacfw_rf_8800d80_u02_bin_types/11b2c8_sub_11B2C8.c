// sub_11B2C8 @ 0x11b2c8, size 134 bytes
// Doc: sub_121B2C8 [unknown]: Checks a flag byte from a global struct and shifts it, branches on result
// sub_121B2C8 [unknown]: Checks a flag byte from a global struct and shifts it, branches on result
int sub_11B2C8()
{
  uint8_t *v0; // r4
  int v1; // r3
  int result; // r0

  v0 = off_11B350;
  v1 = *((unsigned __int8 *)off_11B350 + 88);
  result = v1 << 31;
  if ( (v1 & 1) != 0 )
  {
    if ( **(__int16 **)off_11B354 < 0 && (v1 & 4) != 0 )
    {
      rf_cmd_send_n264(dword_11B364, dword_11B360, 1720);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xFA | 4;
    return rf_mailbox_post_n44(dword_11B358);
  }
  else if ( (v1 & 6) == 2 )
  {
    if ( **(__int16 **)off_11B354 < 0 && (v1 & 8) != 0 )
    {
      rf_cmd_send_n264(dword_11B368, dword_11B360, 1731);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xF5 | 8;
    return rf_mailbox_post_n44(dword_11B35C);
  }
  return result;
}

