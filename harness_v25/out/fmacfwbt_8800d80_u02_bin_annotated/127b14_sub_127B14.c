// fwstruct annotate: 127b14_sub_127B14.c
// sub_127B14 @ 0x127b14, size 94 bytes
int __fastcall sub_127B14(int a1)
{
  int result; // r0
  char v3; // r3
  int v4; // r3

  result = timestamp_update_4f60(a1 + 24, *(_DWORD *)(a1 + 36) + *(_DWORD *)(a1 + 88));
  v3 = *(_BYTE *)(a1 + 85);
  *(_BYTE *)(a1 + 85) = v3 & 0xDF;
  if ( (v3 & 1) != 0 )
  {
    v4 = *((_DWORD *)off_127B74 + 9);
    if ( v4 && *(_DWORD *)(v4 + 12) == a1 + 76 )
    {
      fmacfwbt_init_load();
      bt_rf_calibrate_or_setup(a1, *(_DWORD *)(a1 + 36), 0);
      return mac_state_process_n_1c8(a1, *((_DWORD *)off_127B78 + 4), 0);
    }
    else
    {
      return bt_rf_calibrate_or_setup(a1, *(_DWORD *)(a1 + 36), 0);
    }
  }
  return result;
}

