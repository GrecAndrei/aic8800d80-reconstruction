// fmac_unknown_handler @ 0x1325f4, size 26 bytes
// Doc: fmac_unknown_handler [unknown]: Unidentified FMAC helper
// fmac_unknown_handler [unknown]: Unidentified FMAC helper
int __fastcall fmac_unknown_handler(unsigned __int8 *a1)
{
  if ( *(_DWORD *)(a1 + 0xc) )
    return 3;
  if ( *(_DWORD *)(a1 + 0x8) )
    return 2;
  return *(_DWORD *)(a1 + 0x4) != 0;
}

