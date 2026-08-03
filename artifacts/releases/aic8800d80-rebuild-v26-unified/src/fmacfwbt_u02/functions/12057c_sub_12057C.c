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

extern uint32_t off_1205A4;

// sub_12057C @ 0x12057c, size 40 bytes
int  sub_12057C(int result)
{
  int v1; // r4

  if ( *(uint8_t *)off_1205A4 && (*((uint32_t *)off_1205A4 + 1) & 8) == 0 )
  {
    v1 = result;
    if ( !*(uint32_t *)(result + 4) )
    {
      timestamp_remove_058(result + 48);
      return sub_11F82C(v1);
    }
  }
  return result;
}

