// v23 annotated: chip_revision_get @ 0x101a88
// Original: 101a88_chip_revision_get.c
// Primary struct: <unclustered>
//
// chip_revision_get @ 0x101a88, size 14 bytes
// Doc: chip_revision_get [util]: Reads chip revision field (bits 8-11) from ID register and returns (val-1)
// chip_revision_get [util]: Reads chip revision field (bits 8-11) from ID register and returns (val-1)
int chip_revision_get()
{
  return (unsigned __int8)((BYTE1(*(_DWORD *)off_101A98) & 0xF) - 1);
}

