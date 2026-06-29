// fwstruct annotate: 136154_sub_136154.c
// sub_136154 @ 0x136154, size 148 bytes
// Doc: sub_1236154 [unknown]: Unknown behavioral stub at 0x1236154
// sub_1236154 [unknown]: Unknown behavioral stub at 0x1236154
int __fastcall sub_136154(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  int v7; // r2
  int v8; // r3
  int v9; // r1
  char v10; // r7
  char *v11; // r0
  int v13; // r0
  int v14; // r0
  int v15; // r1
  unsigned __int8 v16[5]; // [sp+7h] [bp-5h] BYREF

  v7 = a2[9];
  v8 = *a2;
  v16[0] = 0;
  msg_parse(dword_1361E8, dword_1361EC, v7, v8);
  v9 = dword_1361F0 + 1320 * a2[10];
  if ( *(_BYTE *)(v9 + 106) == 2 )
  {
    if ( *(_BYTE *)(v9 + 108) || msg_get_value(7u) )
    {
      v10 = 8;
    }
    else
    {
      v13 = sub_127D34(a2, v16);
      v10 = v13;
      if ( v13 )
      {
        v10 = 1;
      }
      else
      {
        v14 = a2[10];
        v15 = v16[0];
        *(_BYTE *)off_1361F4 = 1;
        sub_128888(v14, v15);
        *((_DWORD *)off_1361F8 + 1) |= 0x10u;
      }
    }
  }
  else
  {
    v10 = 4;
  }
  v11 = (char *)sub_12C92C(7173, a4, a3, 2u);
  *v11 = v10;
  v11[1] = v16[0];
  sdio_buffer_prepare_n_4e8((int)v11);
  return 0;
}

