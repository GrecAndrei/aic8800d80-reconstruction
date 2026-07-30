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

extern uint32_t dword_12D9F8;

// sub_12D9D0 @ 0x12d9d0, size 40 bytes
uint8_t * sub_12D9D0(uint8_t *a1, int a2, uint8_t *a3)
{
  uint8_t *result; // r0
  uint16_t v5; // [sp+Eh] [bp-2h] BYREF

  result = sub_12D788(a1, a2, (uint8_t *)dword_12D9F8, 5, &v5);
  if ( result )
  {
    if ( v5 <= 0x17u )
      return 0;
    else
      *a3 = v5 - 2;
  }
  return result;
}

