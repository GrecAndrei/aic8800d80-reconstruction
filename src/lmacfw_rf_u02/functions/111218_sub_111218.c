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


extern uint32_t off_111264;
extern uint32_t off_111268;
extern uint32_t off_11126C;
extern uint32_t off_111270;

// timer_read_count @ 0x111218, size 74 bytes
int timer_read_count()
{
  uint32_t *v0; // r1
  int v1; // r0
  uint32_t *v2; // r3
  int result; // r0

  v0 = *(uint32_t **)off_111264;
  v1 = *(uint32_t *)off_111268;
  v2 = off_11126C;
  *((uint16_t *)off_111270 + 5) = 0;
  *v0 = 167772160;
  v0[1] = v1;
  v2[4] = v2[4] & 0xFFFFF81F | 0x20;
  do
    result = v2[4] & 0x20;
  while ( result );
  v2[578] = v2[578];
  v2[581] = v0;
  v2[576] |= 0x84000000;
  return result;
}
