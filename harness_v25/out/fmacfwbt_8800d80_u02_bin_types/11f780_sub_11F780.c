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

// sub_11F780 @ 0x11f780, size 172 bytes
int  sub_11F780(int a1, int a2, int a3)
{
  int v3; // r5
  int v7; // r10
  int v8; // r11
  int v9; // r3
  int v10; // r8
  int v11; // r0
  int v12; // r2
  int v13; // r3
  int v15; // [sp+4h] [bp-8h]

  v3 = 0;
  v7 = a2 + 624;
  v8 = a2 + 584;
  v15 = 0;
  while ( sub_11733C(a1) )
  {
    v9 = 0;
    while ( 1 )
    {
      v10 = (uint8_t)v9;
      if ( *(uint32_t *)(v7 + 8 * v9) )
      {
        v11 = sub_12D4F8(a2 + 8 * (v9 + 78));
        goto LABEL_9;
      }
      if ( *(uint32_t *)(v8 + 8 * v9) )
        break;
      if ( ++v9 == 4 )
        return v3;
    }
    v11 = sub_12D4F8(a2 + 8 * (v9 + 73));
LABEL_9:
    if ( !v11 )
      break;
    v12 = a2;
    while ( !*(uint32_t *)(v12 + 624) )
    {
      v13 = *(uint32_t *)(v12 + 584);
      v12 += 8;
      if ( v13 )
        break;
      if ( a2 + 32 == v12 )
      {
        if ( !v15 )
          goto LABEL_15;
        break;
      }
    }
    v12 = *(uint32_t *)(v11 + 72);
    *(uint16_t *)(v12 + 108) |= 0x2000u;
    v15 = 1;
LABEL_15:
    sub_13AC44(v11, v10, v12);
    ++v3;
    sub_11AC28(v10);
    if ( a3 )
    {
      if ( v3 == a3 )
        break;
    }
  }
  return v3;
}

