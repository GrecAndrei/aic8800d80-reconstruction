// v23 annotated: sub_1199CC @ 0x1199cc
// Original: 1199cc_sub_1199CC.c
// Primary struct: <unclustered>
//
// sub_1199CC @ 0x1199cc, size 254 bytes
// Doc: sub_12199CC [rf]: Allocates 0x88-byte context and initializes RF object
// sub_12199CC [rf]: Allocates 0x88-byte context and initializes RF object
int __fastcall sub_1199CC(int a1, int *a2, int a3, int a4)
{
  int v5; // r6
  int v6; // r0
  int v7; // r4
  int v8; // r1
  int v9; // r0
  int result; // r0
  int v11; // r0
  int v12; // r1
  _DWORD *v13; // r6
  int v14; // r3
  int v15; // r1
  int v16; // r0
  unsigned __int8 *v17; // r5
  int v18; // r1
  _DWORD *v19; // r5
  int v20; // r0
  int v21; // r0
  int v22; // r1

  v5 = *a2;
  v6 = rf_setup_dispatch(136, a4, a3, 8);
  v7 = v6;
  *(_DWORD *)v6 = v5;
  switch ( v5 )
  {
    case 0:
      v8 = *((unsigned __int8 *)a2 + 4);
      *((_BYTE *)off_119ACC + 373) = v8;
      v9 = dword_119AD0;
      *(_BYTE *)(v7 + 4) = v8;
      msg_parse(v9, v8);
      goto LABEL_3;
    case 1:
      v13 = off_119ACC;
      v14 = *((unsigned __int8 *)a2 + 4);
      v15 = *((unsigned __int8 *)off_119ACC + 363);
      *((_BYTE *)off_119ACC + 363) = v14;
      v13[91] = a2[2];
      if ( v14 != v15 )
      {
        if ( v14 )
        {
          v16 = rf_level_apply_n274(v6);
          sub_127108(v16);
        }
        else
        {
          rf_bus_write_n3d6_716c();
        }
        v15 = *((unsigned __int8 *)v13 + 363);
      }
      *(_BYTE *)(v7 + 4) = v15;
      msg_parse(dword_119AD8, v15);
      sub_11DE50(v7);
      result = 0;
      break;
    case 2:
      v17 = (unsigned __int8 *)off_119ACC;
      *(_BYTE *)(v6 + 4) = *((_BYTE *)off_119ACC + 363);
      *(_BYTE *)(v6 + 5) = sub_126E54();
      msg_parse(dword_119ADC, v17[363]);
      sub_11DE50(v7);
      result = 0;
      break;
    case 3:
      v18 = a2[1];
      v19 = off_119ACC;
      v20 = dword_119AE0;
      *((_DWORD *)off_119ACC + 98) = v18;
      msg_parse(v20, v18);
      *(_DWORD *)(v7 + 4) = v19[98];
      sub_11DE50(v7);
      result = 0;
      break;
    case 4:
      v21 = dword_119AE4;
      v22 = *((_DWORD *)off_119ACC + 98);
      *(_DWORD *)(v7 + 4) = v22;
      msg_parse(v21, v22);
      sub_11DE50(v7);
      result = 0;
      break;
    case 5:
      v11 = dword_119AD4;
      v12 = (a2[2] ^ *((_DWORD *)off_119ACC + 98)) & a2[1] ^ *((_DWORD *)off_119ACC + 98);
      *((_DWORD *)off_119ACC + 98) = v12;
      *(_DWORD *)(v7 + 4) = v12;
      msg_parse(v11, v12);
      sub_11DE50(v7);
      result = 0;
      break;
    default:
LABEL_3:
      sub_11DE50(v7);
      result = 0;
      break;
  }
  return result;
}

