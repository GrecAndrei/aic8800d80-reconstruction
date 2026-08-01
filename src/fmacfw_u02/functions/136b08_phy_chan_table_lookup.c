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

extern uint32_t dword_136B60;
extern uint32_t dword_136B64;

// bt_is_link_active @ 0x136b08, size 88 bytes
// Doc: bt_is_link_active [mac]: Look up PHY channel entry in indexed table (stride 0x528)
// bt_is_link_active [mac]: Look up PHY channel entry in indexed table (stride 0x528)
int  bt_is_link_active(int a1)
{
  unsigned int v1; // r3
  int v2; // r2
  int v3; // r3

  if ( *(uint8_t *)(dword_136B60 + 1320 * *(uint8_t *)(a1 + 28) + 106) != 2 )
    return 1;
  v1 = *(uint8_t *)(a1 + 29);
  if ( v1 > 0x23 || !*(uint16_t *)(a1 + 4) && *(uint16_t *)(*(uint32_t *)(a1 + 72) + 108) == 584 )
    return 1;
  v2 = dword_136B64 + 696 * v1;
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

