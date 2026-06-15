// cmd_dispatch_handler @ 0x117ae0, size 488 bytes
// Doc: cmd_dispatch_handler [util]: Dispatch handler switching on command opcode (r1)
// cmd_dispatch_handler [util]: Dispatch handler switching on command opcode (r1)
int __fastcall cmd_dispatch_handler(int a1, int a2)
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
  _BYTE *v19; // r3
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
  _DWORD *v30; // r3
  int v31; // [sp+4h] [bp-8h]

  if ( a2 == 5 )
    v4 = (char *)dword_117CCC;
  else
    v4 = (char *)off_117CC8 + 84 * a2;
  v5 = *(unsigned __int8 *)(a1 + 28);
  v6 = dword_117D00;
  v7 = *(_DWORD *)(a1 + 76);
  v8 = dword_117D00 + 1320 * v5;
  if ( bt_sub_121733C(v8)
    && ((v10 = *(unsigned __int8 *)(a1 + 28), *(_BYTE *)(v6 + 1320 * v10 + 106))
     || *(unsigned __int8 *)(a1 + 29) > 0x23u
     || *(_WORD *)(a1 + 4)
     || (v11 = *(_WORD *)(*(_DWORD *)(a1 + 72) + 108), (unsigned __int8)v11 != 192)
     && (unsigned __int8)v11 != 176
     && (v11 & 0xDF) != 0
     || (v12 = *((_DWORD *)off_117CD0 + 10)) == 0
     || *(unsigned __int8 *)(v12 + 24) <= 2u
     || (v13 = *(_DWORD *)(v6 + 1320 * v10 + 72)) == 0
     || (v31 = v13, sub_12ECB0(dword_117CD4, v12 == v13, (unsigned __int8)v11), v12 == v31))
    && sub_136C34(a1) )
  {
    *(_DWORD *)(v7 + 68) |= 0x100u;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_117CD8 = 1;
    }
    v14 = (int *)off_117CDC;
    v15 = *((_DWORD *)v4 + 11);
    v16 = v4[80] + 1;
    ++*(_DWORD *)off_117CDC;
    v4[80] = v16;
    if ( v15 )
      sub_11A308(a2);
    if ( !*((_DWORD *)v4 + 5) )
    {
      v30 = *(_DWORD **)(a1 + 72);
      v30[4] = dword_117CFC;
      v30[2] = a1;
      v30[3] = a1;
    }
    v17 = list_push_tail(v4 + 12);
    v18 = *((_DWORD *)off_117CE0 + 8);
    ++*((_DWORD *)off_117CC8 + 126);
    if ( v18 )
    {
      v19 = *(_BYTE **)off_117CE4;
      v17 = 0x80000000;
      *(_DWORD *)off_117CE8 = 0x80000000;
      if ( *v19 == 3 && v18 == v8 )
        *(_DWORD *)(v6 + 1320 * v5 + 120) = *((_DWORD *)off_117CEC + 4);
    }
    if ( **(_BYTE **)off_117CF0 == 2 && (*(_DWORD *)off_117CF4 & dword_117CF8) == 0 )
      sub_1143D0(v17, v18, *(_DWORD *)off_117CF4);
    if ( *v14 )
    {
      v20 = *v14 - 1;
      v21 = *(_DWORD *)off_117CD8;
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
      *(_DWORD *)off_117CD8 = 1;
    }
    v22 = *v14;
    v23 = *v14 + 1;
    v24 = *(_WORD *)(a1 + 82) | 1;
    *v14 = v23;
    *(_WORD *)(a1 + 82) = v24;
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
      *(_DWORD *)off_117CD8 = 1;
    }
    v27 = *(_DWORD *)(a1 + 72);
    ++*v14;
    sub_116EF4(a1, a1, v27, a2);
    if ( *v14 )
    {
      v28 = *v14 - 1;
      v29 = *(_DWORD *)off_117CD8;
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
    rf_bus_write2_n258((_BYTE *)a1, a2);
    return 1;
  }
}

