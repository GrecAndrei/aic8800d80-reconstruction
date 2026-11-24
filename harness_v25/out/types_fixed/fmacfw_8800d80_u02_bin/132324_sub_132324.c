// sub_132324 @ 0x132324, size 48 bytes
int __fastcall sub_132324(int a1)
{
  _BYTE *v2; // r4

  v2 = (_BYTE *)sub_12C92C(12, 0, 5, 1u);
  sub_13BE14(a1);
  *v2 = a1;
  sdio_buffer_prepare_n_4e8((int)v2);
  return sub_12CA10(5130, 13, 5);
}

