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

extern uint32_t off_1210E0;

// ipc_doorbell_handler_n_3d6 @ 0x1210b4, size 42 bytes
// Doc: ipc_doorbell_handler_n_3d6 [ipc]: IPC doorbell interrupt handler variant 3d6
// ipc_doorbell_handler_n_3d6 [ipc]: IPC doorbell interrupt handler variant 3d6
int ipc_doorbell_handler_n_3d6()
{
  if ( msg_get_value(0) == 1 )
    *(uint32_t *)off_1210E0 = 48;
  return sub_12CD34(0);
}

