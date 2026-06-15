// v23 annotated: mmio_read_modify_n_d08 @ 0x117d08
// Original: 117d08_mmio_read_modify_n_d08.c
// Primary struct: <unclustered>
//
// mmio_read_modify_n_d08 @ 0x117d08, size 76 bytes
// Doc: mmio_read_modify_n_d08 [mmio]: Read-modify MMIO register 0x40328078 with mask 0xf0001f
// mmio_read_modify_n_d08 [mmio]: Read-modify MMIO register 0x40328078 with mask 0xf0001f
unsigned int mmio_read_modify_n_d08()
{
  int v0; // r4
  unsigned int result; // r0

  v0 = dword_117D58 & *(_DWORD *)off_117D54;
  if ( (*(_DWORD *)off_117D54 & 0x10) != 0 )
  {
    if ( (*(_DWORD *)off_117D54 & 0x1000) != 0 )
    {
      v0 |= 0x1000u;
      *((_DWORD *)off_117D60 + 52) |= 4u;
    }
    sub_11C734();
  }
  result = v0 & 0xF00000;
  if ( (v0 & 0xF00000) != 0 )
    result = sub_11B0B4((unsigned __int8)(11 - __clz(result)));
  *(_DWORD *)off_117D5C = v0;
  return result;
}

