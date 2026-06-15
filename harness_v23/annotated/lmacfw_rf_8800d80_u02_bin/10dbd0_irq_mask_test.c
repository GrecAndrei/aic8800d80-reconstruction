// v23 annotated: irq_mask_test @ 0x10dbd0
// Original: 10dbd0_irq_mask_test.c
// Primary struct: rf_subsys (cluster 9, 12 funcs)
// Fields: base=0x8, cfg=0xc
//
// irq_mask_test @ 0x10dbd0, size 20 bytes
// Doc: irq_mask_test [util]: Test/validate IRQ mask register handling
// irq_mask_test [util]: Test/validate IRQ mask register handling
BOOL __fastcall irq_mask_test(char a1)
{
  return ((1 << a1) & *(_DWORD *)off_10DBE4) != 0;
}

