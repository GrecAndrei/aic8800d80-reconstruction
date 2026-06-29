// crypto_rx_calibrate @ 0x107c48, size 418 bytes
// Doc: crypto_rx_calibrate [rx]: Initialize crypto/RX calibration registers and MMIO setup
// crypto_rx_calibrate [rx]: Initialize crypto/RX calibration registers and MMIO setup
int  crypto_rx_calibrate(int a1)
{
  uint32_t *v1; // r4
  uint32_t *v2; // r5
  int *v3; // r8
  int v4; // r9
  int *v5; // r6
  uint32_t *v6; // r10
  int v8; // r1
  int *v9; // r5
  int v10; // r3
  int v11; // r3
  int v12; // r6
  bool v13; // cc
  uint32_t *v14; // r4
  int v15; // r3
  int v16; // r11
  int v17; // r1
  int result; // r0
  uint32_t *v19; // r3
  unsigned int v20; // [sp+18h] [bp-14h] BYREF
  unsigned int v21; // [sp+1Ch] [bp-10h]
  int v22; // [sp+20h] [bp-Ch]
  int v23; // [sp+24h] [bp-8h]

  v1 = off_107DEC;
  v2 = off_107DF0;
  v3 = (int *)off_107DFC;
  v4 = dword_107E00;
  v5 = (int *)off_107DF4;
  v6 = off_107DF4;
  crypto_state_dump(a1);
  v8 = dword_107DF8;
  *v1 |= 0x1000000u;
  *v1 |= 0x2000000u;
  feature_guard_check(1, v8);
  crypto_engine_clear_sram_regs();
  *v2 &= ~1u;
  delay_us_0644(20);
  *v2 |= 4u;
  *v2 |= 8u;
  delay_us_0644(20);
  v9 = (int *)off_107DFC;
  *v1 |= 0x400000u;
  *v3 = *v3 & v4 | 0xC00;
  delay_us_0644(20);
  *v1 |= 0x4000000u;
  v10 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  v20 = v10;
  *v3 = *v3 & v4 | 0x400;
  delay_us_0644(20);
  *v1 |= 0x4000000u;
  v11 = *v5;
  v12 = dword_107E00;
  v21 = v11 & 0x7FFF;
  *v1 &= ~0x4000000u;
  v13 = v20 > v21;
  v14 = off_107DEC;
  if ( v20 > v21 )
    v15 = 1536;
  else
    v15 = 3584;
  *v9 = *v9 & v12 | v15;
  if ( v13 )
    v16 = 512;
  else
    v16 = 2560;
  delay_us_0644(20);
  *v14 |= 0x4000000u;
  v22 = *v6 & 0x7FFF;
  *v14 &= ~0x4000000u;
  *v9 = *v9 & v12 | v16;
  delay_us_0644(20);
  v17 = dword_107E04;
  *v14 |= 0x4000000u;
  v23 = *v6 & 0x7FFF;
  *v14 &= ~0x4000000u;
  *v14 &= ~0x400000u;
  feature_guard_check(1, v17);
  result = sub_1079CC(&v20, a1);
  v19 = off_107DF0;
  *(uint32_t *)off_107DF0 &= ~4u;
  *v19 &= ~8u;
  *v9 &= v12;
  *v14 &= ~0x1000000u;
  *v14 &= ~0x2000000u;
  return result;
}

