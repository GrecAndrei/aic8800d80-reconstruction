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

// ipc_dispatch_one @ 0x13eb0c, size 20 bytes
// Doc: sub_123EB0C [util]: Thin wrapper that computes diff and calls helper, restores stack
// sub_123EB0C [util]: Thin wrapper that computes diff and calls helper, restores stack
unsigned int  ipc_dispatch_one(int a1, unsigned int a2, int a3, int a4)
{
  return ipc_dispatch_cmd(a1, a2, a2 - a3, 1, a4);
}

