// sub_136F50 @ 0x136f50, size 48 bytes
int  sub_136F50(int a1, int a2, int a3, __int16 a4)
{
  uint8_t *v5; // r4

  v5 = (uint8_t *)sub_12C92C(4104, a4, 4, 2u);
  feature_guard_check(8, dword_136F80);
  *v5 = 1;
  v5[1] = *(uint8_t *)(a2 + 2);
  sdio_buffer_prepare_n_4e8((int)v5);
  return 0;
}

