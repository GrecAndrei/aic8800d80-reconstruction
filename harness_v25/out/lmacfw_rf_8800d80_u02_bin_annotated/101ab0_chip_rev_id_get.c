// fwstruct annotate: 101ab0_chip_rev_id_get.c
// chip_rev_id_get @ 0x101ab0, size 14 bytes
// Doc: chip_rev_id_get [util]: Read chip revision register and extract (val & 0xf) - 1
// chip_rev_id_get [util]: Read chip revision register and extract (val & 0xf) - 1
int chip_rev_id_get()
{
  return (unsigned __int8)((*(_BYTE *)off_101AC0 & 0xF) - 1);
}

