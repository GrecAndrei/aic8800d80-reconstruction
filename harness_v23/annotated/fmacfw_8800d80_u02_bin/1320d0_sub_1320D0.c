// v23 annotated: sub_1320D0 @ 0x1320d0
// Original: 1320d0_sub_1320D0.c
// Primary struct: <unclustered>
//
// sub_1320D0 @ 0x1320d0, size 96 bytes
int __fastcall sub_1320D0(int a1, char *a2, __int16 a3, __int16 a4)
{
  _WORD *v7; // r4
  char v8; // r3
  int v9; // r1
  _BYTE *v10; // r0
  int v11; // r3

  if ( msg_get_value(5u) == 1 )
    return 2;
  v7 = off_132130;
  v8 = *a2;
  v9 = *((_DWORD *)off_132130 + 1);
  if ( *a2 )
    v8 = 1;
  *((_BYTE *)off_132130 + 375) = v8;
  if ( !v9 )
  {
    v10 = (_BYTE *)sub_12C92C(49, 0, 5, 1u);
    v11 = *((unsigned __int8 *)v7 + 375);
    v7[4] = 255;
    if ( v11 )
      LOBYTE(v11) = *((_BYTE *)v7 + 376);
    *v10 = v11;
    sdio_buffer_prepare_n_4e8((int)v10);
    sub_12CD34(5u, 1);
  }
  sub_12CA10(5140, a4, a3);
  return 0;
}

