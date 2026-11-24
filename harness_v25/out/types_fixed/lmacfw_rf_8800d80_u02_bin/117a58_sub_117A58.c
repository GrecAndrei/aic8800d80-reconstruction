// sub_117A58 @ 0x117a58, size 26 bytes
int sub_117A58()
{
  _DWORD *v0; // r2

  v0 = off_117A78;
  *(_DWORD *)off_117A74 = 0x10000;
  *v0 &= ~0x10000u;
  return irq_nesting_or(0x4000);
}

