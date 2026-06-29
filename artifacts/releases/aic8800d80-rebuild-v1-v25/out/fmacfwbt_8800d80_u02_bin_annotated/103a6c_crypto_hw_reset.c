// fwstruct annotate: 103a6c_crypto_hw_reset.c
// crypto_hw_reset @ 0x103a6c, size 66 bytes
// Doc: crypto_hw_reset [ke]: Reset crypto HW engine via MMIO register clears
// crypto_hw_reset [ke]: Reset crypto HW engine via MMIO register clears
int crypto_hw_reset()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r1
  _DWORD *v2; // r2

  v0 = off_103AB4;
  v1 = off_103AB8;
  v2 = off_103ABC;
  *(_DWORD *)off_103AB0 &= 0xFFFFFA53;
  *v0 &= ~0x20000u;
  *v1 &= ~0x1000000u;
  *v2 &= 0xFFE7FFFF;
  delay_us(10);
  return feature_guard_sdio(0x2000, dword_103AC0);
}

