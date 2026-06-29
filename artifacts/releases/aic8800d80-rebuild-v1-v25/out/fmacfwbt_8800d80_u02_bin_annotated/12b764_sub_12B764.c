// fwstruct annotate: 12b764_sub_12B764.c
// sub_12B764 @ 0x12b764, size 72 bytes
int sub_12B764()
{
  _DWORD *v0; // r4
  unsigned int v1; // r2
  int result; // r0

  if ( **(__int16 **)off_12B7AC < 0 && *(_DWORD *)off_12B7B8 << 28 )
    return sub_12F630(dword_12B7C0, dword_12B7BC, 105, *(_DWORD *)off_12B7B8);
  if ( (*(_DWORD *)off_12B7B0 & 0x80) != 0 )
  {
    v0 = off_12B7B4;
    v1 = *((_DWORD *)off_12B7B4 + 1) & 0xFFFFFFFB;
    *(_DWORD *)off_12B7B0 &= ~0x80u;
    v0[1] = v1;
    return irq_nesting_or(0x2000000);
  }
  return result;
}

