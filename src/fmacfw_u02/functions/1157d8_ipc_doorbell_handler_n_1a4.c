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

// check_event_flag @ 0x1157d8, size 346 bytes
// Doc: ipc_doorbell_handler_n_170 [ipc]: Handles IPC doorbell interrupts and clears status bits
// ipc_doorbell_handler_n_170 [ipc]: Handles IPC doorbell interrupts and clears status bits
void  check_event_flag(int a1, int a2)
{
  int v2; // r3
  int v3; // r1
  int v4; // r0
  uint32_t *v5; // r3

  v2 = **(uint16_t **)ipc_doorbell_handler_n_48;
  if ( (v2 & 1) != 0 )
    ((void ( *)(int, int, int))fmac_init_subsystems)(a1, a2, v2 << 31);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)ipc_doorbell_handler_938 = 1;
  }
  v3 = ipc_doorbell_handler_944;
  ++*(uint32_t *)ipc_doorbell_handler_n_40;
  check_status_bits(1024, v3);
  v4 = unknown_func_12d14c(0x80000000);
  rf_clear_status(v4);
  v5 = ipc_doorbell_handler_n_33;
  *(uint32_t *)ipc_doorbell_handler_n_33 &= 0xFFFFFFu;
  *v5 |= 0x10u;
  while ( 1 )
    ;
}

