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

extern uint32_t off_1365B8;
extern uint32_t off_1365BC;

// sub_136570 @ 0x136570, size 72 bytes
uint32_t * sub_136570(uint32_t *result)
{
  uint32_t *v1; // r4
  uint32_t *v2; // r6
  int v3; // r3
  int v4; // r1

  if ( *((uint8_t *)result + 108) )
  {
    v1 = result;
    if ( *((uint8_t *)result + 412) == 1 )
    {
      v2 = off_1365B8;
      if ( *((uint8_t *)off_1365B8 + 13) )
      {
        *((uint8_t *)off_1365B8 + 13) = 0;
        return sub_100B90();
      }
      else
      {
        sub_100B14();
        v3 = v2[4];
        v4 = *((uint32_t *)off_1365BC + 4);
        *((uint8_t *)v2 + 13) = 1;
        v2[7] = v1;
        return (uint32_t *)sub_124BFC((int)(v2 + 5), v4 + v3);
      }
    }
  }
  return result;
}

