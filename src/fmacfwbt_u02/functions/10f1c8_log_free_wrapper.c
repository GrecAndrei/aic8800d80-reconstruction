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

// wait_event @ 0x10f1c8, size 12 bytes
// Doc: wait_event [util]: Wrapper that frees log buffer and returns success
// wait_event [util]: Wrapper that frees log buffer and returns success
int  wait_event(int a1, int a2)
{
  memory_pool_free(a2);
  return 1;
}

