// v23 annotated: hw_chip_rev_get @ 0x101ac4
// Original: 101ac4_hw_chip_rev_get.c
// Primary struct: <unclustered>
//
// hw_chip_rev_get @ 0x101ac4, size 14 bytes
// Doc: hw_chip_rev_get [mmio]: Read chip revision field from HW register
// hw_chip_rev_get [mmio]: Read chip revision field from HW register
int hw_chip_rev_get()
{
  return (unsigned __int8)((BYTE1(*(_DWORD *)off_101AD4) & 0xF) - 1);
}

