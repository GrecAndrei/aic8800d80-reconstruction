// sub_1238C0 @ 0x1238c0, size 60 bytes
int __fastcall sub_1238C0(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r5
  int v6; // r0
  int v7; // r4

  v4 = dword_1238FC + 1320 * *a2;
  v6 = sub_12C92C(47, a4, a3, 2);
  *(_BYTE *)(v4 + 110) = a2[1];
  v7 = v6;
  message_dispatch_408(v4);
  message_dispatch_n_4c4(v4, v7 + 1, v7);
  sdio_buffer_prepare_n_4e8(v7);
  return 0;
}

