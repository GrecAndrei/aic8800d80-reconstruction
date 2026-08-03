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

extern uint32_t dword_12AA6C;

// sub_12AA40 @ 0x12aa40, size 44 bytes
int  sub_12AA40(int a1)
{
  uint8_t *v1; // r3
  int result; // r0

  v1 = (uint8_t *)(dword_12AA6C + 140 * a1);
  if ( v1[113] == 255 )
    return 0;
  result = v1[132];
  if ( v1[132] )
    return (uint8_t)(13 * v1[136] + 11);
  return result;
}

