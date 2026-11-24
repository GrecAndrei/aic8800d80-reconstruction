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


extern uint32_t off_1293E0;
extern uint32_t off_1293EC;
extern uint32_t off_1293F0;
extern uint32_t off_1293F4;
extern uint32_t off_1293F8;
extern uint32_t off_1293FC;
extern uint32_t off_129400;

// chip_register_set_bit @ 0x129388, size 86 bytes
int chip_register_set_bit()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r1
  uint32_t *v2; // r5
  uint32_t *v3; // r2

  *(uint32_t *)off_1293E0 |= 0x2000000u;
  check_feature_flag(2, "%s\r\n", aPsUpmExit);
  if ( !*((uint8_t *)off_1293EC + 18) )
    *(uint32_t *)off_1293F0 &= ~1u;
  v0 = off_1293F8;
  v1 = off_1293F0;
  v2 = off_1293FC;
  v3 = off_129400;
  *(uint32_t *)off_1293F4 &= ~0x10000u;
  *v0 &= ~0x40000000u;
  *v1 &= ~0x10000000u;
  *v2 = 0;
  *v3 &= ~1u;
  return 0;
}
