// v23 annotated: sub_1231D4 @ 0x1231d4
// Original: 1231d4_sub_1231D4.c
// Primary struct: <unclustered>
//
// sub_1231D4 @ 0x1231d4, size 254 bytes
int __fastcall sub_1231D4(int a1, int *a2, int a3, int a4)
{
  int v5; // r6
  int v6; // r0
  int v7; // r2
  int v8; // r4
  int v9; // r1
  int v10; // r0
  int result; // r0
  int v12; // r2
  int v13; // r0
  int v14; // r1
  _DWORD *v15; // r6
  int v16; // r3
  int v17; // r1
  int v18; // r2
  int inited; // r0
  unsigned __int8 *v20; // r5
  char v21; // r0
  int v22; // r1
  _DWORD *v23; // r5
  int v24; // r0
  int v25; // r0
  int v26; // r1

  v5 = *a2;
  v6 = sub_12C92C(136, a4, a3, 8);
  v8 = v6;
  *(_DWORD *)v6 = v5;
  switch ( v5 )
  {
    case 0:
      v9 = *((unsigned __int8 *)a2 + 4);
      *((_BYTE *)off_1232D4 + 373) = v9;
      v10 = dword_1232D8;
      *(_BYTE *)(v8 + 4) = v9;
      msg_parse(v10, v9, v7);
      goto LABEL_3;
    case 1:
      v15 = off_1232D4;
      v16 = *((unsigned __int8 *)a2 + 4);
      v17 = *((unsigned __int8 *)off_1232D4 + 363);
      *((_BYTE *)off_1232D4 + 363) = v16;
      v18 = a2[2];
      v15[91] = v18;
      if ( v16 != v17 )
      {
        if ( v16 )
        {
          inited = fmac_init_state_load(v6);
          fmac_subhandler_n_05b4(inited);
        }
        else
        {
          fmac_post_init_n_42e();
        }
        v17 = *((unsigned __int8 *)v15 + 363);
      }
      *(_BYTE *)(v8 + 4) = v17;
      msg_parse(dword_1232E0, v17, v18);
      sdio_buffer_prepare_n_4e8(v8);
      result = 0;
      break;
    case 2:
      v20 = (unsigned __int8 *)off_1232D4;
      *(_BYTE *)(v6 + 4) = *((_BYTE *)off_1232D4 + 363);
      v21 = sub_130374();
      *(_BYTE *)(v8 + 5) = v21;
      msg_parse(dword_1232E4, v20[363], v21);
      sdio_buffer_prepare_n_4e8(v8);
      result = 0;
      break;
    case 3:
      v22 = a2[1];
      v23 = off_1232D4;
      v24 = dword_1232E8;
      *((_DWORD *)off_1232D4 + 98) = v22;
      msg_parse(v24, v22, v7);
      *(_DWORD *)(v8 + 4) = v23[98];
      sdio_buffer_prepare_n_4e8(v8);
      result = 0;
      break;
    case 4:
      v25 = dword_1232EC;
      v26 = *((_DWORD *)off_1232D4 + 98);
      *(_DWORD *)(v8 + 4) = v26;
      msg_parse(v25, v26, v7);
      sdio_buffer_prepare_n_4e8(v8);
      result = 0;
      break;
    case 5:
      v12 = *((_DWORD *)off_1232D4 + 98);
      v13 = dword_1232DC;
      v14 = (a2[2] ^ v12) & a2[1] ^ v12;
      *((_DWORD *)off_1232D4 + 98) = v14;
      *(_DWORD *)(v8 + 4) = v14;
      msg_parse(v13, v14, v12);
      sdio_buffer_prepare_n_4e8(v8);
      result = 0;
      break;
    default:
LABEL_3:
      sdio_buffer_prepare_n_4e8(v8);
      result = 0;
      break;
  }
  return result;
}

