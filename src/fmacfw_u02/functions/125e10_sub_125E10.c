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

extern uint32_t dword_125E70;
extern uint32_t off_125E74;

// lld_evt_update @ 0x125e10, size 94 bytes
// Doc: sub_1225E10 [mac]: Access per-station MAC state indexed by 0x4c9 slot
// sub_1225E10 [mac]: Access per-station MAC state indexed by 0x4c9 slot
int  lld_evt_update(int result)
{
  int v1; // r6
  int v2; // r4
  int v3; // r3
  int v4; // r5
  int v5; // r4
  int *v6; // r3
  int v7; // r1

  v1 = dword_125E70;
  v2 = *(uint8_t *)(result + 1225);
  v3 = dword_125E70 + 140 * v2;
  v4 = result;
  if ( !*(uint8_t *)(v3 + 32) && *(uint8_t *)(v3 + 16) )
    result = ((int (*)(void))rf_calib_required)();
  v5 = v1 + 140 * v2;
  if ( !*(uint8_t *)(v5 + 80) && *(uint8_t *)(v5 + 64) )
    result = rf_calib_required(v4, 1);
  v6 = *((int **)off_125E74 + 2);
  if ( v6 )
  {
    v7 = *(uint8_t *)(v4 + 107);
    result = 255;
    do
    {
      if ( *((uint8_t *)v6 + 86) == v7 )
        *((uint8_t *)v6 + 86) = -1;
      v6 = (int *)*v6;
    }
    while ( v6 );
  }
  return result;
}

