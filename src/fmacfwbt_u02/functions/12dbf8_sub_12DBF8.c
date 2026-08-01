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

extern uint32_t dword_12DC20;

// debug_log @ 0x12dbf8, size 40 bytes
// Doc: sub_122DBF8 [unknown]: Setup call frame, prepare 5 args, call helper
// sub_122DBF8 [unknown]: Setup call frame, prepare 5 args, call helper
uint8_t * debug_log(uint8_t *a1, int a2, uint8_t *a3)
{
  uint8_t *result; // r0
  uint16_t v5; // [sp+Eh] [bp-2h] BYREF

  result = memcpy_opt(a1, a2, (uint8_t *)dword_12DC20, 5, &v5);
  if ( result )
  {
    if ( v5 <= 0x17u )
      return 0;
    else
      *a3 = v5 - 2;
  }
  return result;
}

