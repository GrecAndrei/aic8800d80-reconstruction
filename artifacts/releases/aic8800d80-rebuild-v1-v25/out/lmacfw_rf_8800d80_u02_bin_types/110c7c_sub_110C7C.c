// sub_110C7C @ 0x110c7c, size 124 bytes
// Doc: rf_bus_mark_n_4da [rf]: Marks RF bus region by ORing 0x800000 flag into control register
// rf_bus_mark_n_4da [rf]: Marks RF bus region by ORing 0x800000 flag into control register
int  sub_110C7C(int a1)
{
  int *v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r1

  v1 = (int *)rf_bus_mark_n_494;
  v2 = a1 & 0x3FFFFF;
  v3 = *(uint32_t *)rf_bus_mark_n_494 & 0x3FFFFF;
  if ( (a1 & 0x400000) != 0 )
  {
    *(uint32_t *)rf_bus_mark_n_494 = v3 | 0x800000;
    *v1 = v3;
    *v1 = v2;
    v4 = v2 | 0x800000;
  }
  else
  {
    *(uint32_t *)rf_bus_mark_n_494 = v3 | 0x400000;
    v4 = v2 | 0x400000;
  }
  *v1 = v4;
  *v1 = v2 | 0xC00000;
  return sub_10DA6C(rf_bus_mark_n_490, *(uint32_t *)rf_bus_mark_n_494 & 0x3FFFFF);
}

