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

extern uint32_t dword_13BDF0;
extern uint32_t dword_13BDF4;
extern uint32_t dword_13BDF8;

// sub_13BD84 @ 0x13bd84, size 108 bytes
int  sub_13BD84(int result)
{
  int v1; // r4
  int v2; // r5
  int v3; // r10
  int v4; // r7
  int16_t v5; // r9
  int v6; // r6
  int v7; // t1

  v1 = dword_13BDF0;
  v2 = dword_13BDF4;
  v3 = dword_13BDF8;
  v4 = result;
  v5 = -128 * dword_13BDF0;
  v6 = dword_13BDF0 + 64;
  do
  {
    v7 = *(uint16_t *)(v1 + 2);
    v1 += 2;
    if ( v7 )
    {
      if ( *(uint8_t *)(v2 + 16) == v4 )
      {
        rf_bus_mark_n_3b7((uint16_t)(v5 + ((uint16_t)v1 << 7) - 256) | 8, 4);
        *(uint8_t *)(v2 + 25) = 0;
        result = rf_bus_write_n_25c(v4, v2, 2, 0, 0, 39, v3);
      }
    }
    v2 += 32;
  }
  while ( v1 != v6 );
  return result;
}

