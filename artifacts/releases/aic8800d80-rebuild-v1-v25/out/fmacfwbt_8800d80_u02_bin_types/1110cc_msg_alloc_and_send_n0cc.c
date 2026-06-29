// msg_alloc_and_send_n0cc @ 0x1110cc, size 118 bytes
// Doc: msg_alloc_and_send_n0cc [ipc]: Allocate message slot and forward to handler
// msg_alloc_and_send_n0cc [ipc]: Allocate message slot and forward to handler
int  msg_alloc_and_send_n0cc(char a1, int a2, int a3)
{
  uint32_t *v6; // r0
  uint32_t *v7; // r4
  uint32_t *v8; // r6
  int v9; // r2
  int v10; // r3

  v6 = log_free_dispatch_n49e(4);
  if ( !v6 )
    return log_printf(dword_11114C);
  v7 = v6;
  v8 = (uint32_t *)log_free_dispatch_n2b4();
  if ( v8 )
  {
    *(uint8_t *)v7 = a3;
    *((uint8_t *)v7 + 1) = BYTE1(a3) & 0xF;
    *((uint8_t *)v7 + 2) = a1;
    *((uint8_t *)v7 + 3) = 0;
    sub_14380C(v7 + 1, a2, a3);
    v9 = v8[2];
    v10 = dword_111144;
    v8[1] = 0;
    *v8 = v7;
    v8[2] = (unsigned __int16)(a3 + 4) | v10 & v9 | 0x80000000;
    return log_queue_push((int)v8);
  }
  else
  {
    log_printf(dword_111148);
    return log_free_dispatch_2(v7);
  }
}

