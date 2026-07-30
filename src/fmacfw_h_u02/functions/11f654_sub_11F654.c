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

extern uint32_t off_11F67C;

// sub_11F654 @ 0x11f654, size 38 bytes
int sub_11F654()
{
  uint32_t *i; // r5
  uint32_t *j; // r4
  int result; // r0

  for ( i = *((uint32_t **)off_11F67C + 2); i; i = (uint32_t *)*i )
  {
    for ( j = (uint32_t *)i[60]; j; j = (uint32_t *)*j )
      result = sub_11F28C((int)i, (int)j, 0);
  }
  return result;
}

