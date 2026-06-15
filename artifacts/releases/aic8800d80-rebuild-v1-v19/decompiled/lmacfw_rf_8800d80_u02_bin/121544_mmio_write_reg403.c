// mmio_write_reg403 @ 0x121544, size 96 bytes
// Doc: mmio_write_reg403 [mmio]: calls helper with reg 0x403, value 8; MMIO write wrapper
// mmio_write_reg403 [mmio]: calls helper with reg 0x403, value 8; MMIO write wrapper
int __fastcall mmio_write_reg403(int a1, int *a2, __int16 a3, __int16 a4)
{
  int v5; // r0
  _DWORD *v6; // r2
  int *v7; // r5
  int v8; // r3
  int v9; // r0
  int v10; // r2

  v5 = rf_setup_dispatch(1027, a4, a3, 8u);
  v6 = (_DWORD *)*a2;
  v7 = (int *)v5;
  if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    rf_reg_write_wait((int)v6, a2[1], 1);
    v9 = sub_10EFBC(*a2, 1);
    v8 = *a2;
  }
  else
  {
    *v6 = a2[1];
    v8 = *a2;
    v9 = *(_DWORD *)*a2;
  }
  v7[1] = v9;
  v10 = a2[1];
  *v7 = v8;
  msg_parse(dword_1215A4, v10);
  sub_11DE50((int)v7);
  return 0;
}

