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

extern uint32_t dword_125D30;
extern uint32_t off_125D34;

// sub_125CD0 @ 0x125cd0, size 94 bytes
int  sub_125CD0(int result)
{
  int v1; // r6
  int v2; // r4
  int v3; // r3
  int v4; // r5
  int v5; // r4
  int *v6; // r3
  int v7; // r1

  v1 = dword_125D30;
  v2 = *(uint8_t *)(result + 1225);
  v3 = dword_125D30 + 140 * v2;
  v4 = result;
  if ( !*(uint8_t *)(v3 + 32) && *(uint8_t *)(v3 + 16) )
    result = ((int (*)(void))sub_12A5C0)();
  v5 = v1 + 140 * v2;
  if ( !*(uint8_t *)(v5 + 80) && *(uint8_t *)(v5 + 64) )
    result = sub_12A5C0(v4, 1);
  v6 = *((int **)off_125D34 + 2);
  if ( v6 )
  {
    v7 = *(uint8_t *)(v4 + 107);
    result = 255;
    do
    {
      if ( *((uint8_t *)v6 + 86) == v7 )
        *((uint8_t *)v6 + 86) = -1;
      v6 = (int *)*v6;
    }
    while ( v6 );
  }
  return result;
}

