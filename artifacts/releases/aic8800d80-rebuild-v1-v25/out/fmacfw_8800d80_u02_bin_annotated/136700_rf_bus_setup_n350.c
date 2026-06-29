// fwstruct annotate: 136700_rf_bus_setup_n350.c
// rf_bus_setup_n350 @ 0x136700, size 42 bytes
// Doc: rf_bus_setup_n350 [rf]: RF bus setup / configuration
// rf_bus_setup_n350 [rf]: RF bus setup / configuration
_DWORD *rf_bus_setup_n350()
{
  _BYTE *v0; // r4
  int v1; // r3

  v0 = off_13672C;
  memset_thunk((int *)off_13672C, 0, 0x24u);
  v1 = dword_136730;
  v0[15] = 3;
  *((_DWORD *)v0 + 4) = 20000;
  *((_DWORD *)v0 + 6) = v1;
  v0[12] = 0;
  return sub_12CD34(7u, 0);
}

