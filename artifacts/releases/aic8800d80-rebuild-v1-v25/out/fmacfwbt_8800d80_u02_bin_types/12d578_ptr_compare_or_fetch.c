// ptr_compare_or_fetch @ 0x12d578, size 26 bytes
// Doc: ptr_compare_or_fetch [util]: Compare pointer at r0 against r1 value
// ptr_compare_or_fetch [util]: Compare pointer at r0 against r1 value
BOOL  ptr_compare_or_fetch(uint32_t **a1, uint32_t *a2)
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

