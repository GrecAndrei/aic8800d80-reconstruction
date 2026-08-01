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

// is_two_char_string @ 0x12f8ec, size 50 bytes
int  is_two_char_string(int a1)
{
  int v2; // r0
  int v3; // r0
  int v5; // r3

  v2 = memcpy_aligned(a1);
  if ( v2 <= 2 )
    return 4;
  v3 = v2 + a1;
  if ( *(uint8_t *)(v3 - 2) != 46 )
    return 4;
  v5 = *(uint8_t *)(v3 - 1);
  if ( v5 == 98 )
    return 1;
  if ( v5 == 104 )
    return 2;
  return -1;
}

