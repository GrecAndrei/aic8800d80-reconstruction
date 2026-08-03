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

extern uint32_t off_104228;

// sub_1041E4 @ 0x1041e4, size 66 bytes
int  sub_1041E4(int a1, int a2, uint32_t *a3)
{
  int v3; // r3
  int v4; // r4
  int result; // r0

  v3 = (uint16_t)*(uint32_t *)off_104228;
  v4 = 0x3FFF;
  if ( v3 == 0x3FFF )
    a3 = (uint32_t *)*a3;
  else
    v4 = v3 + 1;
  if ( v3 != 0x3FFF )
    a3 = (uint32_t *)a3[v4];
  if ( ((uint8_t)a3 & 1) != 0 )
  {
    if ( a2 )
      goto LABEL_8;
  }
  else if ( a2 != 1 )
  {
LABEL_8:
    result = v3 + 2 + 2 * a1;
    goto LABEL_9;
  }
  result = v3 + 1 + 2 * a1;
LABEL_9:
  if ( result >= 0x4000 )
    result -= 0x4000;
  return result;
}

