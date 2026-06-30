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

extern uint32_t dword_12348C;

// sub_12343C @ 0x12343c, size 80 bytes
int  sub_12343C(int a1, uint8_t *a2)
{
  uint8_t *v3; // r0
  uint8_t *v4; // r4
  unsigned int v5; // r0

  v3 = (uint8_t *)sub_12C7EC(84, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 || !*(uint8_t *)(dword_12348C + 1320 * v5 + 1224) )
    goto LABEL_5;
  *v4 = 0;
  if ( a2[1] )
  {
    sub_12A3E8();
LABEL_5:
    sub_12C84C(v4);
    return 0;
  }
  sub_12A424();
  sub_12C84C(v4);
  return 0;
}

