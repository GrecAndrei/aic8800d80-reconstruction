// sub_12C964 @ 0x12c964, size 152 bytes
// Doc: message_dispatch_n_1de [ipc]: Dispatch message and compare against timestamp at 0x40501000
// message_dispatch_n_1de [ipc]: Dispatch message and compare against timestamp at 0x40501000
int __fastcall sub_12C964(int result, int a2)
{
  int *v2; // r5
  _DWORD *v3; // r6
  int v4; // r4
  int v5; // r3
  int v6; // r3
  int v7; // r2
  int v8; // r7
  int v9; // r0

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)message_dispatch_n_1b8_c9fc = 1;
  }
  v2 = (int *)message_dispatch_ca00;
  v3 = off_12CA04;
  v4 = *((_DWORD *)off_12CA04 + 5);
  v5 = *(_DWORD *)message_dispatch_ca00 + 1;
  *(_DWORD *)message_dispatch_ca00 = v5;
  if ( v4 )
  {
    if ( *(unsigned __int16 *)(v4 + 4) == result && *(unsigned __int16 *)(v4 + 6) == a2 )
    {
      sub_12D4F8(v3 + 5);
      v8 = v3[5];
      v9 = (int)(v3 + 8);
      if ( v8 )
      {
        timestamp_update_4f60(v9, *(_DWORD *)(v8 + 8));
        if ( **(__int16 **)message_dispatch_n_1a4_ca10 < 0
          && *(_DWORD *)(v8 + 8) - *((_DWORD *)message_dispatch_n_1a0_ca14 + 4) < 0 )
        {
          sub_12F694(dword_12CA1C, dword_12CA18, 232);
        }
      }
      else
      {
        timestamp_remove_058(v9);
      }
    }
    else
    {
      result = sub_12CC64(dword_12CA0C, dword_12CA08, a2 | (result << 16));
      v4 = result;
      if ( !result )
      {
        v5 = *v2;
        goto LABEL_8;
      }
    }
    result = buffer_pool_get(v4);
    v5 = *v2;
  }
LABEL_8:
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(_DWORD *)message_dispatch_n_1b8_c9fc;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

