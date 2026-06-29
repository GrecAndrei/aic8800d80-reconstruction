// fwstruct annotate: 12d350_mmio_reg_match.c
// mmio_reg_match @ 0x12d350, size 26 bytes
// Doc: mmio_reg_match [mmio]: Compare MMIO register value against expected
// mmio_reg_match [mmio]: Compare MMIO register value against expected
BOOL __fastcall mmio_reg_match(_DWORD **a1, _DWORD *a2)
{
  _DWORD *v2; // r3

  v2 = *a1;
  if ( *a1 == a2 )
    return 1;
  while ( v2 )
  {
    v2 = (_DWORD *)*v2;
    if ( a2 == v2 )
      return 1;
  }
  return a2 == nullptr;
}

