// sub_123F04 @ 0x123f04, size 68 bytes
int __fastcall sub_123F04(int a1, int a2, __int16 a3, __int16 a4)
{
  int v5; // r0
  int v6; // r4
  int v9; // [sp+8h] [bp-8h] BYREF
  int v10; // [sp+Ch] [bp-4h] BYREF

  read_mac_dual_addr(&v9, &v10);
  v5 = rf_setup_dispatch(2, a4, a3, 0x48u);
  v6 = v5;
  if ( (BYTE2(v9) & 3) == 2 )
    sub_1282E8(v5, dword_123F48, 33);
  *(_DWORD *)(v6 + 64) = 255;
  sub_11DE50(v6);
  return 0;
}

