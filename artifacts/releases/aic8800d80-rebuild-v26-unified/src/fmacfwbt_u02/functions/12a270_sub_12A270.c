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

extern uint32_t dword_12A2AC;
extern uint32_t off_12A2B0;

// sub_12A270 @ 0x12a270, size 60 bytes
int  sub_12A270(int result, int a2)
{
  int v2; // r2
  int v3; // r3

  v2 = dword_12A2AC;
  v3 = dword_12A2AC + 140 * result;
  if ( *(uint8_t *)(v3 + 113) != 255 )
  {
    if ( *(uint8_t *)(v3 + 112) != 1 )
    {
      if ( !a2 )
        return result;
      goto LABEL_4;
    }
    --*(uint8_t *)off_12A2B0;
    if ( a2 )
    {
LABEL_4:
      result = v2 + 140 * result;
      *(uint8_t *)(result + 113) = -1;
    }
  }
  return result;
}

