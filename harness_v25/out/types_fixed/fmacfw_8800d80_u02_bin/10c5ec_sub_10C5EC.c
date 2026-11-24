// sub_10C5EC @ 0x10c5ec, size 74 bytes
void __fastcall sub_10C5EC(int a1, int a2)
{
  int *v2; // r2
  unsigned __int16 *v3; // r3
  int *v4; // r5
  unsigned __int16 *v5; // r4
  int v7; // r0
  unsigned __int8 v8; // [sp+20h] [bp+18h]
  unsigned __int8 v9; // [sp+24h] [bp+1Ch]

  v4 = v2;
  v5 = v3;
  sub_101F70(a1, a2, a2, 0);
  tx_phy_config(v4, (unsigned int)v5, v8, v9);
  if ( v8 )
  {
    if ( a1 == 1 )
      v7 = 28;
    else
      v7 = 3;
    rf_level_apply_n_18c(v7, v5);
  }
}
