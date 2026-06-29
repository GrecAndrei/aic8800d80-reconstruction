// sub_136EFC @ 0x136efc, size 32 bytes
// Doc: sub_1236EFC [ipc]: Calls message dispatch init/registration
// sub_1236EFC [ipc]: Calls message dispatch init/registration
int  sub_136EFC(int a1, int a2, int a3, __int16 a4)
{
  int v4; // r0

  v4 = sub_12C92C(4107, a4, 4, 1u);
  sdio_buffer_prepare_n_4e8(v4);
  feature_guard_check(8, dword_136F1C);
  return 0;
}

