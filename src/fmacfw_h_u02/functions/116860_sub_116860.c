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


extern uint32_t dword_116958;
extern uint32_t dword_11696C;
extern uint32_t off_11695C;
extern uint32_t off_116960;
extern uint32_t off_116970;

// phy_set_cfg @ 0x116860, size 248 bytes
int  phy_set_cfg(int result, int a2, int a3)
{
  int v4; // r6
  int *v6; // r5
  int v7; // r2
  void *v8; // r8
  int v9; // r3
  int v10; // r2
  int v11; // r2

  v4 = result;
  if ( a3 == 5 )
    v6 = (int *)dword_11696C;
  else
    v6 = (int *)(dword_116958 + 84 * a3);
  v7 = *v6;
  if ( **(uint16_t **)off_11695C < 0 && v7 == result )
    return unknown_12f2c8((int)aPrevHdFirstThd, (int)aTxlFrameExchan, 1972);
  if ( v7 )
  {
    v8 = off_116970;
    v9 = *(uint8_t *)(*(uint32_t *)off_116970 + 1);
    if ( *(uint8_t *)(*(uint32_t *)off_116970 + 1) || !v6[2] )
      *(uint32_t *)(v7 + 4) = result;
    else
      *(uint32_t *)(v6[1] + 4) = result;
    if ( a3 == 5
      || !*((uint8_t *)off_116960 + 28 * a3 + 46)
      && ((v10 = *((uint32_t *)off_116960 + 52), result = v10 << 31, (v10 & 1) == 0)
       || *((uint8_t *)off_116960 + 190) != a3) )
    {
      result = adv_type_valid(a3);
      v9 = *(uint8_t *)(*(uint32_t *)v8 + 1);
    }
  }
  else if ( a3 != 5
         && (*((uint8_t *)off_116960 + 28 * a3 + 46)
          || (result = *((uint8_t *)off_116960 + 190), (*((uint32_t *)off_116960 + 52) & 1) != 0) && a3 == result) )
  {
    v11 = *(uint32_t *)off_116970;
    *((uint32_t *)off_116960 + 7 * a3 + 9) = v4;
    v9 = *(uint8_t *)(v11 + 1);
  }
  else
  {
    result = rf_switch_case(v4, a3);
    v9 = *(uint8_t *)(*(uint32_t *)off_116970 + 1);
  }
  if ( !v9 )
  {
    if ( (*(uint32_t *)(a2 + 56) & 0x200000) != 0 )
    {
      v6[1] = v4;
      v6[2] = 1;
    }
    else
    {
      v6[1] = 0;
      v6[2] = 0;
    }
  }
  *(uint32_t *)(dword_116958 + 84 * a3) = a2;
  return result;
}
