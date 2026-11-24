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


extern uint32_t dword_11199C;
extern uint32_t dword_1119A0;

// sub_11196C @ 0x11196c, size 48 bytes
int  sub_11196C(int a1)
{
  int v2; // r0
  int v3; // r5
  int result; // r0
  int ( *v5)(uint32_t, uint32_t, int); // r3

  v2 = dword_11199C + 16 * (a1 - 1);
  v3 = *(uint8_t *)(v2 + 8);
  result = (int)sub_100200((int *)v2, 0, 0x10u);
  if ( v3 )
  {
    result = dword_1119A0;
    v5 = *(int ( **)(uint32_t, uint32_t, int))(dword_1119A0 + 4 * a1 + 32);
    if ( v5 )
      return v5(0, 0, 1);
  }
  return result;
}
