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

extern uint32_t dword_1293E8;
extern uint32_t off_1293E0;
extern uint32_t off_1293EC;
extern uint32_t off_1293F0;
extern uint32_t off_1293F8;
extern uint32_t off_1293FC;
extern uint32_t off_129400;
extern uint32_t off_1293F4;

// chip_register_set_bit @ 0x129388, size 86 bytes
int chip_register_set_bit()
{
  int v0; // r1
  uint32_t *v1; // r0
  uint32_t *v2; // r1
  uint32_t *v3; // r5
  uint32_t *v4; // r2

  v0 = dword_1293E8;
  *(uint32_t *)off_1293E0 |= 0x2000000u;
  check_feature_flag(2, v0);
  if ( !*((uint8_t *)off_1293EC + 18) )
    *(uint32_t *)off_1293F0 &= ~1u;
  v1 = off_1293F8;
  v2 = off_1293F0;
  v3 = off_1293FC;
  v4 = off_129400;
  *(uint32_t *)off_1293F4 &= ~0x10000u;
  *v1 &= ~0x40000000u;
  *v2 &= ~0x10000000u;
  *v3 = 0;
  *v4 &= ~1u;
  return 0;
}

