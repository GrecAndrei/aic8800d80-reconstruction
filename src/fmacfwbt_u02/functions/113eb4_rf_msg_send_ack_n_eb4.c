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

// sleep_exit_critical @ 0x113eb4, size 56 bytes
// Doc: sleep_exit_critical [ipc]: Send RF message ack to host via IPC call
// sleep_exit_critical [ipc]: Send RF message ack to host via IPC call
int sleep_exit_critical()
{
  int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  rf_wait_idle();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_113EEC = 1;
  }
  v0 = (int *)off_113EF0;
  ++*(uint32_t *)off_113EF0;
  result = set_system_flag_2(128);
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

