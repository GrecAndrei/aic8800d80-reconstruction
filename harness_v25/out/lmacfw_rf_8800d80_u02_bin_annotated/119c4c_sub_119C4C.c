// fwstruct annotate: 119c4c_sub_119C4C.c
// sub_119C4C @ 0x119c4c, size 184 bytes
int __fastcall sub_119C4C(int a1, char *a2, int a3, int a4)
{
  _BYTE *v5; // r0
  __int16 **v6; // r6
  _BYTE *v7; // r5
  int v8; // r3

  v5 = (_BYTE *)rf_setup_dispatch(37, a4, a3, 2);
  v6 = (__int16 **)off_119D04;
  *v5 = 1;
  v7 = v5;
  if ( **v6 < 0 )
  {
    if ( (unsigned __int8)*a2 <= 3u || (rf_cmd_send_n264(dword_119D14, dword_119D0C, 1725), **v6 < 0) )
    {
      if ( (unsigned __int8)a2[4] > 0x20u )
        rf_cmd_send_n264(dword_119D10, dword_119D0C, 1726);
    }
  }
  switch ( a2[40] )
  {
    case 0:
    case 1:
    case 3:
      v8 = (*(_DWORD *)off_119D08 >> 6) & 1;
      goto LABEL_4;
    case 2:
    case 8:
      v8 = (*(_DWORD *)off_119D08 >> 7) & 1;
      goto LABEL_4;
    case 4:
      v8 = (*(_DWORD *)off_119D08 >> 13) & 1;
      goto LABEL_4;
    case 6:
    case 7:
      v8 = (*(_DWORD *)off_119D08 >> 9) & 1;
LABEL_4:
      if ( v8 && (unsigned __int8)a2[4] <= 0x20u && (unsigned __int8)*a2 <= 3u )
      {
        v7[1] = sub_118A60(a2);
        *v7 = 0;
      }
      break;
    default:
      break;
  }
  sub_11DE50(v7);
  return 0;
}

