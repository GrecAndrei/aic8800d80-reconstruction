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

extern uint32_t dword_11A93C;

// sub_11A900 @ 0x11a900, size 58 bytes
int  sub_11A900(int result)
{
  int v1; // r5
  int v2; // r1
  char v3; // r3
  int v4; // r4

  v1 = dword_11A93C;
  v2 = *(uint32_t *)(dword_11A93C + 84 * result + 40);
  if ( v2 )
  {
    v3 = *(uint8_t *)(v2 + 14) - 1;
    v4 = result;
    *(uint8_t *)(v2 + 14) = v3;
    if ( !v3 )
      sub_12D248(*(uint32_t *)(v2 + 340));
    *(uint32_t *)(v1 + 84 * v4 + 40) = 0;
    return 84;
  }
  return result;
}

