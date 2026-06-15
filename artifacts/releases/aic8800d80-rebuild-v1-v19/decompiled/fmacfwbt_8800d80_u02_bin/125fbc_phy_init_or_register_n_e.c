// phy_init_or_register_n_e @ 0x125fbc, size 42 bytes
// Doc: phy_init_or_register_n_e [rf]: PHY init/register write with val 0x48
// phy_init_or_register_n_e [rf]: PHY init/register write with val 0x48
int __fastcall phy_init_or_register_n_e(int a1)
{
  _BYTE *v2; // r0
  _DWORD *v3; // r2

  v2 = (_BYTE *)rf_bus_setup_n3a8(72, *(unsigned __int16 *)(a1 + 14), 0, 2);
  v2[1] = *(_BYTE *)(a1 + 24);
  v3 = off_125FE8;
  *v2 = *(_BYTE *)(a1 + 26);
  *v3 &= ~4u;
  return sub_12CBB4(v2);
}

