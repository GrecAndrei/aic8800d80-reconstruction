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

// sub_113B5C @ 0x113b5c, size 26 bytes
unsigned int  sub_113B5C(int a1)
{
  host_reg_wait_set(1u, (a1 << 13) & 0x1E000);
  return ((unsigned int)sub_113A44(1u) >> 13) & 0xF;
}

