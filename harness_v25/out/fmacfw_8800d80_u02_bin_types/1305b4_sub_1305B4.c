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

extern uint32_t off_13060C;
extern uint32_t dword_130614;
extern uint32_t off_130610;

// sub_1305B4 @ 0x1305b4, size 88 bytes
int sub_1305B4()
{
  uint8_t *v0; // r4
  int result; // r0
  int v2; // r0
  int v3; // r2
  int v4; // r0

  v0 = off_13060C;
  *((uint8_t *)off_13060C + 1) = 1;
  result = sub_12C8B4(1070, 1);
  if ( !result )
  {
    sub_10DFF0();
    v0[6] = sub_10EF24();
    sub_1304B0();
    v2 = (uint8_t)v0[5];
    if ( (uint8_t)v0[6] != v2 )
    {
      sub_10EF38(v2);
      v3 = (uint8_t)v0[5];
      v4 = dword_130614;
      v0[6] = v3;
      sub_12EA88(v4, v3);
    }
    return sub_12C5E4(1070, 1, 1000 * *((uint32_t *)off_130610 + 91));
  }
  return result;
}

