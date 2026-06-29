// crypto_hw_power_up_3b6c @ 0x103b6c, size 138 bytes
// Doc: crypto_hw_power_up_3b6c [ke]: Power up crypto engine via MMIO at 0x40344084/0x403440a8
// crypto_hw_power_up_3b6c [ke]: Power up crypto engine via MMIO at 0x40344084/0x403440a8
int crypto_hw_power_up_3b6c()
{
  uint32_t *v0; // r2
  int v1; // r3
  uint32_t *v2; // r3
  uint32_t *v3; // r2
  int v4; // r3
  uint32_t *v5; // r3
  uint32_t *v6; // r0
  int v7; // r1

  v0 = off_103BFC;
  *(uint32_t *)off_103BF8 |= 1u;
  while ( (*v0 & 0x10) == 0 )
  {
    LOWORD(v1) = 50;
    do
      v1 = (unsigned __int16)(v1 - 1);
    while ( v1 );
  }
  v2 = off_103C00;
  v3 = off_103BFC;
  *(uint32_t *)off_103C00 |= 0x80000u;
  *v2 |= 0x100000u;
  while ( (*v3 & 8) == 0 )
  {
    LOWORD(v4) = 50;
    do
      v4 = (unsigned __int16)(v4 - 1);
    while ( v4 );
  }
  v5 = off_103C08;
  v6 = off_103C0C;
  v7 = dword_103C10;
  *(uint32_t *)off_103C04 |= 0x20000u;
  *v5 |= 0x1000000u;
  *v5 |= 0x8000000u;
  *v6 |= 0x524u;
  return feature_guard_check(0x2000, v7);
}

