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

extern uint32_t off_123730;
extern uint32_t off_123734;
extern uint32_t off_123738;

// sub_1236FC @ 0x1236fc, size 52 bytes
uint8_t * sub_1236FC(uint8_t *result)
{
  uint8_t *v1; // r3
  char v2; // r1
  char v3; // r2

  if ( *result == 2 )
  {
    if ( *(uint8_t *)off_123730 == (uint8_t)result[1] )
    {
      v1 = off_123734;
      v2 = result[3];
      v3 = result[4];
      *((uint8_t *)off_123734 + 2) = result[2];
      v1[3] = v2;
      v1[4] = v3;
    }
    return (uint8_t *)sub_1264DC(*(uint32_t *)off_123738 + 20000);
  }
  return result;
}

