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

extern uint32_t off_138DA4;
extern uint32_t dword_138DA8;
extern uint32_t dword_138DAC;
extern uint32_t dword_138DB4;
extern uint32_t dword_138DB0;

// rf_cal_is_valid @ 0x138cf8, size 170 bytes
// Doc: rf_cal_is_valid [scan]: evaluate channel/scan state from 0x18eed8[0x10]
// rf_cal_is_valid [scan]: evaluate channel/scan state from 0x18eed8[0x10]
int  rf_cal_is_valid(uint16_t *a1)
{
  int v2; // r7
  int v3; // r5
  int i; // r4
  int v6; // r10
  uint32_t *v7; // r4

  if ( *((uint8_t *)off_138DA4 + 16) == 255 || (*a1 & 0xEC) != 0xC4 )
  {
    v2 = dword_138DA8;
    v3 = 0;
    for ( i = dword_138DA8; ; i += 1320 )
    {
      if ( *(uint8_t *)(i + 108) )
      {
        if ( *(uint8_t *)(i + 106) == 2 )
        {
          v6 = 1320 * v3;
          if ( !memcpy(a1 + 2, i + 100, 6) )
            break;
        }
      }
      if ( ++v3 == 4 )
        return 0;
    }
    v7 = *(uint32_t **)(v2 + v6 + 240);
    if ( v7 )
    {
      while ( memcpy(a1 + 5, (char *)v7 + 38, 6) )
      {
        v7 = (uint32_t *)*v7;
        if ( !v7 )
          goto LABEL_14;
      }
      ke_event_schedule(dword_138DAC, (uint16_t)a1[5], (uint16_t)a1[6], (uint16_t)a1[7]);
    }
    else
    {
LABEL_14:
      ke_event_schedule(dword_138DB4, dword_138DB0, (uint16_t)a1[5], (uint16_t)a1[6], (uint16_t)a1[7]);
      txpwr_event_handler(v2 + v6, (int)(a1 + 5));
    }
  }
  return 0;
}

