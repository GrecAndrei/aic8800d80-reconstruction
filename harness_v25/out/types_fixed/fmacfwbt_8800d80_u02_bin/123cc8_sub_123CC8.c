// sub_123CC8 @ 0x123cc8, size 182 bytes
void __fastcall sub_123CC8(int a1, int a2, int a3)
{
  __int16 v3; // r3
  __int16 **v4; // r8
  int v5; // r0
  __int16 v8; // r7
  _DWORD *(_DWORD *)(v9 + 0x8); // [sp+4h] [bp-24h] BYREF
  char v10; // [sp+Dh] [bp-1Bh]
  _DWORD *(_DWORD *)(v11 + 0x18); // [sp+10h] [bp-18h] BYREF

  v4 = (__int16 **)off_123D98;
  v5 = **(__int16 **)off_123D98;
  memset(v11, 0, sizeof(v11));
  v8 = v3;
  if ( v5 < 0 && msg_get_value(a3) )
    sub_12F694(dword_123D94, dword_123D90, 337);
  fmac_module_init((int *)a2);
  *(_DWORD *)(v9 + 0x0) = dword_123D80;
  v10 = 0;
  *(_DWORD *)(v9 + 0x4) = 2484;
  sub_102898((unsigned __int16 *)v9, 0);
  bt_hci_cmd_build_n6ac(15);
  *((_WORD *)off_123D84 + 14) = *(_WORD *)(a2 + 68);
  sub_118104((int)v11);
  if ( **v4 < 0 && (unsigned __int8)v8 > 0xEu )
  {
    sub_12F694(dword_123D8C, dword_123D88, 183);
    goto LABEL_7;
  }
  if ( (unsigned __int8)v8 > 0xCu )
LABEL_7:
    message_dispatch_n84(3, v8, a3);
  rf_misc_init_n_xxx();
  sub_12BA2C();
  rf_bus_mark_n_3b7(a3, 2);
}

