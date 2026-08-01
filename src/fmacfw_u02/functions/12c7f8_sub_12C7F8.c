#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

extern uint32_t off_12C8A8;

// ke_event_schedule @ 0x12c7f8, size 166 bytes
// Doc: message_dispatch_n_170 [ipc]: Compares message timestamp/delta against a reference value
// message_dispatch_n_170 [ipc]: Compares message timestamp/delta against a reference value
int ke_event_schedule()
{
  uint32_t *v0; // r7
  int *v1; // r5
  int *v2; // r9
  uint32_t *v3; // r6
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
    unknown_func_12d14c(0x10000000);
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
    v5 = *(uint32_t *)(v12 + 8);
    if ( v5 - v3[4] - 50 >= 0 )
    {
      result = unknown_worker((int)v4, v5);
      if ( *(uint32_t *)(v12 + 8) - v3[4] >= 0 )
      {
        if ( *v1 )
        {
          v16 = *v1 - 1;
          v17 = *(uint32_t *)message_dispatch_n_dc;
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
    v7 = mem_word_load(message_dispatch_e0);
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
    ke_msg_send_no_param(*(uint16_t *)(v7 + 4), *(uint16_t *)(v7 + 6), 255);
    tx_pkt_enqueue(v8);
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

