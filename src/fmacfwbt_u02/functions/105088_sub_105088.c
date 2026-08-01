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

extern uint32_t dword_105138;
extern uint32_t dword_10513C;
extern uint32_t dword_105134;

// temp_sensor_convert @ 0x105088, size 168 bytes
int  temp_sensor_convert(float a1, int a2, int a3)
{
  float v5; // r0
  uint64_t v6; // r0
  uint64_t v7; // r0
  int16_t v8; // r0
  uint64_t v9; // kr00_8
  uint64_t v11; // kr08_8

  v5 = load_const_table(a1 / 20.0);
  v6 = __aeabi_f2d((float)a2 * v5);
  v7 = softfloat_float_op(v6, HIDWORD(v6));
  v8 = __aeabi_d2lz(v7, HIDWORD(v7));
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
        ke_event_schedule(dword_105138, (uint32_t *)(uintptr_t)(HIDWORD(v11)), v11);
    }
  }
  else
  {
    v9 = *(uint64_t *)(a3 + 112);
    *(uint8_t *)(a3 + 104) = -24;
    if ( SHIDWORD(v9) < (int)v9 )
      ke_event_schedule(dword_10513C, (uint32_t *)(uintptr_t)(HIDWORD(v9)), v9);
  }
  return state_check_feature(1, dword_105134);
}

