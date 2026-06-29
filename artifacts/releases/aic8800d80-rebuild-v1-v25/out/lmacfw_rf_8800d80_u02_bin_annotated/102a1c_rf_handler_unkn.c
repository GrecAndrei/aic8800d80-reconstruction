// fwstruct annotate: 102a1c_rf_handler_unkn.c
// rf_handler_unkn @ 0x102a1c, size 38 bytes
// Doc: rf_handler_unkn [rf]: Unidentified RF helper routine
// rf_handler_unkn [rf]: Unidentified RF helper routine
int rf_handler_unkn()
{
  int result; // r0

  result = msg_parse(dword_102A48, dword_102A44);
  if ( **(__int16 **)off_102A4C < 0 )
    return rf_cmd_send_n264(dword_102A54, dword_102A50, 61);
  return result;
}

