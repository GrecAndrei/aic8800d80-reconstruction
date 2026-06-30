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

extern uint32_t dword_1052E0;
extern uint32_t dword_1052E4;
extern uint32_t dword_1052DC;

// rf_bus_write_n_3dc @ 0x105230, size 168 bytes
// Doc: rf_bus_write_n_3dc [rf]: Writes a value to an RF bus register slot via helper and bit-shift masking
// rf_bus_write_n_3dc [rf]: Writes a value to an RF bus register slot via helper and bit-shift masking
int  rf_bus_write_n_3dc(float a1, int a2, int a3)
{
  float v5; // r0
  int v6; // r0
  uint64_t v7; // r0
  int16_t v8; // r0
  uint64_t v9; // kr00_8
  uint64_t v11; // kr08_8

  v5 = math_fastpath(a1 / 20.0);
  v6 = sub_1429F8((float)a2 * v5);
  v7 = math_round(v6);
  v8 = sub_142FDC(v7, HIDWORD(v7));
  if ( v8 <= 232 )
  {
    if ( v8 > 31 )
    {
      *(uint8_t *)(a3 + 104) = v8;
    }
    else
    {
      v11 = *(uint64_t *)(a3 + 112);
      *(uint8_t *)(a3 + 104) = 32;
      if ( SHIDWORD(v11) < (int)v11 )
        msg_parse(dword_1052E0, HIDWORD(v11), v11);
    }
  }
  else
  {
    v9 = *(uint64_t *)(a3 + 112);
    *(uint8_t *)(a3 + 104) = -24;
    if ( SHIDWORD(v9) < (int)v9 )
      msg_parse(dword_1052E4, HIDWORD(v9), v9);
  }
  return feature_guard_check(1, dword_1052DC);
}

