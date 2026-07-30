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

// message_dispatch_n_3dc @ 0x12c5b0, size 18 bytes
// Doc: message_dispatch_n_3da [ipc]: Check message index within dispatch table bound
// message_dispatch_n_3da [ipc]: Check message index within dispatch table bound
BOOL  message_dispatch_n_3dc(int a1, int a2)
{
  return *(uint32_t *)(a1 + 8) - *(uint32_t *)(a2 + 8) > (unsigned int)message_dispatch_n_3c8;
}

