// mmio_field_extract_n1168 @ 0x111168, size 124 bytes
// Doc: rf_bus_mark_1e2 [rf]: Mark RF bus operation state
// rf_bus_mark_1e2 [rf]: Mark RF bus operation state
int  mmio_field_extract_n1168(int a1)
{
  int *v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r1

  v1 = (int *)rf_bus_mark_1e4;
  v2 = a1 & 0x3FFFFF;
  v3 = *(uint32_t *)rf_bus_mark_1e4 & 0x3FFFFF;
  if ( (a1 & 0x400000) != 0 )
  {
    *(uint32_t *)rf_bus_mark_1e4 = v3 | 0x800000;
    *v1 = v3;
    *v1 = v2;
    v4 = v2 | 0x800000;
  }
  else
  {
    *(uint32_t *)rf_bus_mark_1e4 = v3 | 0x400000;
    v4 = v2 | 0x400000;
  }
  *v1 = v4;
  *v1 = v2 | 0xC00000;
  return log_printf(dword_1111E8, *(uint32_t *)rf_bus_mark_1e4 & 0x3FFFFF);
}

