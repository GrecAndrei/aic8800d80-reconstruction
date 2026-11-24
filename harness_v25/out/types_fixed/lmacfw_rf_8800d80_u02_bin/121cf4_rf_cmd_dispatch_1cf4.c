// rf_cmd_dispatch_1cf4 @ 0x121cf4, size 304 bytes
// Doc: rf_cmd_dispatch_table [rf]: Dispatches RF command via table with size bounds 0x60/0x7f
// rf_cmd_dispatch_table [rf]: Dispatches RF command via table with size bounds 0x60/0x7f
int __fastcall rf_cmd_dispatch_1cf4(unsigned int a1, _BYTE *a2, int a3)
{
  int *v3; // r6
  char v4; // r4
  int *v6; // r7
  _DWORD *v7; // r3
  int v8; // r2
  int *v9; // r8
  int result; // r0
  int v11; // r0
  int *v12; // r2
  _DWORD *v13; // r3
  int *v14; // r8
  int v15; // r1
  unsigned int v16; // r0
  unsigned __int8 *v17; // r0
  int v18; // r2
  int v19; // r3
  unsigned int v20; // r1
  _BYTE *v21; // r0
  _DWORD *v22; // r3
  _BYTE *v23; // r3
  int v24; // r2

  v3 = (int *)rf_mem_write_1e24;
  v4 = a1;
  if ( *(_DWORD *)rf_mem_write_1e24 )
  {
    if ( !a3 )
      goto rf_cmd_queue_next_n_42b;
rf_cmd_dispatch_n_1f0:
    v11 = sub_1288C0(a3);
    v12 = (int *)rf_state_check_n_20c;
    v13 = rf_cmd_dispatch_e30;
    *v3 = (int)a2;
    *v12 = v11;
    *v13 = 0;
    return 0;
  }
  *(_DWORD *)rf_mem_write_1e24 = a2;
  if ( a3 )
    goto rf_cmd_dispatch_n_1f0;
rf_cmd_queue_next_n_42b:
  v6 = (int *)rf_state_check_n_20c;
  v7 = off_121E2C;
  v8 = *(_DWORD *)rf_state_check_n_20c;
  *(_DWORD *)off_121E2C = *(_DWORD *)rf_state_check_n_20c;
  if ( a1 <= 0x17 )
  {
    switch ( a1 )
    {
      case 0u:
        return -1;
      case 3u:
        result = 0;
        *a2 = 0;
        return result;
      case 8u:
        goto rf_mem_write_n_28c;
      case 0xAu:
      case 0xDu:
        v21 = (_BYTE *)rf_mem_write_n_1f7;
        *(_BYTE *)*v3 = 0;
        uart_puts(v21);
        return *v3 - (_DWORD)a2;
      case 0x15u:
        v22 = rf_cmd_dispatch_e30;
        *v3 = (int)a2;
        *v22 = 0;
        return -1;
      case 0x17u:
        v14 = (int *)rf_cmd_dispatch_e30;
        v15 = *v3;
        if ( *(_DWORD *)rf_cmd_dispatch_e30 )
        {
          v16 = (unsigned int)a2;
          while ( 1 )
          {
            v17 = (unsigned __int8 *)sub_121B40(v16, v15, v8);
            v18 = *v14;
            *v3 = (int)v17;
            v15 = (int)v17;
            if ( v18 <= 0 )
              break;
            v19 = *v17;
            v16 = (unsigned int)a2;
            if ( v19 == 32 )
              break;
            v8 = *v6;
          }
        }
        return -1;
      default:
        v9 = (int *)rf_cmd_dispatch_e30;
        if ( *(int *)rf_cmd_dispatch_e30 > 61 )
          goto rf_cmd_dispatch_n_204;
        if ( a1 != 9 )
          goto rf_mem_write_n_213;
        uart_puts((_BYTE *)(dword_121E38 + (v8 & 7)));
        *(_DWORD *)off_121E2C = (*(_DWORD *)off_121E2C & 0xFFFFFFF8) + 8;
        break;
    }
    goto rf_mem_write_n_22b;
  }
  if ( a1 == 127 )
  {
rf_mem_write_n_28c:
    v20 = *v3;
    if ( *(_DWORD *)rf_cmd_dispatch_e30 )
      v20 = sub_121B40((unsigned int)a2, v20, v8);
    *v3 = v20;
    return -1;
  }
  else
  {
    v9 = (int *)rf_cmd_dispatch_e30;
    if ( *(int *)rf_cmd_dispatch_e30 <= 61 )
    {
rf_mem_write_n_213:
      *v7 = v8 + 1;
      uart_putc(a1);
rf_mem_write_n_22b:
      v23 = (_BYTE *)*v3;
      *v23 = v4;
      v24 = *v9 + 1;
      *v3 = (int)(v23 + 1);
      *v9 = v24;
      return -1;
    }
rf_cmd_dispatch_n_204:
    uart_putc(7);
    return -1;
  }
}

