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

extern uint32_t dword_12365C;
extern uint32_t off_123660;
extern uint32_t off_123664;

// sub_1235D0 @ 0x1235d0, size 140 bytes
int  sub_1235D0(int a1, uint8_t *a2)
{
  uint8_t *v3; // r0
  uint8_t *v4; // r4
  unsigned int v5; // r0
  int v6; // r0

  v3 = (uint8_t *)sub_12C92C(83, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 )
    goto LABEL_6;
  v6 = dword_12365C + 1320 * v5;
  if ( !*(uint8_t *)(v6 + 1224) )
    goto LABEL_6;
  if ( a2[2] )
  {
    if ( sub_12A5F4(
           v6,
           0,
           a2[3],
           a2[2],
           *((uint32_t *)a2 + 2),
           *((uint32_t *)a2 + 1),
           (*(uint16_t *)(v6 + 222) << 10)
         + *(uint32_t *)off_123660 / (*(uint16_t *)(v6 + 222) << 10) * (*(uint16_t *)(v6 + 222) << 10)
         + *((uint32_t *)off_123664 + 4)
         - *(uint32_t *)off_123660
         + *((uint32_t *)a2 + 3)) != 255 )
      *v4 = 0;
LABEL_6:
    sub_12C98C(v4);
    return 0;
  }
  *v4 = sub_12A700();
  sub_12C98C(v4);
  return 0;
}

