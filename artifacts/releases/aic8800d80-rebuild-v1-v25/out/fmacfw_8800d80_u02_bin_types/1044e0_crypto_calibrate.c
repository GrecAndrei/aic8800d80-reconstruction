// crypto_calibrate @ 0x1044e0, size 212 bytes
// Doc: crypto_calibrate [mac]: Calibrate crypto engine via MMIO writes to 0x403420xx block
// crypto_calibrate [mac]: Calibrate crypto engine via MMIO writes to 0x403420xx block
int crypto_calibrate()
{
  int *v0; // r1
  uint32_t *v1; // r3
  int v2; // r0
  int v3; // r5
  uint32_t *v4; // r6
  int *v5; // r4
  int v6; // r1
  int result; // r0
  uint32_t *v8; // r3
  uint32_t *v9; // r1

  v0 = (int *)off_1045B4;
  v1 = off_1045BC;
  v2 = dword_1045C0;
  v3 = *(uint32_t *)off_1045B8;
  *(uint32_t *)off_1045B8 = dword_1045C4;
  *v0 = v2;
  v4 = off_1045C8;
  v5 = (int *)off_1045CC;
  *v1 = *v1 & 0xFC000FFF | 0x333000;
  *v1 &= 0x3FFFFFFFu;
  *v1 |= 0xC000000u;
  *v1 = ~(~(*v1 >> 12) << 12);
  v0[29] = v0[29] & 0xFFFFFF0F | 0xA0;
  *v1 |= 0x10000000u;
  delay_us_0644(10);
  *v4 = dword_1045D0;
  delay_us_0644(125);
  *v4 = dword_1045D4;
  while ( *v5 < 0 )
    delay_us_0644(1);
  feature_guard_check(1, dword_1045D8);
  v6 = dword_1045DC;
  *(uint32_t *)off_1045C8 = 0;
  feature_guard_check(1, v6);
  *(uint32_t *)off_1045B8 = v3;
  crypto_iq_calculate();
  result = feature_guard_check(1, dword_1045E0);
  v8 = off_1045BC;
  v9 = off_1045E4;
  *(uint32_t *)off_1045BC &= 0xF3FFFFFF;
  *v9 |= 0xF0u;
  *v8 &= ~0x10000000u;
  *v8 &= 0x3FFFFFFFu;
  return result;
}

