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

extern uint32_t off_11830C;

// sub_1182F4 @ 0x1182f4, size 22 bytes
int sub_1182F4()
{
  uint32_t *i; // r4
  int result; // r0

  for ( i = *((uint32_t **)off_11830C + 2); i; i = (uint32_t *)*i )
    result = sub_1182C8((int)i);
  return result;
}

