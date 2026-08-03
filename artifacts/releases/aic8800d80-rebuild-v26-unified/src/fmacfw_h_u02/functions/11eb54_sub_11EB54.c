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

// sub_11EB54 @ 0x11eb54, size 36 bytes
int  sub_11EB54(int a1)
{
  int v2; // r0
  int v3; // r1
  int v4; // r4

  v2 = sub_12C7EC(139, 13, 0, 24);
  v3 = a1;
  v4 = v2;
  sub_143630(v2, v3, 24);
  return sub_12C84C(v4);
}

