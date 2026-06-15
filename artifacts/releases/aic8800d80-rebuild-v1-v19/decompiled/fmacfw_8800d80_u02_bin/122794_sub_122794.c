// sub_122794 @ 0x122794, size 214 bytes
// Doc: sub_12227A0 [unknown]: Helper: save r0 in r4 and call with r4,r5,r6,lr
// sub_12227A0 [unknown]: Helper: save r0 in r4 and call with r4,r5,r6,lr
char *__fastcall sub_122794(char *result)
{
  int v1; // r4
  int v2; // r6
  int v3; // r5
  unsigned int v4; // r3
  int v5; // r2
  unsigned __int8 *v6; // r1
  unsigned int v7; // r2
  _BYTE *v8; // r3
  unsigned int v9; // r3

  if ( result[108] )
  {
    v1 = (int)result;
    if ( result[146] && result[148] )
    {
      v9 = (unsigned __int8)(result[146] - 1);
      result[146] = v9;
      if ( v9 <= 1 )
        return (char *)sub_120314((int)result);
      if ( v9 == 2 )
        tx_send_msg_n25dc(result[107], 0);
    }
    v2 = *(_DWORD *)(v1 + 36);
    v3 = *(_DWORD *)(dword_12286C + 696 * *(unsigned __int8 *)(v1 + 116) + 8) + v2;
    if ( v1 != *((_DWORD *)off_122870 + 8)
      || (v8 = off_122878, *(_DWORD *)(v1 + 36) = v3, !v8[189]) && **(_BYTE **)off_12287C != 2 )
    {
      timestamp_update(v1 + 24, v3);
    }
    mmio_read_status_reg(v1);
    fmac_status_chk_4c8(v1, *(_DWORD *)(v1 + 136) + v2);
    result = (char *)fmac_handler_dispatch(v1, v2, v3);
    if ( !result )
    {
      v4 = (unsigned __int8)(*(_BYTE *)(v1 + 128) + 1);
      v5 = *(_DWORD *)(v1 + 4) | 1;
      v6 = *(unsigned __int8 **)off_122874;
      *(_BYTE *)(v1 + 128) = v4;
      *(_DWORD *)(v1 + 4) = v5;
      v7 = *v6;
      if ( v4 > v7 )
      {
        return (char *)sub_11908C(*(unsigned __int8 *)(v1 + 116), (int)off_122880, v1);
      }
      else if ( v4 == v7 )
      {
        return (char *)rf_status_get_or_init(v1);
      }
    }
  }
  return result;
}

