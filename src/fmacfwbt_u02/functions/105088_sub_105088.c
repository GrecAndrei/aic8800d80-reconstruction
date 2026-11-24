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


extern float flt_105130;

// sub_105088 @ 0x105088, size 168 bytes
int  sub_105088(float a1, int a2, int a3)
{
  float v6; // r0
  uint64_t v7; // r0
  uint64_t v8; // r0
  int v9; // r0
  uint64_t v10; // kr00_8
  uint64_t v12; // kr08_8

  v6 = COERCE_FLOAT(sub_12D748(COERCE_INT(a1 / 20.0)));
  v7 = sub_142A94(COERCE_UNSIGNED_INT((float)a2 * v6));
  v8 = sub_1426B8(v7);
  v9 = (uint16_t)sub_143078(v8);
  if ( (uint16_t)v9 <= 232 )
  {
    if ( (uint16_t)v9 > 31 )
    {
      *(uint8_t *)(a3 + 104) = v9;
    }
    else
    {
      v12 = *(uint64_t *)(a3 + 112);
      v9 = 32;
      *(uint8_t *)(a3 + 104) = 32;
      if ( SHIDWORD(v12) < (int)v12 )
      {
        sub_12ECB0("ana_cur_index=%x ana_max_index=%x warning:dig_pwr is smaller\n", HIDWORD(v12), (uint32_t)v12);
        v9 = *(uint8_t *)(a3 + 104);
      }
    }
  }
  else
  {
    v10 = *(uint64_t *)(a3 + 112);
    v9 = 232;
    *(uint8_t *)(a3 + 104) = -24;
    if ( SHIDWORD(v10) < (int)v10 )
    {
      sub_12ECB0("ana_cur_index=%x ana_max_index=%x warning:dig_pwr is bigger\n", HIDWORD(v10), (uint32_t)v10);
      v9 = *(uint8_t *)(a3 + 104);
    }
  }
  return sub_12EEF8(1, "pwr_diff*100=%4d base_pwr=%x dig_pwr=%x ", (int)(float)(a1 * flt_105130), a2, v9);
}
