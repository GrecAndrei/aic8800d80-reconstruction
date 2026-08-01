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

extern uint32_t off_12C924;
extern uint32_t dword_12C928;

// ke_int_lock_save @ 0x12c8d8, size 72 bytes
// Doc: message_dispatch_n_7c [ipc]: Dispatch IPC message by indexing into message table
// message_dispatch_n_7c [ipc]: Dispatch IPC message by indexing into message table
int ke_int_lock_save()
{
  int *v0; // r5
  int v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)message_dispatch_n_6c_c920 = 1;
  }
  v0 = (int *)off_12C924;
  v1 = dword_12C928;
  ++*(uint32_t *)off_12C924;
  unknown_func_12d14c(0x10000000);
  while ( 1 )
  {
    result = mem_word_load(v1);
    if ( !result )
      break;
    tx_pkt_enqueue(result);
  }
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)message_dispatch_n_6c_c920;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

