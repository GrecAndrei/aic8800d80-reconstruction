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

extern uint32_t off_10D048;
extern uint32_t off_10D04C;
extern uint32_t off_10D050;

// log_hw_regs_init @ 0x10d000, size 70 bytes
// Doc: log_hw_regs_init [util]: Initialize hardware logging registers
// log_hw_regs_init [util]: Initialize hardware logging registers
int log_hw_regs_init()
{
  uint32_t *v0; // r1
  uint32_t *v1; // r4
  uint32_t *v2; // r3

  v0 = off_10D048;
  v1 = off_10D04C;
  v2 = off_10D050;
  *(uint32_t *)off_10D04C = 13369344;
  *v0 = 13369344;
  *v2 &= 0xFFFFFFCF;
  *v2 &= 0xFFFFFF3F;
  *v2 &= 0xFFFFCFFF;
  *v2 &= 0xFFFF3FFF;
  *v1 = 0x8000000;
  *v0 = 0x8000000;
  *v2 &= 0xFF3FFFFF;
  return 0x8000000;
}

