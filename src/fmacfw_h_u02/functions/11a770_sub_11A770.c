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


extern uint32_t off_11A7B4;

// tx_status_check @ 0x11a770, size 68 bytes
int  tx_status_check(int result, int a2)
{
  int v2; // r3
  int v3; // r2
  unsigned int v4; // r3

  v2 = *(uint32_t *)(result + 60);
  if ( v2 < 0 )
  {
    v3 = *(uint32_t *)(result + 36);
    if ( **(uint16_t **)off_11A7B4 >= 0 || (v2 & 0x10000) != 0 )
    {
      v4 = *(uint32_t *)(v3 + 20) & 0xFFFE3FFF | 0x4000;
      *(uint32_t *)(result + 60) = 0;
      *(uint32_t *)(v3 + 20) = v4;
      return rf_switch_case(result, a2);
    }
    else
    {
      return unknown_12f2c8((int)aAThdStatusRetr, (int)aTxlAggCheckRts, 3371);
    }
  }
  return result;
}
