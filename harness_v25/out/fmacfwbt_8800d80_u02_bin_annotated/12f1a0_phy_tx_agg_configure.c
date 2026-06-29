// fwstruct annotate: 12f1a0_phy_tx_agg_configure.c
// phy_tx_agg_configure @ 0x12f1a0, size 42 bytes
// Doc: phy_tx_agg_configure [tx]: Configure TX aggregation via sub_12ECB0
// phy_tx_agg_configure [tx]: Configure TX aggregation via sub_12ECB0
int __fastcall phy_tx_agg_configure(int a1, _DWORD *a2, __int16 a3, __int16 a4)
{
  sub_12ECB0(dword_12F1CC, *a2);
  *((_DWORD *)off_12F1D0 + 1) = *a2;
  message_dispatch_n84(1031, a4, a3);
  return 0;
}

