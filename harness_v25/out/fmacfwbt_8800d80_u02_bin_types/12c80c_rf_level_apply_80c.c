// rf_level_apply_80c @ 0x12c80c, size 288 bytes
// Doc: message_dispatch_n_2fc [ipc]: Top-level message dispatcher (epilogue/frame restore).
// message_dispatch_n_2fc [ipc]: Top-level message dispatcher (epilogue/frame restore).
int  rf_level_apply_80c(int a1, int a2, unsigned int a3)
{
  __int16 **v3; // r11
  int *v7; // r8
  uint32_t *v8; // r10
  int v9; // r6
  int v10; // r4
  int v11; // r2
  int v12; // r0
  unsigned int v13; // r5
  int result; // r0
  int v15; // r3
  int v16; // r2
  int v17; // r0

  v3 = (__int16 **)off_12C958;
  if ( **(__int16 **)off_12C958 < 0 )
  {
    if ( a3 )
    {
      if ( a3 > dword_12C944 )
        sub_12F694(dword_12C94C, message_dispatch_n_26c_c948, 148);
    }
    else
    {
      sub_12F694(message_dispatch_n_264, message_dispatch_n_26c_c948, 147);
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)message_dispatch_n_288_c92c = 1;
  }
  v7 = (int *)off_12C95C;
  v8 = off_12C960;
  v9 = *((uint32_t *)off_12C960 + 5);
  ++*(uint32_t *)off_12C95C;
  if ( v9 )
    v9 = *(unsigned __int16 *)(v9 + 4) == a1 && *(unsigned __int16 *)(v9 + 6) == a2;
  v10 = sub_12CC64(dword_12C934, message_dispatch_n_284, a2 | (a1 << 16));
  if ( !v10 )
  {
    v17 = message_dispatch_n158(12);
    v10 = v17;
    if ( **v3 < 0 && !v17 )
      sub_12F694(dword_12C954, message_dispatch_n_26c_c948, 165);
    *(uint16_t *)(v10 + 4) = a1;
    *(uint16_t *)(v10 + 6) = a2;
  }
  v11 = dword_12C93C;
  v12 = dword_12C934;
  v13 = a3 + *((uint32_t *)message_dispatch_n_27c + 4);
  *(uint32_t *)(v10 + 8) = v13;
  result = list_insert_sorted(v12, v10, v11);
  if ( v9 )
  {
    v10 = v8[5];
    if ( !v10 )
      goto LABEL_10;
message_dispatch_n_308:
    result = timestamp_update_4f60(message_dispatch_n_274, *(uint32_t *)(v10 + 8));
    goto LABEL_10;
  }
  if ( v8[5] == v10 )
    goto message_dispatch_n_308;
LABEL_10:
  if ( *v7 && (v15 = *v7 - 1, v16 = *(uint32_t *)message_dispatch_n_288_c92c, (*v7 = v15) == 0) && v16 )
  {
    __enable_irq();
    if ( (int)(v13 - *((uint32_t *)message_dispatch_n_27c + 4)) < 0 )
      return irq_nesting_or(0x10000000);
  }
  else if ( (int)(v13 - *((uint32_t *)message_dispatch_n_27c + 4)) < 0 )
  {
    return irq_nesting_or(0x10000000);
  }
  return result;
}

