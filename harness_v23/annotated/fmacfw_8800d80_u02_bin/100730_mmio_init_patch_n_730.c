// v23 annotated: mmio_init_patch_n_730 @ 0x100730
// Original: 100730_mmio_init_patch_n_730.c
// Primary struct: <unclustered>
//
// mmio_init_patch_n_730 @ 0x100730, size 46 bytes
// Doc: mmio_init_patch_n_730 [mmio]: Initializes MMIO register at 0x40344084 by setting bit 0x10000
// mmio_init_patch_n_730 [mmio]: Initializes MMIO register at 0x40344084 by setting bit 0x10000
_DWORD *mmio_init_patch_n_730()
{
  _DWORD *result; // r0
  int *v1; // r2

  result = off_100764;
  v1 = (int *)off_100768;
  *(_DWORD *)off_100760 |= 0x10000u;
  *result = 0;
  *v1 = *v1 & 0x1FFFFFFE | 0x20000001;
  return result;
}

