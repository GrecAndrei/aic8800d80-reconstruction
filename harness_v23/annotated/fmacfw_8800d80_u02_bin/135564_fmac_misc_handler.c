// v23 annotated: fmac_misc_handler @ 0x135564
// Original: 135564_fmac_misc_handler.c
// Primary struct: <unclustered>
//
// fmac_misc_handler @ 0x135564, size 48 bytes
// Doc: fmac_misc_handler [util]: fmac firmware miscellaneous handler
// fmac_misc_handler [util]: fmac firmware miscellaneous handler
_DWORD *__fastcall fmac_misc_handler(__int16 a1)
{
  int v2; // r5
  int v3; // r0

  v2 = *((_DWORD *)off_135594 + 4);
  v3 = sub_12C92C(30, 0, 6, 4u);
  *(_WORD *)v3 = a1;
  *(_BYTE *)(v3 + 2) = 1;
  *(_BYTE *)(v3 + 3) = *(_BYTE *)(v2 + 61);
  sdio_buffer_prepare_n_4e8(v3);
  return sub_12CD34(6u, 9);
}

