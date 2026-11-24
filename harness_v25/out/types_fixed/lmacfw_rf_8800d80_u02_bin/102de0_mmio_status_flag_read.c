// mmio_status_flag_read @ 0x102de0, size 26 bytes
// Doc: mmio_status_flag_read [mmio]: Read status flag bit from MMIO 0x40344018
// mmio_status_flag_read [mmio]: Read status flag bit from MMIO 0x40344018
BOOL mmio_status_flag_read()
{
  BOOL result; // r0

  result = (*(_DWORD *)off_102DFC >> 27) & 1;
  if ( (*(_DWORD *)off_102DFC & 0x8000000) != 0 )
    return (*(_DWORD *)off_102E00 & 0x400) == 0;
  return result;
}

