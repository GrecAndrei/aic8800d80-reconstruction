// fwstruct annotate: 136f20_sub_136F20.c
// sub_136F20 @ 0x136f20, size 40 bytes
// Doc: sub_1236F20 [mmio]: Performs MMIO writes via helper (likely RF register config)
// sub_1236F20 [mmio]: Performs MMIO writes via helper (likely RF register config)
int sub_136F20()
{
  unsigned __int16 *v0; // r4
  int v1; // r0

  v0 = (unsigned __int16 *)off_136F48;
  v1 = sub_12C92C(4107, *((_WORD *)off_136F48 + 1924), 4, 1u);
  sdio_buffer_prepare_n_4e8(v1);
  feature_guard_check(8, dword_136F4C, v0[1924]);
  return 0;
}

