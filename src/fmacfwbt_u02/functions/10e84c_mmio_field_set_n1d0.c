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

extern uint32_t off_10E968;
extern uint32_t off_10E95C;
extern uint32_t dword_10E960;
extern uint32_t dword_10E96C;
extern uint32_t dword_10E964;

// gpio_set_alternate @ 0x10e84c, size 272 bytes
// Doc: gpio_set_alternate [mmio]: Set MMIO register field with masked bits
// gpio_set_alternate [mmio]: Set MMIO register field with masked bits
int  gpio_set_alternate(int a1)
{
  int16_t *v1; // r9
  int v2; // r7
  int v3; // r5
  int v4; // r3
  unsigned int *v5; // r8
  int v6; // r11
  int v7; // r6
  int v8; // r10
  int v9; // r2
  int v10; // r4
  int v11; // r3
  int v12; // r0
  int v13; // r3
  int v15; // r1
  int v16; // r2
  int v17; // [sp+0h] [bp-Ch]
  int v18; // [sp+4h] [bp-8h]

  v1 = (int16_t *)off_10E968;
  *(uint32_t *)off_10E95C = (a1 << 26) & 0x1C000000 | *(uint32_t *)off_10E95C & 0xE3FFFFFF;
  v2 = a1;
  v3 = radio_enable();
  ke_event_schedule(dword_10E960, v2, v3);
  v4 = *v1;
  if ( v4 > v3 )
  {
    v17 = 1;
  }
  else
  {
    if ( v4 >= v3 )
      return 0;
    v17 = -1;
  }
  v5 = (unsigned int *)off_10E95C;
  v6 = dword_10E96C;
  v18 = v2;
  v7 = 4;
  v8 = 0;
  while ( 1 )
  {
    v2 += v17;
    if ( v2 <= 7 )
    {
      if ( v2 < 0 )
      {
        v2 = 0;
        v9 = 0;
        v8 = -v18;
      }
      else
      {
        v9 = v2 << 26;
        v8 += v17;
      }
    }
    else
    {
      v9 = 469762048;
      v8 = 7 - v18;
      v2 = 7;
    }
    *v5 = *v5 & 0xE3FFFFFF | v9;
    v10 = radio_enable();
    ke_event_schedule(v6, v2, v10);
    v11 = *v1;
    v12 = v10 - v11;
    v13 = v3 - v11;
    if ( v13 * v12 <= 0 )
      break;
    --v7;
    v3 = v10;
    if ( !v7 )
      return v8;
  }
  v15 = v13;
  if ( v13 < 0 )
    v15 = -v13;
  if ( v12 < 0 )
    v12 = -v12;
  v16 = v10;
  if ( v15 <= v12 )
  {
    v8 -= v17;
    v16 = v3;
    *v5 = ((v2 - v17) << 26) & 0x1C000000 | *v5 & 0xE3FFFFFF;
  }
  ke_event_schedule(dword_10E964, v8, v16);
  return v8;
}

