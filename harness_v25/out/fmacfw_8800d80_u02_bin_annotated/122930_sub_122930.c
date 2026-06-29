// fwstruct annotate: 122930_sub_122930.c
// sub_122930 @ 0x122930, size 40 bytes
// Doc: sub_1222932 [unknown]: unknown behavioral stub function
// sub_1222932 [unknown]: unknown behavioral stub function
int __fastcall sub_122930(int a1, int a2, int a3, int a4)
{
  _BYTE *v5; // r4

  v5 = (_BYTE *)sub_12C92C(11, a4, a3, 3);
  *v5 = sub_121CD8(a2, v5 + 1, v5 + 2);
  sdio_buffer_prepare_n_4e8(v5);
  return 0;
}

