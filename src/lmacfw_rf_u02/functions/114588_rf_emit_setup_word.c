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

// mmio_read_4 @ 0x114588, size 10 bytes
// Doc: mmio_read_4 [rf]: Emits a 4-byte setup word (type 0x14) to RF path
// mmio_read_4 [rf]: Emits a 4-byte setup word (type 0x14) to RF path
int  mmio_read_4(int a1)
{
  return ke_task_handler(4, a1, 0x14u);
}

