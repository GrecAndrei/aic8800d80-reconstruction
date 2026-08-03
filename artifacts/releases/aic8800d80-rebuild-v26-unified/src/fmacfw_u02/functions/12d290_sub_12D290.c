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

extern uint32_t off_12D2C4;
extern uint32_t dword_12D2CC;
extern uint32_t dword_12D2C8;

// sub_12D290 @ 0x12d290, size 52 bytes
int  sub_12D290(int result, uint32_t *a2)
{
  uint32_t *v2; // r5

  v2 = (uint32_t *)result;
  if ( **(int16_t **)off_12D2C4 < 0 && !a2 )
    result = sub_12F46C(dword_12D2CC, dword_12D2C8, 95);
  if ( *v2 )
  {
    *a2 = *v2;
  }
  else
  {
    v2[1] = a2;
    *a2 = 0;
  }
  *v2 = a2;
  return result;
}

