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

extern uint32_t dword_12646C;
extern uint32_t dword_126470;

// sub_126440 @ 0x126440, size 44 bytes
int  sub_126440(uint32_t *a1)
{
  int v1; // r3
  int v2; // r2

  v1 = dword_12646C;
  while ( 1 )
  {
    if ( *(uint8_t *)(v1 + 24) != 255 )
    {
      v2 = *(uint8_t *)(v1 + 27);
      if ( v2 != 255 )
        break;
    }
    v1 += 28;
    if ( v1 == dword_12646C + 84 )
      return 0;
  }
  *a1 = dword_126470 + 1320 * v2;
  return 1;
}

