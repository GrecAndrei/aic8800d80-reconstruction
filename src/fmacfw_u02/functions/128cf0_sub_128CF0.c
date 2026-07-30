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

extern uint32_t dword_128D54;
extern uint32_t dword_128D58;
extern uint32_t off_128D5C;
extern uint32_t off_128D60;

// sub_128CF0 @ 0x128cf0, size 96 bytes
uint16_t * sub_128CF0(int a1, int a2)
{
  uint16_t *result; // r0
  int *i; // r3
  int v6; // r3

  feature_guard_check(2, dword_128D54);
  result = (uint16_t *)sub_128B2C(a1, a2, dword_128D58);
  if ( result )
  {
    result = (uint16_t *)off_128D5C;
    if ( !*((uint8_t *)off_128D5C + 8)
      || (v6 = (uint8_t)(*((uint8_t *)off_128D5C + 8) - 1), *((uint8_t *)off_128D5C + 8) = v6, !v6) )
    {
      for ( i = *((int **)off_128D60 + 2); i; i = (int *)*i )
      {
        if ( !*((uint8_t *)i + 106) )
        {
          if ( *((uint8_t *)i + 108) )
            i[1] &= 0xFFFFFFF1;
        }
      }
      *(uint8_t *)result = 0;
      return (uint16_t *)sub_12CA10(50, result[1], 0);
    }
  }
  return result;
}

