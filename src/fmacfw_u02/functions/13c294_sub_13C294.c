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


extern uint32_t dword_13C39C;
extern uint32_t dword_13C3A0;

// get_tx_power_cal_entry @ 0x13c294, size 264 bytes
int  get_tx_power_cal_entry(int a1, int a2, int a3)
{
  int v4; // r3
  int v5; // r3
  int i; // r4
  int v8; // r4
  int v11; // r4
  int v12; // r0
  int v13; // r6
  int v14; // r2
  volatile unsigned int v15; // r3
  volatile unsigned int v16; // r3
  int v17; // r3
  int ( *v18)(int, int); // r2
  uint8_t v19; // r0
  volatile unsigned int v20; // r2

  v4 = 696 * *(uint8_t *)(a1 + 29);
  if ( (*(uint32_t *)(dword_13C39C + v4 + 4) & 2) == 0 )
    return 1;
  v5 = v4 + 12 * *(uint8_t *)(a1 + 27) + dword_13C39C;
  --*(uint8_t *)(v5 + 455);
  if ( (*(uint16_t *)(a1 + 30) & 2) == 0 )
    return 1;
  v8 = *(uint8_t *)(v5 + 453);
  if ( v8 == 33 || rx_rate_field_parse((v8 << 8) | 8) != 1 )
    return 1;
  v11 = dword_13C3A0 + 32 * v8;
  v12 = *(uint32_t *)(a1 + 36) << 10;
  v13 = *(uint32_t *)(v11 + 28);
  --*(uint32_t *)(v11 + 4);
  if ( v12 < 0 )
  {
    if ( a3 )
    {
      if ( !a2 )
      {
        v14 = *(uint16_t *)(a1 + 64);
        v15 = (*(volatile uint32_t *)0x40501010u);
        if ( ((v14 - (v15 >> 10)) & 0x8000) == 0 )
        {
          v16 = (*(volatile uint32_t *)0x40501010u);
          event_dispatch("move win since flush: succ=%d, timepast=%d\n", 0, ((v14 - (v16 >> 10)) >> 15) & 1);
        }
      }
    }
    else if ( !a2 )
    {
      v20 = (*(volatile uint32_t *)0x40501010u);
      if ( ((*(uint16_t *)(a1 + 64) - (v20 >> 10)) & 0x8000) == 0 )
      {
        i = 0;
        *(uint32_t *)(*(uint32_t *)(a1 + 76) + 4) |= 2u;
        return i;
      }
    }
  }
  *(uint8_t *)((*(int ( **)(int, int))v13)(v13, (*(uint16_t *)(a1 + 32) - *(uint16_t *)(v13 + 4)) & 0xFFF) + v13 + 6) = 2;
  v17 = *(uint8_t *)(v13 + 262) + v13;
  for ( i = 0; *(uint8_t *)(v17 + 6) == 2; i = (char)(i + 1) )
  {
    *(uint8_t *)(v17 + 6) = 0;
    v18 = *(int ( **)(int, int))v13;
    *(uint16_t *)(v13 + 4) = (*(uint16_t *)(v13 + 4) + 1) & 0xFFF;
    v19 = v18(v13, 1);
    v17 = v13 + v19;
    *(uint8_t *)(v13 + 262) = v19;
  }
  return i;
}
