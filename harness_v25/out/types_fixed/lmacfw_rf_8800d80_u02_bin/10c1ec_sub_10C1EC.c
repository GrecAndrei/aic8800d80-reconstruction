// sub_10C1EC @ 0x10c1ec, size 238 bytes
void __fastcall sub_10C1EC(int a1, int a2)
{
  int *v2; // r2
  unsigned __int16 *v3; // r3
  int *v5; // r6
  unsigned __int16 *v6; // r4
  _DWORD *v7; // r10
  _DWORD *v8; // r11
  unsigned __int8 v9; // [sp+30h] [bp+24h]
  unsigned __int8 v10; // [sp+34h] [bp+28h]

  v5 = v2;
  v6 = v3;
  sub_101E18(a1, a2, a2, 0);
  if ( a1 == 1 )
  {
    v7 = off_10C2DC;
    v8 = off_10C2E0;
    *(_DWORD *)off_10C2DC &= ~0x400u;
    *v8 |= 0x8000000u;
    rf_init_or_config_helper(1);
    tx_phy_config(v5, (unsigned int)v6, v9, v10);
    if ( v9 )
    {
      sub_102BB0(28, v6);
      *v8 &= ~0x8000000u;
      *v7 |= 0x400u;
      rf_init_or_config_helper(0);
      tx_phy_config(v5, (unsigned int)v6, v9, v10);
      sub_102BB0(28, v6);
    }
    else
    {
      *v8 &= ~0x8000000u;
      *v7 |= 0x400u;
      rf_init_or_config_helper(0);
      tx_phy_config(v5, (unsigned int)v6, 0, v10);
    }
  }
  else
  {
    tx_phy_config(v5, (unsigned int)v6, v9, v10);
    if ( v9 )
      sub_102BB0(3, v6);
  }
}
