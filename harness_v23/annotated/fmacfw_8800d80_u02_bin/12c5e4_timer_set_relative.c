// v23 annotated: timer_set_relative @ 0x12c5e4
// Original: 12c5e4_timer_set_relative.c
// Primary struct: <unclustered>
//
// timer_set_relative @ 0x12c5e4, size 288 bytes
// Doc: message_dispatch_n_382 [ipc]: Dispatch message with index increment and handler resolve (variant 382)
// message_dispatch_n_382 [ipc]: Dispatch message with index increment and handler resolve (variant 382)
int __fastcall timer_set_relative(int a1, int a2, unsigned int a3)
{
  __int16 **v3; // r11
  int *v7; // r8
  _DWORD *v8; // r10
  int v9; // r6
  int v10; // r4
  int v11; // r2
  int v12; // r0
  unsigned int v13; // r5
  int result; // r0
  int v15; // r3
  int v16; // r2
  int v17; // r0

  v3 = (__int16 **)off_12C730;
  if ( **(__int16 **)off_12C730 < 0 )
  {
    if ( a3 )
    {
      if ( a3 > ipc_message_dispatch )
        sub_12F46C(message_dispatch_n_268, message_dispatch_n_26c, 148);
    }
    else
    {
      sub_12F46C(dword_12C728, message_dispatch_n_26c, 147);
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)message_dispatch_n_288 = 1;
  }
  v7 = (int *)message_dispatch_n_258;
  v8 = msg_dispatch_322;
  v9 = *((_DWORD *)msg_dispatch_322 + 5);
  ++*(_DWORD *)message_dispatch_n_258;
  if ( v9 )
    v9 = *(unsigned __int16 *)(v9 + 4) == a1 && *(unsigned __int16 *)(v9 + 6) == a2;
  v10 = list_find_remove_ca3c(message_dispatch_n_280, dword_12C708, a2 | (a1 << 16));
  if ( !v10 )
  {
    v17 = message_dispatch_n158(12);
    v10 = v17;
    if ( **v3 < 0 && !v17 )
      sub_12F46C(message_dispatch_n_260, message_dispatch_n_26c, 165);
    *(_WORD *)(v10 + 4) = a1;
    *(_WORD *)(v10 + 6) = a2;
  }
  v11 = dword_12C714;
  v12 = message_dispatch_n_280;
  v13 = a3 + *((_DWORD *)message_dispatch_n_27c + 4);
  *(_DWORD *)(v10 + 8) = v13;
  result = list_insert_sorted_d380(v12, v10, v11);
  if ( v9 )
  {
    v10 = v8[5];
    if ( !v10 )
      goto message_dispatch_n_330;
LABEL_15:
    result = timestamp_update(message_dispatch_n_274, *(_DWORD *)(v10 + 8));
    goto message_dispatch_n_330;
  }
  if ( v8[5] == v10 )
    goto LABEL_15;
message_dispatch_n_330:
  if ( *v7 && (v15 = *v7 - 1, v16 = *(_DWORD *)message_dispatch_n_288, (*v7 = v15) == 0) && v16 )
  {
    __enable_irq();
    if ( (int)(v13 - *((_DWORD *)message_dispatch_n_27c + 4)) < 0 )
      return irq_nesting_or_d104(0x10000000);
  }
  else if ( (int)(v13 - *((_DWORD *)message_dispatch_n_27c + 4)) < 0 )
  {
    return irq_nesting_or_d104(0x10000000);
  }
  return result;
}

