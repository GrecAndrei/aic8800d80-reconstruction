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

extern uint32_t off_114738;
extern uint32_t off_114734;
extern uint32_t off_11473C;
extern uint32_t off_114744;
extern uint32_t off_114740;

// sub_1146F0 @ 0x1146f0, size 68 bytes
int sub_1146F0()
{
  int v0; // r2
  int v1; // r1
  uint32_t *v2; // r3

  if ( *(uint32_t *)off_114738 )
    v0 = 2048;
  else
    v0 = 4096;
  if ( *(uint32_t *)off_114738 )
    v1 = 1;
  else
    v1 = 2;
  if ( *(uint8_t *)(*(uint32_t *)off_114734 + 6) == 1 )
    *((uint32_t *)off_11473C + 83) &= ~v1;
  v2 = off_114744;
  *(uint32_t *)(*(uint32_t *)off_114740 + 8) = 0;
  v2[34] = v0;
  __dsb(0xFu);
  __isb(0xFu);
  return 0;
}

