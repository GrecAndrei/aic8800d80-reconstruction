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

// patch_apply_n34e @ 0x1146c8, size 14 bytes
// Doc: rf_fault_dump_n7a [rf]: Clears fault bit and prepares RF fault dump buffer
// rf_fault_dump_n7a [rf]: Clears fault bit and prepares RF fault dump buffer
void patch_apply_n34e()
{
  *(uint32_t *)(*(uint32_t *)msg_dispatch + 8) &= ~2u;
}

