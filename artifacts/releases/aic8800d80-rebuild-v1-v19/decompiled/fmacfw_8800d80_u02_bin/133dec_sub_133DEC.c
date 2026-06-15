// sub_133DEC @ 0x133dec, size 154 bytes
int __fastcall sub_133DEC(int a1, unsigned __int16 *a2)
{
  int v3; // r6
  int *v4; // r4
  int v5; // r0
  int v6; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r2

  v3 = *((unsigned __int8 *)a2 + 2);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_133E88 = 1;
  }
  v4 = (int *)off_133E8C;
  ++*(_DWORD *)off_133E8C;
  if ( msg_get_value(6u) || *((_BYTE *)off_133E90 + 14) && message_dispatch_c8b4(6155, 6) )
  {
    if ( *v4 )
    {
      v10 = *v4 - 1;
      v11 = *(_DWORD *)off_133E88;
      *v4 = v10;
      if ( !v10 )
      {
        if ( v11 )
          __enable_irq();
      }
    }
    return 2;
  }
  else
  {
    if ( *v4 )
    {
      v8 = *v4 - 1;
      v9 = *(_DWORD *)off_133E88;
      *v4 = v8;
      if ( !v8 )
      {
        if ( v9 )
          __enable_irq();
      }
    }
    v5 = dword_133E94 + 1320 * v3;
    v6 = *(unsigned __int8 *)(v5 + 106);
    if ( !*(_BYTE *)(v5 + 106) && *(_BYTE *)(v5 + 108) )
    {
      fmac_msg_alloc_and_send(v5, *a2, 1);
      return v6;
    }
    else
    {
      sub_12CA10(6148, 13, 6);
      return 0;
    }
  }
}

