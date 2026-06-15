// v23 annotated: sub_12C7F8 @ 0x12c7f8
// Original: 12c7f8_sub_12C7F8.c
// Primary struct: <unclustered>
//
// sub_12C7F8 @ 0x12c7f8, size 166 bytes
// Doc: message_dispatch_n_170 [ipc]: Compares message timestamp/delta against a reference value
// message_dispatch_n_170 [ipc]: Compares message timestamp/delta against a reference value
int sub_12C7F8()
{
  _DWORD *v0; // r7
  int *v1; // r5
  int *v2; // r9
  _DWORD *v3; // r6
  char *v4; // r8
  int v5; // r1
  int result; // r0
  int v7; // r0
  int v8; // r4
  int v9; // r2
  int v10; // r3
  int v11; // r2
  int v12; // r4
  int v13; // r3
  int *v14; // r3
  int v15; // r3
  int v16; // r3
  int v17; // r2

  v0 = msg_dispatch_hash_ec;
  v1 = (int *)message_dispatch_n_e8;
  v2 = (int *)message_dispatch_n_dc;
  v3 = off_12C8A8;
  v4 = (char *)msg_dispatch_hash_ec + 32;
  while ( 1 )
  {
    clear_flags(0x10000000);
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *v2 = 1;
    }
    v11 = *v1;
    v12 = v0[5];
    v13 = *v1 + 1;
    result = (int)v4;
    *v1 = v13;
    if ( !v12 )
      break;
    v5 = *(_DWORD *)(v12 + 8);
    if ( v5 - v3[4] - 50 >= 0 )
    {
      result = timestamp_update((int)v4, v5);
      if ( *(_DWORD *)(v12 + 8) - v3[4] >= 0 )
      {
        if ( *v1 )
        {
          v16 = *v1 - 1;
          v17 = *(_DWORD *)message_dispatch_n_dc;
          *v1 = v16;
          if ( !v16 )
          {
            if ( v17 )
              goto LABEL_15;
          }
        }
        return result;
      }
    }
    v7 = rf_bus_mark_n100_d2d0(message_dispatch_e0);
    v8 = v7;
    v9 = *v1 - 1;
    if ( *v1 )
    {
      v10 = *v2;
      *v1 = v9;
      if ( !v9 )
      {
        if ( v10 )
          __enable_irq();
      }
    }
    sub_12CA10(*(unsigned __int16 *)(v7 + 4), *(unsigned __int16 *)(v7 + 6), 255);
    sub_12CBC8(v8);
  }
  if ( v13 )
  {
    v14 = (int *)message_dispatch_n_dc;
    *v1 = v11;
    v15 = *v14;
    if ( !v11 )
    {
      if ( v15 )
LABEL_15:
        __enable_irq();
    }
  }
  return result;
}

