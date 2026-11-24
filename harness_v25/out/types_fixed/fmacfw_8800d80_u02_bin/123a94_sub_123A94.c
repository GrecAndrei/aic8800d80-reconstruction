// sub_123A94 @ 0x123a94, size 182 bytes
void __fastcall sub_123A94(int a1, int a2, int a3)
{
  __int16 v3; // r3
  __int16 **v4; // r8
  int v5; // r0
  __int16 v8; // r7
  _DWORD *(_DWORD *)(v9 + 0x8); // [sp+4h] [bp-24h] BYREF
  char v10; // [sp+Dh] [bp-1Bh]
  _DWORD *(_DWORD *)(v11 + 0x18); // [sp+10h] [bp-18h] BYREF

  v4 = (__int16 **)off_123B64;
  v5 = **(__int16 **)off_123B64;
  memset(v11, 0, sizeof(v11));
  v8 = v3;
  if ( v5 < 0 && msg_get_value(a3) )
    sub_12F46C(dword_123B60, dword_123B5C, 337);
  fmac_init_step((int *)a2);
  *(_DWORD *)(v9 + 0x0) = dword_123B4C;
  v10 = 0;
  *(_DWORD *)(v9 + 0x4) = 2484;
  sub_102A20((unsigned __int16 *)v9, 0);
  mac_rx_reorder(15);
  *((_WORD *)off_123B50 + 14) = *(_WORD *)(a2 + 68);
  rf_bus_reset2_n_357((int)v11);
  if ( **v4 < 0 && (unsigned __int8)v8 > 0xEu )
  {
    sub_12F46C(dword_123B58, dword_123B54, 183);
    goto LABEL_7;
  }
  if ( (unsigned __int8)v8 > 0xCu )
LABEL_7:
    sub_12CA10(3, v8, a3);
  mmio_init_reset();
  sub_12B804();
  sub_12CD34(a3, 2);
}

