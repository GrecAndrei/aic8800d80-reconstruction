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

extern uint32_t dword_136C8C;
extern uint32_t dword_136C90;

// phy_check_core_mode @ 0x136c34, size 88 bytes
// Doc: sub_1236C34 [util]: Lookup indexed table by 0x528-stride byte field, compare to 2
// sub_1236C34 [util]: Lookup indexed table by 0x528-stride byte field, compare to 2
int  phy_check_core_mode(int a1)
{
  unsigned int v1; // r3
  int v2; // r2
  int v3; // r3

  if ( *(uint8_t *)(dword_136C8C + 1320 * *(uint8_t *)(a1 + 28) + 106) != 2 )
    return 1;
  v1 = *(uint8_t *)(a1 + 29);
  if ( v1 > 0x23 || !*(uint16_t *)(a1 + 4) && *(uint16_t *)(*(uint32_t *)(a1 + 72) + 108) == 584 )
    return 1;
  v2 = dword_136C90 + 696 * v1;
  v3 = *(uint8_t *)(v2 + 36);
  if ( v3 != 1 )
    return 1;
  if ( (*(uint8_t *)(v2 + 54) & 3) == 0 )
  {
    v3 = 0;
    *(uint16_t *)(a1 + 30) |= 0x1000u;
  }
  return v3;
}

