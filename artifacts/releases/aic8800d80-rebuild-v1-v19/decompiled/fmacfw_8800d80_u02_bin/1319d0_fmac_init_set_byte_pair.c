// fmac_init_set_byte_pair @ 0x1319d0, size 138 bytes
// Doc: fmac_init_set_byte_pair [rf]: Reads byte pair from r1, initializes RF state structure
// fmac_init_set_byte_pair [rf]: Reads byte pair from r1, initializes RF state structure
int __fastcall fmac_init_set_byte_pair(int a1, _BYTE *a2, unsigned int a3, __int16 a4)
{
  _DWORD *v5; // r5
  int v6; // r7
  int v8; // r0
  int v9; // r0
  int v10; // r3
  _BYTE *v12; // r0
  int v13; // r3
  char v14; // r3
  unsigned int v15; // [sp+4h] [bp-8h]

  v5 = off_131A5C;
  v6 = *((_DWORD *)off_131A5C + 1);
  v8 = 1 << a2[1];
  if ( *a2 )
    v9 = v8 | v6;
  else
    v9 = v6 & ~v8;
  v10 = *((unsigned __int8 *)off_131A5C + 375);
  *((_DWORD *)off_131A5C + 1) = v9;
  if ( !v10 )
    goto LABEL_7;
  v15 = a3;
  if ( msg_get_value(5u) == 1 )
    return 2;
  LOWORD(a3) = v15;
  if ( (_BYTE)v6 )
  {
    if ( *a2 )
    {
LABEL_7:
      sub_12CA10(5146, a4, a3);
      return 0;
    }
  }
  else if ( !*a2 )
  {
    goto LABEL_7;
  }
  v12 = (_BYTE *)sub_12C92C(49, 0, v15, 1u);
  v13 = v5[1];
  *((_WORD *)v5 + 4) = a4;
  if ( v13 )
    v14 = 0;
  else
    v14 = *((_BYTE *)v5 + 376);
  *v12 = v14;
  sdio_buffer_prepare_n_4e8((int)v12);
  sub_12CD34(v15, 1);
  return 0;
}

