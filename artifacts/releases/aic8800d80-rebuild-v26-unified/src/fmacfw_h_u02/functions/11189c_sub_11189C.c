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

// sub_11189C @ 0x11189c, size 30 bytes
int *sub_11189C()
{
  int i; // r4
  int v1; // r0
  int *result; // r0
  int v3; // [sp+4h] [bp-4h]

  for ( i = 1; i != 6; ++i )
  {
    v1 = (uint8_t)i;
    v3 = (uint8_t)i;
    sub_11182C(v1);
    result = sub_111864(v3);
  }
  return result;
}

