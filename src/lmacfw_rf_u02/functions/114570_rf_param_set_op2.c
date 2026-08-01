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

// bus_read_12 @ 0x114570, size 10 bytes
// Doc: bus_read_12 [rf]: Set RF parameter via opcode 2 with 12-byte payload
// bus_read_12 [rf]: Set RF parameter via opcode 2 with 12-byte payload
int  bus_read_12(int a1)
{
  return ke_task_handler(2, a1, 0xCu);
}

