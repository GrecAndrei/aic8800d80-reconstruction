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

extern uint32_t off_12F504;

// reset_global_0x18274c @ 0x12f4e8, size 26 bytes
// Doc: reset_global_0x18274c [ipc]: Initialize 8-byte buffer to zero at 0x18274c
// reset_global_0x18274c [ipc]: Initialize 8-byte buffer to zero at 0x18274c
int *reset_global_0x18274c()
{
  uint64_t *v0; // r4
  int *result; // r0

  v0 = off_12F504;
  result = memset((int *)off_12F504, 0, 8u);
  *v0 = 0x2FFFFFFFFLL;
  return result;
}

