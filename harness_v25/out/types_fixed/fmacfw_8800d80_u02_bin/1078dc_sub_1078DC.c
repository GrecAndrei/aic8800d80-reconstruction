// sub_1078DC @ 0x1078dc, size 212 bytes
int __fastcall sub_1078DC(int a1, _DWORD *a2, int a3)
{
  _DWORD *v3; // r5
  _DWORD *v4; // r4
  int *v5; // r6
  int v6; // r8
  int v7; // r7
  __int64 v8; // kr00_8
  int v9; // r3
  int *v10; // r0
  int v11; // r0
  int result; // r0

  v3 = off_1079B0;
  v4 = off_1079B4;
  v5 = (int *)off_1079B8;
  v6 = dword_1079C8;
  v7 = dword_1079BC;
  v8 = *(_QWORD *)(a1 + 8);
  crypto_engine_clear_sram_regs();
  *v3 &= ~1u;
  delay_us_0644(20);
  v9 = dword_1079C0;
  *v3 |= 4u;
  *v3 |= 8u;
  *v4 |= 0x100000u;
  *v4 |= 0x200000u;
  *v5 = v9 & (HIDWORD(v8) << 16) | *v5 & v6;
  *v5 = *v5 & v7 | v8 & 0xFFF;
  delay_us_0644(40);
  v10 = (int *)off_1079C4;
  *v4 |= 0x4000000u;
  v11 = *v10;
  *v4 &= ~0x4000000u;
  *v4 &= ~0x100000u;
  *v4 &= ~0x200000u;
  result = crypto_power_apply(v11 & 0x7FFF, a2, a3);
  *v3 &= ~4u;
  *v3 &= ~8u;
  *v5 &= v6;
  *v5 &= v7;
  *v4 &= ~0x1000000u;
  *v4 &= ~0x2000000u;
  return result;
}

