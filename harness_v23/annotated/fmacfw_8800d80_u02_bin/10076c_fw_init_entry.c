// v23 annotated: fw_init_entry @ 0x10076c
// Original: 10076c_fw_init_entry.c
// Primary struct: <unclustered>
//
// fw_init_entry @ 0x10076c, size 42 bytes
// Doc: fw_init_entry [util]: Firmware initialization early entry point
// fw_init_entry [util]: Firmware initialization early entry point
_DWORD *fw_init_entry()
{
  _DWORD *result; // r0
  unsigned int *v1; // r2

  result = off_10079C;
  v1 = (unsigned int *)off_1007A0;
  *(_DWORD *)off_100798 &= ~0x10000u;
  *result = 1;
  *v1 = *v1 & 0x1FFFFFFE | 0xC0000000;
  return result;
}

