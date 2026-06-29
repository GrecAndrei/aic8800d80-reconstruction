// mmio_reg_match @ 0x12d350, size 26 bytes
// Doc: mmio_reg_match [mmio]: Compare MMIO register value against expected
// mmio_reg_match [mmio]: Compare MMIO register value against expected
BOOL  mmio_reg_match(uint32_t **a1, uint32_t *a2)
{
  uint32_t *v2; // r3

  v2 = *a1;
  if ( *a1 == a2 )
    return 1;
  while ( v2 )
  {
    v2 = (uint32_t *)*v2;
    if ( a2 == v2 )
      return 1;
  }
  return a2 == nullptr;
}

