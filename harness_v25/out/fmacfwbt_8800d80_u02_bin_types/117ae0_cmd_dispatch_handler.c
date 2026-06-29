// cmd_dispatch_handler @ 0x117ae0, size 488 bytes
// Doc: cmd_dispatch_handler [util]: Dispatch handler switching on command opcode (r1)
// cmd_dispatch_handler [util]: Dispatch handler switching on command opcode (r1)
int  cmd_dispatch_handler(int a1, int a2)
{
  char *v4; // r7
  int v5; // r10
  int v6; // r8
  int v7; // r11
  int v8; // r9
  int v10; // r3
  __int16 v11; // r1
  int v12; // r6
  int v13; // r3
  int *v14; // r6
  int v15; // r2
  char v16; // r3
  int v17; // r0
  int v18; // r1
  uint8_t *v19; // r3
  int v20; // r3
  int v21; // r2
  int v22; // r2
  int v23; // r1
  __int16 v24; // r3
  int *v25; // r3
  int v26; // r3
  int v27; // r2
  int v28; // r3
  int v29; // r2
  uint32_t *v30; // r3
  int v31; // [sp+4h] [bp-8h]

  if ( a2 == 5 )
    v4 = (char *)dword_117CCC;
  else
    v4 = (char *)off_117CC8 + 84 * a2;
  v5 = *(unsigned __int8 *)(a1 + 28);
  v6 = dword_117D00;
  v7 = *(uint32_t *)(a1 + 76);
  v8 = dword_117D00 + 1320 * v5;
  if ( bt_sub_121733C(v8)
    && ((v10 = *(unsigned __int8 *)(a1 + 28), *(uint8_t *)(v6 + 1320 * v10 + 106))
     || *(unsigned __int8 *)(a1 + 29) > 0x23u
     || *(uint16_t *)(a1 + 4)
     || (v11 = *(uint16_t *)(*(uint32_t *)(a1 + 72) + 108), (unsigned __int8)v11 != 192)
     && (unsigned __int8)v11 != 176
     && (v11 & 0xDF) != 0
     || (v12 = *((uint32_t *)off_117CD0 + 10)) == 0
     || *(unsigned __int8 *)(v12 + 24) <= 2u
     || (v13 = *(uint32_t *)(v6 + 1320 * v10 + 72)) == 0
     || (v31 = v13, sub_12ECB0(dword_117CD4, v12 == v13, (unsigned __int8)v11), v12 == v31))
    && sub_136C34(a1) )
  {
    *(uint32_t *)(v7 + 68) |= 0x100u;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_117CD8 = 1;
    }
    v14 = (int *)off_117CDC;
    v15 = *((uint32_t *)v4 + 11);
    v16 = v4[80] + 1;
    ++*(uint32_t *)off_117CDC;
    v4[80] = v16;
    if ( v15 )
      sub_11A308(a2);
    if ( !*((uint32_t *)v4 + 5) )
    {
      v30 = *(uint32_t **)(a1 + 72);
      v30[4] = dword_117CFC;
      v30[2] = a1;
      v30[3] = a1;
    }
    v17 = list_push_tail(v4 + 12);
    v18 = *((uint32_t *)off_117CE0 + 8);
    ++*((uint32_t *)off_117CC8 + 126);
    if ( v18 )
    {
      v19 = *(uint8_t **)off_117CE4;
      v17 = 0x80000000;
      *(uint32_t *)off_117CE8 = 0x80000000;
      if ( *v19 == 3 && v18 == v8 )
        *(uint32_t *)(v6 + 1320 * v5 + 120) = *((uint32_t *)off_117CEC + 4);
    }
    if ( **(uint8_t **)off_117CF0 == 2 && (*(uint32_t *)off_117CF4 & dword_117CF8) == 0 )
      sub_1143D0(v17, v18, *(uint32_t *)off_117CF4);
    if ( *v14 )
    {
      v20 = *v14 - 1;
      v21 = *(uint32_t *)off_117CD8;
      *v14 = v20;
      if ( !v20 )
      {
        if ( v21 )
          __enable_irq();
      }
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_117CD8 = 1;
    }
    v22 = *v14;
    v23 = *v14 + 1;
    v24 = *(uint16_t *)(a1 + 82) | 1;
    *v14 = v23;
    *(uint16_t *)(a1 + 82) = v24;
    if ( v23 )
    {
      v25 = (int *)off_117CD8;
      *v14 = v22;
      v26 = *v25;
      if ( !v22 )
      {
        if ( v26 )
          __enable_irq();
      }
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_117CD8 = 1;
    }
    v27 = *(uint32_t *)(a1 + 72);
    ++*v14;
    sub_116EF4(a1, a1, v27, a2);
    if ( *v14 )
    {
      v28 = *v14 - 1;
      v29 = *(uint32_t *)off_117CD8;
      *v14 = v28;
      if ( !v28 )
      {
        if ( v29 )
          __enable_irq();
      }
    }
    return 1;
  }
  else if ( *(unsigned __int8 *)(a1 + 29) == 255 )
  {
    sub_11913C(a1, 0);
    return 0;
  }
  else
  {
    rf_bus_write2_n258((uint8_t *)a1, a2);
    return 1;
  }
}

