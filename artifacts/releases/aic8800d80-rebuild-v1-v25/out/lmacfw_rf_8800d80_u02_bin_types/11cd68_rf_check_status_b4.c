// rf_check_status_b4 @ 0x11cd68, size 56 bytes
// Doc: rf_check_status_b4 [rf]: Check RF status flag and branch on zero
// rf_check_status_b4 [rf]: Check RF status flag and branch on zero
int rf_check_status_b4()
{
  int result; // r0

  if ( **(__int16 **)off_11CDA0 < 0 && *(uint32_t *)off_11CDA8 << 28 )
    return sub_121960(dword_11CDB0, dword_11CDAC, 105, *(uint32_t *)off_11CDA8);
  if ( (*(uint32_t *)off_11CDA4 & 0x80) != 0 )
  {
    *(uint32_t *)off_11CDA4 &= ~0x80u;
    return irq_nesting_or(0x2000000);
  }
  return result;
}

