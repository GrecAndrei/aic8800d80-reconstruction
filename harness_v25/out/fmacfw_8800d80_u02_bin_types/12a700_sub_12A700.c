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

extern uint32_t dword_12A7DC;

// sub_12A700 @ 0x12a700, size 218 bytes
int  sub_12A700(int a1, unsigned int a2, int a3)
{
  int v3; // r6
  int v4; // r5
  int result; // r0
  int v7; // r3
  unsigned int v8; // r8
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3

  v3 = *(uint8_t *)(a1 + 1225);
  v4 = dword_12A7DC;
  result = *(uint8_t *)(dword_12A7DC + 140 * v3 + 112);
  if ( result != 1 )
    return 1;
  if ( a2 <= 1 )
  {
    v7 = 140 * v3 + 48 * a2 + dword_12A7DC;
    if ( *(uint8_t *)(v7 + 16) )
    {
      if ( !a3 || *(uint8_t *)(v7 + 32) )
      {
        sub_124E34(48 * a2 + 140 * v3 + dword_12A7DC);
        v8 = 140 * v3 + 48 * a2 + v4;
        *(uint8_t *)(v8 + 16) = 0;
        sub_129598(v4 + 140 * v3);
        sub_129804((uint8_t *)(v4 + 140 * v3));
        v9 = v4 + 140 * v3;
        v10 = *(uint8_t *)(v8 + 32);
        v11 = (uint8_t)(*(uint8_t *)(v9 + 121) - 1);
        *(uint8_t *)(v9 + 121) = v11;
        if ( v10 == 1 )
          --*(uint8_t *)(v9 + 122);
        v12 = v4 + 140 * v3;
        if ( *(uint8_t *)(v12 + 115) || v11 )
          sub_125CD8(*(uint8_t *)(v4 + 140 * v3 + 113), 3);
        else
          sub_125CD8(*(uint8_t *)(v12 + 113), 2);
        sub_129544(v4 + 140 * v3, a2);
        return 0;
      }
    }
  }
  return result;
}

