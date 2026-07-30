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

extern uint32_t off_12838C;

// sub_128350 @ 0x128350, size 58 bytes
BOOL  sub_128350(int a1)
{
  int v1; // r3
  int v2; // r2

  v1 = *((uint32_t *)off_12838C + 10);
  if ( v1
    && (v2 = *(uint32_t *)(a1 + 72), *(uint16_t *)(v1 + 4) == *(uint16_t *)(v2 + 4))
    && *(uint8_t *)(v1 + 13) == *(uint8_t *)(v2 + 13)
    && *(uint16_t *)(v1 + 6) == *(uint16_t *)(v2 + 6)
    && *(uint16_t *)(v1 + 8) == *(uint16_t *)(v2 + 8) )
  {
    return *(uint16_t *)(v1 + 10) == *(uint16_t *)(v2 + 10);
  }
  else
  {
    return 0;
  }
}

