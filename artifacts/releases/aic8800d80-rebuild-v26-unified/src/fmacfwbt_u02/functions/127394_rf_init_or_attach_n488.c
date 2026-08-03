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

extern uint32_t off_1274A8;
extern uint32_t off_1274A0;
extern uint32_t dword_1274A4;
extern uint32_t dword_1274BC;
extern uint32_t dword_1274C0;
extern uint32_t dword_1274AC;
extern uint32_t off_1274B0;
extern uint32_t dword_1274B8;
extern uint32_t dword_1274B4;

// rf_init_or_attach_n488 @ 0x127394, size 266 bytes
// Doc: rf_init_or_attach_n488 [rf]: Initialize/attach RF subsystem reading MMIO regs at 0x40501000 and table 0x190c30
// rf_init_or_attach_n488 [rf]: Initialize/attach RF subsystem reading MMIO regs at 0x40501000 and table 0x190c30
int  rf_init_or_attach_n488(int result)
{
  uint8_t *v1; // r5
  uint64_t v2; // r6
  int v3; // r4
  char v4; // r3
  int v5; // r4
  int v6; // r9
  int v7; // r10
  int v8; // r7
  int v9; // r3
  int v10; // r11
  int v11; // r1
  int v12; // r0

  v1 = off_1274A8;
  LODWORD(v2) = result;
  HIDWORD(v2) = *((uint32_t *)off_1274A0 + 4) + *(uint32_t *)(result + 20);
  if ( result != dword_1274A4 || (*((uint8_t *)off_1274A8 + 88) & 4) != 0 )
  {
    if ( *((uint32_t *)off_1274A8 + 10) != result )
    {
      result = sub_10186C();
      HIDWORD(v2) += 4000 + result;
    }
    v3 = (uint8_t)v1[91];
    v4 = v1[88];
    *((uint64_t *)v1 + 10) = v2;
    if ( v3 )
    {
      v1[88] = v4 | 0x40;
    }
    else
    {
      v1[88] = v4 & 0xBF;
      fmacfwbt_init_load();
      result = rf_chan_table_lookup_n938(SHIDWORD(v2), 0, 0);
      v5 = *((uint32_t *)v1 + 4);
      if ( v5 )
      {
        v6 = dword_1274BC;
        v7 = dword_1274C0;
        v8 = dword_1274AC - HIDWORD(v2);
        while ( 1 )
        {
          v10 = *(uint32_t *)(v5 + 4);
          result = v10 - sub_10186C();
          if ( result + v8 >= 0 )
            break;
          v11 = *(uint32_t *)(v5 + 4);
          v12 = v6 + 1320 * *(uint8_t *)(v5 + 8);
          v9 = 102400;
          if ( *(uint8_t *)(v12 + 106) )
          {
            if ( *(uint8_t *)(v12 + 106) == 2 )
              v9 = *(uint16_t *)(v12 + 222) << 10;
            result = bt_rf_calibrate_or_setup(v12, v11 + v9, 0);
            v5 = *((uint32_t *)v1 + 4);
            if ( !v5 )
              break;
          }
          else
          {
            result = bt_rf_calibrate_or_setup(v12, v11 + *(uint32_t *)(v7 + 696 * *(uint8_t *)(v12 + 116) + 8), 0);
            v5 = *((uint32_t *)v1 + 4);
            if ( !v5 )
              break;
          }
        }
      }
      if ( *((uint32_t *)v1 + 11) )
      {
        if ( **(int16_t **)off_1274B0 < 0 && (v1[88] & 0xC) == 0 )
          return sub_12F694(dword_1274B8, dword_1274B4, 1698);
      }
      else
      {
        return sub_1272F0(v2);
      }
    }
  }
  else
  {
    *((uint8_t *)off_1274A8 + 88) &= ~0x40u;
  }
  return result;
}

