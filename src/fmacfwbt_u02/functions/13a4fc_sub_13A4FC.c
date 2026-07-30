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

extern uint32_t off_13A53C;
extern uint32_t dword_13A548;
extern uint32_t dword_13A544;
extern uint32_t dword_13A540;

// sub_13A4FC @ 0x13a4fc, size 64 bytes
int  sub_13A4FC(int a1, int a2)
{
  int v2; // r4
  uint32_t *v3; // r5
  int result; // r0

  v2 = a1 + 4 * a2;
  v3 = *(uint32_t **)(v2 + 408);
  if ( **(int16_t **)off_13A53C < 0 && !v3 )
    sub_12F694(dword_13A548, dword_13A544, 3320);
  sub_125058((int)(v3 + 68));
  result = sub_12D470(dword_13A540, v3);
  *(uint32_t *)(v2 + 408) = 0;
  return result;
}

