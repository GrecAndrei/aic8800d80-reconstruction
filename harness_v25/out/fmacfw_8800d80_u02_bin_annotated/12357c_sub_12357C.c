// fwstruct annotate: 12357c_sub_12357C.c
// sub_12357C @ 0x12357c, size 80 bytes
// Doc: sub_122357C [ipc]: Invoke IPC/utility with cmd 0x54 sub 0xd, flag 1, arg 0
// sub_122357C [ipc]: Invoke IPC/utility with cmd 0x54 sub 0xd, flag 1, arg 0
int __fastcall sub_12357C(int a1, unsigned __int8 *a2)
{
  _BYTE *v3; // r0
  _BYTE *v4; // r4
  unsigned int v5; // r0

  v3 = (_BYTE *)sub_12C92C(84, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 || !*(_BYTE *)(dword_1235CC + 1320 * v5 + 1224) )
    goto LABEL_5;
  *v4 = 0;
  if ( a2[1] )
  {
    sub_12A528();
LABEL_5:
    sdio_buffer_prepare_n_4e8(v4);
    return 0;
  }
  rf_table_lookup_n564();
  sdio_buffer_prepare_n_4e8(v4);
  return 0;
}

