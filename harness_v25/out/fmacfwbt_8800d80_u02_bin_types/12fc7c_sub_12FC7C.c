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

extern uint32_t dword_12FD60;
extern uint32_t dword_12FD50;
extern uint32_t dword_12FD54;
extern uint32_t dword_12FD58;
extern uint32_t dword_12FD5C;

// sub_12FC7C @ 0x12fc7c, size 212 bytes
int  sub_12FC7C(int a1, int a2)
{
  unsigned int v4; // r5
  int v5; // r0
  int v7; // r3
  int v8; // r0
  int v9; // [sp+4h] [bp-4h]

  v4 = sub_12FB74(*(uint8_t **)(a2 + 4), 0, 0x10u);
  if ( a1 <= 2 )
  {
    v5 = sub_12FC48(*(uint32_t *)a2);
    if ( v5 >= 0 )
      goto LABEL_3;
LABEL_18:
    sub_10DA7C(dword_12FD60, v5);
    return -1;
  }
  v9 = sub_12FB74(*(uint8_t **)(a2 + 8), 0, 0);
  v5 = sub_12FC48(*(uint32_t *)a2);
  if ( v5 < 0 )
    goto LABEL_18;
  if ( v9 == 1 )
  {
LABEL_3:
    if ( ((v4 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      v8 = sub_10EBC4();
      sub_10DA7C(dword_12FD50, v4 & 0xFFFFFFFC, v8);
      return 0;
    }
    else if ( v5 == 4 )
    {
      sub_10DA7C(dword_12FD54, v4, *(uint32_t *)v4);
      return 0;
    }
    else if ( v5 == 2 )
    {
      sub_10DA7C(dword_12FD58, v4, *(uint16_t *)v4);
      return 0;
    }
    else
    {
      if ( v5 == 1 )
        sub_10DA7C(dword_12FD5C, v4, *(uint8_t *)v4);
      return 0;
    }
  }
  v7 = **(uint8_t **)a2 == 82 && v4 < 0x40000000;
  sub_12ED40(v4, v9, (uint8_t)v5, v7);
  return 0;
}

