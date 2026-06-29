// fwstruct annotate: 107e70_fmac_irq_disable_dispatch.c
// fmac_irq_disable_dispatch @ 0x107e70, size 104 bytes
// Doc: fmac_irq_disable_dispatch [util]: Disable IRQ and dispatch to handler
// fmac_irq_disable_dispatch [util]: Disable IRQ and dispatch to handler
int fmac_irq_disable_dispatch()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r2
  int result; // r0
  _DWORD *v3; // r2
  int v4; // r3

  v0 = off_107ED8;
  crypto_engine_clear_sram_regs();
  *v0 &= ~1u;
  delay_us_0644(1);
  v1 = off_107EDC;
  *(_DWORD *)off_107EDC = *(_DWORD *)off_107EDC & 0xCFFFFFFF | 0x10000000;
  *v1 |= 0x40000000u;
  result = delay_us_0644(1);
  v3 = off_107EE0;
  *v0 |= 1u;
  *v0 |= 1u;
  while ( (*v3 & 1) == 0 )
  {
    LOWORD(v4) = 50;
    do
      v4 = (unsigned __int16)(v4 - 1);
    while ( v4 );
  }
  *(_DWORD *)off_107ED8 &= ~1u;
  return result;
}

