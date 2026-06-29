// fwstruct annotate: 13b564_sub_13B564.c
// sub_13B564 @ 0x13b564, size 142 bytes
int __fastcall sub_13B564(int a1, char *a2, unsigned int a3)
{
  unsigned int v5; // r5
  int v6; // r6
  char v7; // r0
  char v8; // r8
  unsigned __int8 v9; // r7
  char v10; // r6
  _BYTE *v11; // r0

  if ( a2[2] != 2 )
    return 0;
  v5 = a3 >> 8;
  if ( msg_get_value(a3 & 0xFF00 | 8) == 4 )
  {
    v6 = dword_13B5F4 + 32 * v5;
    if ( *(_BYTE *)(v6 + 17) == 1 )
    {
      v7 = sub_13C400(*(_DWORD *)(v6 + 28));
      v8 = *a2;
      v9 = a2[1];
      v10 = 4 - *(_BYTE *)(v6 + 20) + v7;
      v11 = (_BYTE *)sub_12C92C(5131, 13, 5, 3u);
      v11[2] = v10;
      *v11 = v8;
      v11[1] = v9;
      sdio_buffer_prepare_n_4e8((int)v11);
    }
    *(_DWORD *)(696 * (unsigned __int8)*a2 + 12 * (unsigned __int8)a2[1] + dword_13B5F8 + 448) = *((_DWORD *)off_13B5FC
                                                                                                 + 4);
    tx_msg_submit_n_bc28(v5);
  }
  return 0;
}

