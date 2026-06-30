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

extern uint32_t off_1326D4;
extern uint32_t dword_1326D8;
extern uint32_t dword_1326DC;

// sub_132654 @ 0x132654, size 128 bytes
int  sub_132654(uint8_t *a1, int a2)
{
  int v2; // r11
  int16_t **v3; // r8
  int v4; // r10
  int v5; // r9
  uint8_t *v8; // r4
  int v9; // r7
  int v10; // r0

  v2 = *a1;
  if ( *a1 )
  {
    v3 = (int16_t **)off_1326D4;
    v4 = dword_1326D8;
    v5 = dword_1326DC;
    v8 = a1;
    v9 = 0;
    while ( 1 )
    {
      if ( a2 && (v8[1] & 0x80u) == 0 )
        goto LABEL_6;
      sub_1325B4();
      if ( **v3 < 0 )
        break;
      if ( v10 <= 11 )
        goto LABEL_11;
LABEL_6:
      if ( ++v8 - a1 >= v2 )
        return v9;
    }
    if ( v10 > 11 )
    {
      sub_12F35C(v5, v4, 598);
      v2 = *a1;
      goto LABEL_6;
    }
LABEL_11:
    v9 = (uint16_t)(v9 | (1 << v10));
    goto LABEL_6;
  }
  return *a1;
}

