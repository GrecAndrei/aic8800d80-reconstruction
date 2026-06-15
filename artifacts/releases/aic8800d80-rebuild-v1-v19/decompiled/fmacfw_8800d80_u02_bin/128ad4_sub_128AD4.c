// sub_128AD4 @ 0x128ad4, size 80 bytes
int __fastcall sub_128AD4(int a1)
{
  unsigned __int8 *v1; // r6
  int v2; // r4
  _BYTE *v4; // r0

  v1 = (unsigned __int8 *)off_128B24;
  v2 = dword_128B28 + 1320 * *((unsigned __int8 *)off_128B24 + 16);
  if ( *(_DWORD *)(v2 + 72) )
  {
    sub_1285BC(*((unsigned __int8 *)off_128B24 + 16));
  }
  else
  {
    v4 = (_BYTE *)sub_12C92C(5143, 5, 5, 2);
    *v4 = 1;
    v4[1] = *(_BYTE *)(v2 + 107);
    sdio_buffer_prepare_n_4e8(v4);
  }
  return sub_128888(v1[16], a1);
}

