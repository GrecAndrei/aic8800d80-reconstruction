// v23 annotated: sub_119BB0 @ 0x119bb0
// Original: 119bb0_sub_119BB0.c
// Primary struct: <unclustered>
//
// sub_119BB0 @ 0x119bb0, size 38 bytes
// Doc: rf_alloc_buf_0x34 [rf]: Allocate 0x34-byte RF buffer via helper, returns indexed handle
// rf_alloc_buf_0x34 [rf]: Allocate 0x34-byte RF buffer via helper, returns indexed handle
int __fastcall sub_119BB0(int a1, int a2, int a3, int a4)
{
  _BYTE *v5; // r4

  v5 = (_BYTE *)rf_setup_dispatch(52, a4, a3, 2);
  *v5 = sub_11BD44(a2, v5 + 1);
  sub_11DE50(v5);
  return 0;
}

