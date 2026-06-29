// sub_119BB0 @ 0x119bb0, size 38 bytes
// Doc: rf_alloc_buf_0x34 [rf]: Allocate 0x34-byte RF buffer via helper, returns indexed handle
// rf_alloc_buf_0x34 [rf]: Allocate 0x34-byte RF buffer via helper, returns indexed handle
int  sub_119BB0(int a1, int a2, int a3, int a4)
{
  uint8_t *v5; // r4

  v5 = (uint8_t *)rf_setup_dispatch(52, a4, a3, 2);
  *v5 = sub_11BD44(a2, v5 + 1);
  sub_11DE50(v5);
  return 0;
}

