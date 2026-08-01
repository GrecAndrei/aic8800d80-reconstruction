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

extern uint32_t off_1138DC;

// memory_barrier_write @ 0x1138d0, size 10 bytes
// Doc: sub_12138D0 [unknown]: Unidentified function at 0x12138D0
// sub_12138D0 [unknown]: Unidentified function at 0x12138D0
void memory_barrier_write()
{
  **(uint32_t **)off_1138DC = **(uint32_t **)off_1138DC;
}

