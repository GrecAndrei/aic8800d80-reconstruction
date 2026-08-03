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

extern uint32_t dword_1225F0;

// sub_1225C4 @ 0x1225c4, size 44 bytes
int  sub_1225C4(int a1, int a2)
{
  float v3; // r0
  int v4; // r0

  if ( a1 <= 1 )
  {
    v3 = COERCE_FLOAT(sub_10DD20());
    v4 = msg_parse(dword_1225F0, (int)v3);
    rf_level_dump(v4);
  }
  else
  {
    sub_122508(a1, a2);
  }
  return 0;
}

