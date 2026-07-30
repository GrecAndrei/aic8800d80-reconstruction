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

extern uint32_t off_1270AC;
extern uint32_t off_1270B0;

// sub_127080 @ 0x127080, size 44 bytes
int sub_127080()
{
  char v0; // r3
  int result; // r0

  if ( *((uint8_t *)off_1270AC + 89) )
  {
    v0 = *((uint8_t *)off_1270AC + 89) - 1;
    *((uint8_t *)off_1270AC + 89) = v0;
    if ( !v0 && *(uint8_t *)off_1270B0 == 1 )
    {
      *(uint8_t *)off_1270B0 = 0;
      sub_121AE4();
      return sub_127048();
    }
  }
  return result;
}

