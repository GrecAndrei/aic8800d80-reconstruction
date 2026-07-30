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

extern uint32_t dword_134A0C;
extern uint32_t off_134A10;
extern uint32_t dword_134A18;
extern uint32_t dword_134A14;

// sub_1349D8 @ 0x1349d8, size 52 bytes
int sub_1349D8()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r4

  v0 = sub_12D4F8(dword_134A0C);
  v1 = v0;
  if ( **(int16_t **)off_134A10 < 0 && !v0 )
    sub_12F694(dword_134A18, dword_134A14, 766);
  return sub_12CBB4((int)(v1 + 3));
}

