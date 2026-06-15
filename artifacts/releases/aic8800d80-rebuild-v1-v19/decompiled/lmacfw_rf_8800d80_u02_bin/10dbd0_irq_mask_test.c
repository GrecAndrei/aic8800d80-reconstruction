// irq_mask_test @ 0x10dbd0, size 20 bytes
// Doc: irq_mask_test [util]: Test/validate IRQ mask register handling
// irq_mask_test [util]: Test/validate IRQ mask register handling
BOOL __fastcall irq_mask_test(char a1)
{
  return ((1 << a1) & *(_DWORD *)off_10DBE4) != 0;
}

