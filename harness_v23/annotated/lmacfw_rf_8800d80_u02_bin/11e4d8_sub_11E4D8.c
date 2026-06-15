// v23 annotated: sub_11E4D8 @ 0x11e4d8
// Original: 11e4d8_sub_11E4D8.c
// Primary struct: <unclustered>
//
// sub_11E4D8 @ 0x11e4d8, size 222 bytes
int sub_11E4D8()
{
  int *v0; // r5
  int v1; // r0
  int result; // r0
  unsigned __int16 *v3; // r4
  int v4; // r3
  int v5; // r2
  int (__fastcall *v6)(_DWORD, unsigned __int16 *, _DWORD, _DWORD); // r6
  int v7; // r2
  int v8; // r3
  int v9; // r3
  int v10; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_11E5B8 = 1;
  }
  v0 = (int *)off_11E5BC;
  v1 = dword_11E5C0;
  ++*(_DWORD *)off_11E5BC;
  result = sub_11E7AC(v1);
  v3 = (unsigned __int16 *)result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(_DWORD *)off_11E5B8;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (int (__fastcall *)(_DWORD, unsigned __int16 *, _DWORD, _DWORD))sub_11E3FC(
                                                                           *(unsigned __int16 *)(result + 4),
                                                                           *(unsigned __int16 *)(result + 6));
    msg_parse(dword_11E5C4, v3[2]);
    if ( v6 )
    {
      result = v6(v3[2], v3 + 6, v3[3], v3[4]);
      if ( result == 1 )
        goto LABEL_12;
      if ( result == 2 )
      {
        result = list_push_tail(dword_11E5D4);
        goto LABEL_12;
      }
      if ( result )
      {
        if ( **(__int16 **)off_11E5C8 < 0 )
          result = rf_cmd_send_n264(dword_11E5DC, dword_11E5D8, 360);
        goto LABEL_12;
      }
    }
    else
    {
      msg_parse(dword_11E5D0, v3[2]);
    }
    result = sub_11DEE8((int)v3);
  }
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_11E5B8 = 1;
  }
  v7 = *((_DWORD *)off_11E5CC + 1);
  v8 = *v0 + 1;
  *v0 = v8;
  if ( !v7 )
  {
    result = sub_11E628(0x4000000);
    v8 = *v0;
  }
  if ( v8 )
  {
    v9 = v8 - 1;
    v10 = *(_DWORD *)off_11E5B8;
    *v0 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}

