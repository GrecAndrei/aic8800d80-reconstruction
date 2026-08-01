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

extern uint32_t off_12CB48;
extern uint32_t dword_12CB50;

// irq_lock_small @ 0x12cb00, size 72 bytes
// Doc: message_dispatch_n_82_cb32 [ipc]: Dispatch incoming message by ID
// message_dispatch_n_82_cb32 [ipc]: Dispatch incoming message by ID
int irq_lock_small()
{
  int *v0; // r5
  int v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12CB48 = 1;
  }
  v0 = (int *)message_dispatch_n_68;
  v1 = dword_12CB50;
  ++*(uint32_t *)message_dispatch_n_68;
  set_system_flag_2(0x10000000);
  while ( 1 )
  {
    result = list_pop_front(v1);
    if ( !result )
      break;
    hci_tx_packet(result);
  }
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_12CB48;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

