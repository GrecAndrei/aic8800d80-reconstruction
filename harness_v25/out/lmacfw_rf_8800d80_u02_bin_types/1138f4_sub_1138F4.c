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

extern uint32_t off_11393C;
extern uint32_t off_113938;
extern uint32_t off_113940;
extern uint32_t off_113948;
extern uint32_t off_113944;

// sub_1138F4 @ 0x1138f4, size 68 bytes
int sub_1138F4()
{
  int v0; // r2
  int v1; // r1
  uint32_t *v2; // r3

  if ( *(uint32_t *)off_11393C )
    v0 = 2048;
  else
    v0 = 4096;
  if ( *(uint32_t *)off_11393C )
    v1 = 1;
  else
    v1 = 2;
  if ( *(uint8_t *)(*(uint32_t *)off_113938 + 6) == 1 )
    *((uint32_t *)off_113940 + 83) &= ~v1;
  v2 = off_113948;
  *(uint32_t *)(*(uint32_t *)off_113944 + 8) = 0;
  v2[34] = v0;
  __dsb(0xFu);
  __isb(0xFu);
  return 0;
}

