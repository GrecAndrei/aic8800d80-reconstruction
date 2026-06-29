// fwstruct annotate: 13afc0_bt_fw_struct_reset_n_afc0.c
// bt_fw_struct_reset_n_afc0 @ 0x13afc0, size 24 bytes
// Doc: bt_fw_struct_reset_n_afc0 [bt]: Resets BT firmware context struct flags and counters
// bt_fw_struct_reset_n_afc0 [bt]: Resets BT firmware context struct flags and counters
int __fastcall bt_fw_struct_reset_n_afc0(int a1, int a2)
{
  __int16 v2; // r2

  v2 = *(_WORD *)(a1 + 30) | 1;
  *(_DWORD *)(a1 + 68) = 0;
  *(_DWORD *)(a1 + 80) = 0;
  *(_WORD *)(a1 + 30) = v2;
  return sub_13AC44(a1, a2);
}

