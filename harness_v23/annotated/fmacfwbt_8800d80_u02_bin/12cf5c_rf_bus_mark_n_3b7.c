// v23 annotated: rf_bus_mark_n_3b7 @ 0x12cf5c
// Original: 12cf5c_rf_bus_mark_n_3b7.c
// Primary struct: <unclustered>
//
// rf_bus_mark_n_3b7 @ 0x12cf5c, size 278 bytes
// Doc: message_dispatch_n47e_d032 [ipc]: Dispatch IPC/control message
// message_dispatch_n47e_d032 [ipc]: Dispatch IPC/control message
_DWORD *__fastcall rf_bus_mark_n_3b7(unsigned int a1, int a2)
{
  __int16 **v2; // r7
  unsigned int v5; // r9
  int v6; // r6
  _WORD *v7; // r9
  _DWORD *result; // r0
  int (__fastcall *v9)(_DWORD *, int); // r8
  int v10; // r7
  int *v11; // r6
  int *v12; // r5
  int v13; // r0
  int v14; // r3
  int v15; // r2
  int v16; // r6

  v2 = (__int16 **)message_dispatch_n4c0;
  v5 = a1 >> 8;
  v6 = (unsigned __int8)a1;
  if ( **(__int16 **)message_dispatch_n4c0 >= 0 )
    goto LABEL_2;
  if ( (unsigned __int8)a1 > 0xDu )
  {
    sub_12F694(message_dispatch_n4e9, message_dispatch_n4dd, 173);
    if ( **v2 >= 0 )
    {
LABEL_2:
      v7 = (_WORD *)(*(_DWORD *)(dword_12D078 + 16 * v6 + 8) + 2 * v5);
      goto LABEL_3;
    }
    if ( v6 != 14 )
      sub_12F694(message_dispatch_n4f1, message_dispatch_n4ec, 183);
  }
  else if ( (unsigned __int8)a1 != 13 )
  {
    goto message_dispatch_n440_cff4;
  }
  sub_12F694(message_dispatch_n4f4, message_dispatch_n4dd, 174);
  if ( **v2 >= 0 )
    goto LABEL_2;
message_dispatch_n440_cff4:
  v16 = dword_12D078 + 16 * v6;
  if ( *(unsigned __int16 *)(v16 + 14) > v5 )
  {
    v7 = (_WORD *)(*(_DWORD *)(v16 + 8) + 2 * v5);
    if ( v7 )
      goto LABEL_3;
    goto LABEL_18;
  }
  sub_12F694(message_dispatch_n4e4, message_dispatch_n4dd, 175);
  v7 = (_WORD *)(*(_DWORD *)(v16 + 8) + 2 * v5);
  if ( **v2 < 0 && !v7 )
LABEL_18:
    sub_12F694(message_dispatch_n4e1, message_dispatch_n4dd, 180);
LABEL_3:
  result = (_DWORD *)sub_12ECB0(dword_12D07C, a1, a2);
  if ( (unsigned __int16)*v7 != a2 )
  {
    v9 = (int (__fastcall *)(_DWORD *, int))msg_dispatch_n4f8;
    v10 = message_dispatch_n4cd;
    v11 = (int *)message_dispatch_n4d1;
    *v7 = a2;
    while ( 1 )
    {
      result = sub_12CC64(v10, v9, a1);
      if ( !result )
        break;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v11 = 1;
      }
      v12 = (int *)off_12D088;
      v13 = message_dispatch_n4d9;
      ++*(_DWORD *)off_12D088;
      list_push_tail(v13);
      v14 = *v12 - 1;
      if ( *v12 )
      {
        v15 = *v11;
        *v12 = v14;
        if ( !v14 )
        {
          if ( v15 )
            __enable_irq();
        }
      }
      irq_nesting_or(0x4000000);
    }
  }
  return result;
}

