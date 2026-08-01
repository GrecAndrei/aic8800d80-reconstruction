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

extern uint32_t dword_12974C;
extern uint32_t off_129744;
extern uint32_t off_129750;
extern uint32_t off_129754;
extern uint32_t off_12975C;
extern uint32_t off_129760;
extern uint32_t off_129764;
extern uint32_t off_129758;

// set_reg_bit @ 0x1296ec, size 86 bytes
int set_reg_bit()
{
  int v0; // r1
  uint32_t *v1; // r0
  uint32_t *v2; // r1
  uint32_t *v3; // r5
  uint32_t *v4; // r2

  v0 = dword_12974C;
  *(uint32_t *)off_129744 |= 0x2000000u;
  state_check_feature(2, v0);
  if ( !*((uint8_t *)off_129750 + 18) )
    *(uint32_t *)off_129754 &= ~1u;
  v1 = off_12975C;
  v2 = off_129754;
  v3 = off_129760;
  v4 = off_129764;
  *(uint32_t *)off_129758 &= ~0x10000u;
  *v1 &= ~0x40000000u;
  *v2 &= ~0x10000000u;
  *v3 = 0;
  *v4 &= ~1u;
  return 0;
}

