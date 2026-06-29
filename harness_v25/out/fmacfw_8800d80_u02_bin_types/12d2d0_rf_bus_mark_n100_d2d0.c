// rf_bus_mark_n100_d2d0 @ 0x12d2d0, size 22 bytes
// Doc: rf_bus_mark_n100_d2d0 [rf]: Marks a tagged slot on the RF shared bus structure
// rf_bus_mark_n100_d2d0 [rf]: Marks a tagged slot on the RF shared bus structure
uint32_t * rf_bus_mark_n100_d2d0(int a1)
{
  uint32_t *v1; // r3
  uint32_t *v2; // r2

  v1 = *(uint32_t **)a1;
  if ( *(uint32_t *)a1 )
  {
    v2 = *(uint32_t **)(a1 + 4);
    *(uint32_t *)a1 = *v1;
    if ( v2 == v1 )
      *(uint32_t *)(a1 + 4) = 0;
  }
  return v1;
}

