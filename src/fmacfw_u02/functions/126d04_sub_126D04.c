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

extern uint32_t off_126E04;
extern uint32_t off_126E00;
extern uint32_t off_126E08;
extern uint32_t off_126E0C;
extern uint32_t dword_126E10;
extern uint32_t off_126E14;
extern uint32_t dword_126E18;

// rf_mmio_read @ 0x126d04, size 250 bytes
int  rf_mmio_read(int a1)
{
  uint32_t *v1; // r6
  int *v2; // r4
  int v3; // r7
  int v4; // r5
  uint32_t *v5; // r2
  uint8_t *v6; // r1
  int v7; // r8
  int v8; // r7
  uint8_t *v9; // r10
  int v10; // r9
  int v11; // r0
  char v12; // r11
  int v13; // r4
  int v14; // r5
  int v15; // r4

  v1 = off_126E04;
  v2 = *((int **)off_126E00 + 2);
  v3 = *((uint8_t *)off_126E04 + 89);
  nullsub_8(a1);
  v4 = v1[10];
  if ( !v4 )
    return 0;
  v5 = off_126E08;
  v6 = off_126E0C;
  *(uint32_t *)off_126E08 |= 4u;
  v7 = v3;
  if ( v6[2] )
    v5[250] |= 0x80000000;
  if ( v2 )
  {
    v8 = dword_126E10;
    v9 = off_126E14;
    v10 = dword_126E18;
    do
    {
      while ( 1 )
      {
        if ( v4 == v2[18] && !*((uint8_t *)v2 + 106) )
        {
          if ( *((uint8_t *)v2 + 108) )
          {
            v11 = *((uint8_t *)v2 + 116);
            if ( v11 != 255 && (!*((uint8_t *)v2 + 1224) || *(uint8_t *)(v10 + 140 * *((uint8_t *)v2 + 1225) + 133)) )
              break;
          }
        }
        v2 = (int *)*v2;
        if ( !v2 )
          goto LABEL_16;
      }
      v12 = *(uint8_t *)(v4 + 16);
      *(uint8_t *)(v4 + 16) = 6;
      if ( !phy_channel_is_5g(v11, v8, 0) )
      {
        ++v7;
        *v9 = 1;
      }
      *(uint8_t *)(v4 + 16) = v12;
      v2 = (int *)*v2;
    }
    while ( v2 );
LABEL_16:
    LOBYTE(v3) = v7;
  }
  v13 = *((uint8_t *)v1 + 89);
  v14 = v1[11];
  *((uint8_t *)v1 + 89) = v3;
  v15 = v7 - v13;
  if ( !v14 )
  {
    set_clock_divisor();
    if ( v7 )
    {
      v15 = 0;
      --*((uint8_t *)v1 + 89);
      return v15;
    }
    return 0;
  }
  if ( !v15 )
    return v15;
  *(uint8_t *)(v14 + 16) = 3;
  set_clock_divisor();
  return v15;
}

