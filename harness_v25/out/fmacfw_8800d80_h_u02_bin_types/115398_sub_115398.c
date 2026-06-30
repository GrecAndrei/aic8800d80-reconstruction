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

extern uint32_t off_11544C;
extern uint32_t off_115450;
extern uint32_t dword_11545C;
extern uint32_t off_115460;
extern uint32_t off_115464;
extern uint32_t dword_11546C;
extern uint32_t off_115468;
extern uint32_t dword_115454;
extern uint32_t off_115458;

// sub_115398 @ 0x115398, size 180 bytes
int sub_115398()
{
  uint8_t *v0; // r4
  int result; // r0
  uint32_t *v2; // r3
  int v3; // r3

  v0 = off_11544C;
  if ( !*(uint8_t *)off_11544C && *(uint8_t *)off_115450 )
  {
    result = sub_12EB90(2, dword_11545C);
    v2 = off_115460;
    *v0 = 1;
    if ( (uint16_t)*v2 )
    {
      switch ( *(uint8_t *)off_115464 )
      {
        case 1:
          v3 = 700 * (uint16_t)*(uint32_t *)off_115460;
          break;
        case 2:
          v3 = 500 * (uint16_t)*(uint32_t *)off_115460;
          break;
        case 3:
          v3 = 300 * (uint16_t)*(uint32_t *)off_115460;
          break;
        case 4:
          v3 = 200 * (uint16_t)*(uint32_t *)off_115460;
          break;
        case 5:
          v3 = 100 * (uint16_t)*(uint32_t *)off_115460;
          break;
        default:
          v3 = 100 * (uint16_t)*(uint32_t *)off_115460;
          break;
      }
      return sub_124BFC(dword_11546C, *((uint32_t *)off_115468 + 4) + v3);
    }
  }
  else
  {
    result = sub_12EB90(2, dword_115454);
    if ( *((uint8_t *)off_115458 + 18) )
      *v0 = 0;
  }
  return result;
}

