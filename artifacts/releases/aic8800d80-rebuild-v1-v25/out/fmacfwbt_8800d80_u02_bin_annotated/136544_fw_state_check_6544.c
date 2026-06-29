// fwstruct annotate: 136544_fw_state_check_6544.c
// fw_state_check_6544 @ 0x136544, size 56 bytes
// Doc: fw_state_check_6544 [util]: Read global halfword and branch on zero/nonzero
// fw_state_check_6544 [util]: Read global halfword and branch on zero/nonzero
int fw_state_check_6544()
{
  if ( **(__int16 **)off_13657C >= 0 || msg_get_value(7u) == 2 )
  {
    sub_136890(0);
    return 0;
  }
  else
  {
    sub_12F694(dword_136584, dword_136580, 388);
    sub_136890(0);
    return 0;
  }
}

