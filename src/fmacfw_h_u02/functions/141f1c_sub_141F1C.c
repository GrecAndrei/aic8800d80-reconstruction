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

extern uint32_t dword_141F5C;

// scan_slot_init @ 0x141f1c, size 64 bytes
int  scan_slot_init(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r3

  v3 = 0;
  v4 = dword_141F5C;
  do
  {
    if ( (*(uint16_t *)v4 & 1) != 0
      && *(uint8_t *)(v4 + 47) == a2
      && *(uint8_t *)(v4 + 46) == a1
      && *(uint8_t *)(v4 + 2) == a3 )
    {
      return dword_141F5C + 72 * v3;
    }
    ++v3;
    v4 += 72;
  }
  while ( v3 != 8 );
  return 0;
}

