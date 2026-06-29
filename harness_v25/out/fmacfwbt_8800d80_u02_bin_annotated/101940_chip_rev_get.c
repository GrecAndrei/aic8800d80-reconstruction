// fwstruct annotate: 101940_chip_rev_get.c
// chip_rev_get @ 0x101940, size 14 bytes
// Doc: chip_rev_get [util]: Get chip revision from register field
// chip_rev_get [util]: Get chip revision from register field
int chip_rev_get()
{
  return (unsigned __int8)((BYTE1(*(_DWORD *)off_101950) & 0xF) - 1);
}

