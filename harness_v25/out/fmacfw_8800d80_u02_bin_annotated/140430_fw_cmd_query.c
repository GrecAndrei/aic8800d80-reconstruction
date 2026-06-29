// fwstruct annotate: 140430_fw_cmd_query.c
// fw_cmd_query @ 0x140430, size 50 bytes
// Doc: fw_cmd_query [ipc]: Queries firmware command status (op 0xb)
// fw_cmd_query [ipc]: Queries firmware command status (op 0xb)
int fw_cmd_query()
{
  if ( msg_get_value(0xBu) == 1 )
  {
    sub_1415EC();
    return 0;
  }
  else
  {
    if ( **(__int16 **)off_140464 < 0 )
      sub_12F49C(dword_14046C, dword_140468, 157);
    return 0;
  }
}

