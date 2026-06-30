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

extern uint32_t off_123F74;

// sub_123F64 @ 0x123f64, size 16 bytes
// Doc: sub_1223F64 [mmio]: Set bit 6 in MMIO register (read-modify-write)
// sub_1223F64 [mmio]: Set bit 6 in MMIO register (read-modify-write)
int  sub_123F64(int result)
{
  *(uint32_t *)off_123F74 = *(uint32_t *)off_123F74 & 0xFFFFFFBF | (result << 6);
  return result;
}

