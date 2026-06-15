// fmac_flag_read_a0 @ 0x11b490, size 204 bytes
// Doc: fmac_flag_read_a0 [mac]: Reads status flag byte at offset 0xa0 from fmac state
// fmac_flag_read_a0 [mac]: Reads status flag byte at offset 0xa0 from fmac state
int __fastcall fmac_flag_read_a0(int result, int a2, int a3, int a4)
{
  _DWORD *v4; // r5
  char *v5; // r3
  int v6; // r2
  int v7; // r4
  int v8; // r6
  BOOL v9; // r3
  __int16 **v10; // r7

  v4 = off_11B55C;
  if ( *((_BYTE *)off_11B55C + 160) )
  {
    v5 = (char *)off_11B55C + 28 * result;
    v6 = *((_DWORD *)v5 + 6);
    v5[47] = 1;
    v7 = result;
    v8 = 8 * result;
    if ( !v6 )
    {
      switch ( (char)result )
      {
        case 0:
          v9 = (*(_DWORD *)off_11B560 & 0x30) == 0;
          goto LABEL_6;
        case 1:
          v9 = (*(_DWORD *)off_11B560 & 0x300) == 0;
          goto LABEL_6;
        case 2:
          v9 = (*(_DWORD *)off_11B560 & 0x3000) == 0;
          goto LABEL_6;
        case 3:
          v9 = (*(_DWORD *)off_11B560 & 0x30000) == 0;
          goto LABEL_6;
        case 4:
          v9 = (*(_DWORD *)off_11B560 & 3) == 0;
LABEL_6:
          if ( v9 )
            goto LABEL_9;
          v10 = (__int16 **)off_11B564;
          break;
        default:
          v10 = (__int16 **)off_11B564;
          if ( **(__int16 **)off_11B564 >= 0 )
            goto LABEL_9;
          sub_12F46C(dword_11B570, dword_11B574, 520);
          break;
      }
      if ( **v10 < 0 )
      {
        return fmac_phy_op_handler(dword_11B570, dword_11B56C, 684, a4);
      }
      else
      {
LABEL_9:
        v4[v8 - v7 + 6] = dword_11B568;
        return sub_11B3B8(v7);
      }
    }
  }
  return result;
}

