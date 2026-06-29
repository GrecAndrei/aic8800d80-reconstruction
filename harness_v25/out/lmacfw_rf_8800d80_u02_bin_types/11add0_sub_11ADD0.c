// sub_11ADD0 @ 0x11add0, size 76 bytes
// Doc: sub_121ADD0 [util]: Lookup/validate state entry against stored pointer
// sub_121ADD0 [util]: Lookup/validate state entry against stored pointer
int  sub_11ADD0(int result)
{
  uint32_t *v1; // r6
  int v2; // r5
  int v3; // r4
  uint8_t *v4; // r0
  uint32_t *v5; // r0

  v1 = off_11AE1C;
  v2 = *((uint32_t *)off_11AE1C + 10);
  if ( v2 == result )
  {
    *(uint8_t *)(v2 + 16) = 4;
  }
  else
  {
    v3 = result;
    if ( v2 )
    {
      if ( *(uint8_t *)(v2 + 24) != 3 )
      {
        v4 = (uint8_t *)rf_setup_dispatch(69, 4, 0, 1);
        *v4 = *(uint8_t *)(v2 + 24);
        sub_11DE50(v4);
      }
    }
    v1[11] = v3;
    *(uint8_t *)(v3 + 16) = 2;
    v5 = (uint32_t *)rf_setup_dispatch(140, 0, 255, 4);
    *v5 = dword_11AE20;
    return sub_11DE50(v5);
  }
  return result;
}

