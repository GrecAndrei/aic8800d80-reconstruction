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

extern uint32_t off_1041CC;
extern uint32_t off_1041D0;
extern uint32_t off_1041D4;
extern uint32_t off_1041D8;
extern uint32_t off_1041DC;
extern uint32_t off_1041E0;

// mmio_config_clear_bits_n_0f0 @ 0x1040f0, size 220 bytes
// Doc: mmio_config_clear_bits_n_0f0 [mmio]: Clear bits in MMIO control registers
// mmio_config_clear_bits_n_0f0 [mmio]: Clear bits in MMIO control registers
unsigned int *mmio_config_clear_bits_n_0f0()
{
  unsigned int *v0; // r1
  uint32_t *v1; // r0
  unsigned int *v2; // r2
  uint32_t *v3; // r6
  uint32_t *v4; // r5
  uint32_t *v5; // r4
  unsigned int *result; // r0

  v0 = (unsigned int *)off_1041CC;
  v1 = off_1041D0;
  v2 = (unsigned int *)off_1041D4;
  *(uint32_t *)off_1041CC &= ~0x10000000u;
  v3 = off_1041D8;
  v4 = off_1041DC;
  v5 = off_1041E0;
  *v1 &= ~0x200u;
  *v0 = *v0 & 0xFC000FFF | 0x333000;
  *v3 = 0;
  *v4 &= ~0x1000000u;
  *v2 = *v2 & 0xFFFF0FFF | 0xA000;
  *v2 &= ~0x20000u;
  *v2 &= ~0x10000u;
  *v2 &= ~0x80000u;
  *v5 &= ~0x20000000u;
  result = v1 - 138;
  *v5 &= ~0x10000000u;
  v4 += 2046;
  *result &= 0xE7FFFFFF;
  *v4 &= ~0x2000000u;
  v2[8] = v2[8] & 0xFC00FFFF | 0x100000;
  v5[23] &= ~0x80u;
  v4[48] &= ~8u;
  *v0 = *v0 & 0xFFFFF000 | 0x80;
  *result = *result & 0xF8FFFFFF | 0x5000000;
  *(unsigned int *)((char *)v2 + 0xFFFFFFD8) &= ~0x1000000u;
  return result;
}

