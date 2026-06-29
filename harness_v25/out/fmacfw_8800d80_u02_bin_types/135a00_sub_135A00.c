// sub_135A00 @ 0x135a00, size 124 bytes
void  sub_135A00(
        unsigned __int16 *a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  unsigned __int16 *v13; // r6
  int v15; // r5
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r3
  int v20; // r3
  unsigned int v21; // r3

  v13 = a1 + 6;
  event_queue_push(6154, 6);
  v15 = v13[2];
  feature_guard_check(256, dword_135A7C, v15);
  if ( v15 )
  {
    sub_134E04(v15, v16, v17, v18, a5, a6, a7, a8, a9, a10, a11, a12, a13);
    return;
  }
  v19 = a1[6];
  if ( !a1[6] )
  {
LABEL_7:
    queue_pending_check();
    return;
  }
  if ( v19 != 1 )
  {
    if ( v19 == 2 )
      rf_bus_write_6b_d(*((uint8_t *)a1 + 8), (int)(a1 + 9), (unsigned __int16)(*a1 - 6));
    return;
  }
  v20 = v13[1];
  if ( v20 == 4 )
  {
    mmio_read_backoff_window(3000);
    goto LABEL_7;
  }
  if ( v20 == 2 )
  {
    v21 = *a1;
    if ( v21 > 0x22 )
      sub_135168(3, (char *)a1 + 20, v17, v21, a5, a6, a7, a8, a9, a10, a11, a12, a13);
  }
}

