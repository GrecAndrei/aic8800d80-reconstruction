// rf_mem_write_n3f8 @ 0x1131bc, size 156 bytes
// Doc: rf_mem_write_n3f8 [rf]: Write to RF memory region n3f8
// rf_mem_write_n3f8 [rf]: Write to RF memory region n3f8
void rf_mem_write_n3f8()
{
  int *v0; // r4
  int v1; // r0
  uint8_t *v2; // r1
  int v3; // r0
  unsigned __int16 v4; // r3
  int v5; // r3
  int v6; // r2
  int v7; // r3
  int v8; // r2
  int v9; // r3
  int v10; // r0
  int v11; // r1
  int v12; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_113258 = 1;
  }
  v0 = (int *)off_11325C;
  v1 = dword_113260;
  ++*(uint32_t *)off_11325C;
  list_push_tail(v1);
  v2 = off_113268;
  v3 = *(unsigned __int8 *)off_113268;
  v4 = *(uint16_t *)off_113264 + 1;
  *(uint16_t *)off_113264 = v4;
  if ( v3 && *(unsigned __int8 *)off_11326C <= (unsigned int)v4 )
  {
    v7 = *(unsigned __int8 *)off_113270;
    *v2 = 0;
    if ( v7 )
      *((uint32_t *)off_113274 + 512) &= ~0x2000u;
    else
      *((uint32_t *)off_113274 + 713) &= ~1u;
    hw_event_flag(1);
    event_queue_push(1069, 1);
    v10 = sub_11F74C(512, dword_113278, v8, v9);
    if ( !*(uint8_t *)off_11327C )
      sub_112F6C(v10, v11, v12, *(unsigned __int8 *)off_11327C);
  }
  if ( *v0 )
  {
    v5 = *v0 - 1;
    v6 = *(uint32_t *)off_113258;
    *v0 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
}

