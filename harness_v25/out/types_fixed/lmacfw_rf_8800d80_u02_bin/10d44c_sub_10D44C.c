// sub_10D44C @ 0x10d44c, size 36 bytes
int sub_10D44C()
{
  int v0; // r3
  int result; // r0

  v0 = *((_DWORD *)off_10D470 + 3);
  if ( (v0 & 0x8000) != 0 )
    *((_DWORD *)off_10D470 + 2) = 0x800000;
  if ( (v0 & 0x400) != 0 )
  {
    *((_DWORD *)off_10D470 + 2) = 0x40000;
    return irq_nesting_or(0x20000000);
  }
  return result;
}

