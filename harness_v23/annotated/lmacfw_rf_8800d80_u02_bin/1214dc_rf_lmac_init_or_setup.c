// v23 annotated: rf_lmac_init_or_setup @ 0x1214dc
// Original: 1214dc_rf_lmac_init_or_setup.c
// Primary struct: <unclustered>
//
// rf_lmac_init_or_setup @ 0x1214dc, size 42 bytes
// Doc: rf_lmac_init_or_setup [rf]: LMAC RF setup helper that loads config pointer and dispatches to sub-handler
// rf_lmac_init_or_setup [rf]: LMAC RF setup helper that loads config pointer and dispatches to sub-handler
int __fastcall rf_lmac_init_or_setup(int a1, _DWORD *a2, __int16 a3, __int16 a4)
{
  msg_parse(dword_121508, *a2);
  *((_DWORD *)off_12150C + 1) = *a2;
  sub_11DED8(1031, a4, a3);
  return 0;
}

