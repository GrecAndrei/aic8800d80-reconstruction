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

extern uint32_t off_1321D4;
extern uint32_t off_1321D8;
extern uint32_t dword_1321E0;
extern uint32_t dword_1321DC;

// sub_132178 @ 0x132178, size 92 bytes
int  sub_132178(uint8_t *a1)
{
  int v1; // r3
  int result; // r0
  int v4; // r1
  char *v5; // r3
  char *v6; // r1

  v1 = *a1;
  result = *((uint16_t *)a1 + 1);
  if ( v1 )
  {
    v4 = *((uint8_t *)off_1321D4 + 371);
    v5 = (char *)off_1321D4 + 202;
  }
  else
  {
    v4 = *((uint8_t *)off_1321D4 + 370);
    v5 = (char *)off_1321D4 + 118;
  }
  if ( v4 )
  {
    v6 = &v5[6 * v4];
    while ( *(uint16_t *)v5 != result )
    {
      v5 += 6;
      if ( v5 == v6 )
        goto LABEL_9;
    }
    a1[8] = v5[4];
    a1[9] = v5[3];
  }
  else
  {
LABEL_9:
    if ( **(int16_t **)off_1321D8 < 0 )
      result = sub_12F35C(dword_1321E0, dword_1321DC, 141);
    *((uint16_t *)a1 + 4) = 15;
  }
  return result;
}

