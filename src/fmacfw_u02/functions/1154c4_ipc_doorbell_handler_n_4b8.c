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

// ipc_doorbell_handler_n_4b8 @ 0x1154c4, size 12 bytes
// Doc: ipc_doorbell_handler_n_4ae [ipc]: Handle IPC doorbell interrupt with sub-id 0x65 (sign-extended)
// ipc_doorbell_handler_n_4ae [ipc]: Handle IPC doorbell interrupt with sub-id 0x65 (sign-extended)
int  ipc_doorbell_handler_n_4b8(int a1, int a2)
{
  int v2; // r0

  v2 = ipc_doorbell_handler_n_4a7;
  *(uint8_t *)message_dispatch_n_2ca = 0;
  return msg_parse(v2, a2, 0);
}

