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

extern uint32_t off_113EEC;
extern uint32_t off_113EF0;

// rf_msg_send_ack_n_eb4 @ 0x113eb4, size 56 bytes
// Doc: rf_msg_send_ack_n_eb4 [ipc]: Send RF message ack to host via IPC call
// rf_msg_send_ack_n_eb4 [ipc]: Send RF message ack to host via IPC call
int rf_msg_send_ack_n_eb4()
{
  int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  init_alloc_0x200000();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_113EEC = 1;
  }
  v0 = (int *)off_113EF0;
  ++*(uint32_t *)off_113EF0;
  result = sub_12D374(128);
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(uint32_t *)off_113EEC;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}

