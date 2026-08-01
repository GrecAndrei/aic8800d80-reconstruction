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

// ll_get_adv_state @ 0x131258, size 88 bytes
// Doc: sub_1231258 [util]: Helper: invoke callback and clear flag byte
// sub_1231258 [util]: Helper: invoke callback and clear flag byte
int  ll_get_adv_state(uint8_t *a1, int a2, int a3, uint8_t *a4)
{
  int result; // r0
  char v7; // r2
  int v8; // r2
  int v9; // r7
  int v10; // r5
  int v11; // r3

  result = (int)parse_frame_0x26(a1, a2);
  *a4 = 0;
  if ( result )
  {
    v7 = *(uint8_t *)(result + 3);
    if ( *(uint8_t *)(a3 + 17) == (v7 & 0xF) )
    {
      return 1;
    }
    else
    {
      *a4 = 1;
      *(uint8_t *)(a3 + 16) = v7;
      *(uint8_t *)(a3 + 17) = v7 & 0xF;
      v8 = *(uint16_t *)(result + 8);
      v9 = *(uint16_t *)(result + 11);
      v10 = *(uint16_t *)(result + 14);
      *(uint32_t *)(a3 + 4) = *(uint8_t *)(result + 4) | (*(uint16_t *)(result + 5) << 8);
      *(uint32_t *)a3 = *(uint8_t *)(result + 7) | (v8 << 8);
      *(uint32_t *)(a3 + 8) = *(uint8_t *)(result + 10) | (v9 << 8);
      v11 = *(uint8_t *)(result + 13) | (v10 << 8);
      result = 1;
      *(uint32_t *)(a3 + 12) = v11;
    }
  }
  return result;
}

