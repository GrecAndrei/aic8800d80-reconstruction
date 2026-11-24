// sub_119BF8 @ 0x119bf8, size 66 bytes
// Doc: rf_param_handler [rf]: Validates and dispatches RF parameter configuration
// rf_param_handler [rf]: Validates and dispatches RF parameter configuration
int __fastcall sub_119BF8(int a1, unsigned __int8 *a2, int a3, int a4)
{
  unsigned int v7; // r0

  if ( **(__int16 **)off_119C3C < 0 )
  {
    v7 = *a2;
    if ( v7 <= HIBYTE(*(_DWORD *)off_119C40) )
      goto LABEL_3;
    rf_cmd_send_n264(dword_119C48, dword_119C44, 1803);
  }
  v7 = *a2;
LABEL_3:
  sub_118C90(v7);
  sub_11DED8(39, a4, a3);
  return 0;
}

