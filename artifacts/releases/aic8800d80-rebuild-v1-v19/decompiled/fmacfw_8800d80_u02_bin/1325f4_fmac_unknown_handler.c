// fmac_unknown_handler @ 0x1325f4, size 26 bytes
// Doc: fmac_unknown_handler [unknown]: Unidentified FMAC helper
// fmac_unknown_handler [unknown]: Unidentified FMAC helper
int __fastcall fmac_unknown_handler(unsigned __int8 *a1)
{
  if ( a1[3] )
    return 3;
  if ( a1[2] )
    return 2;
  return a1[1] != 0;
}

