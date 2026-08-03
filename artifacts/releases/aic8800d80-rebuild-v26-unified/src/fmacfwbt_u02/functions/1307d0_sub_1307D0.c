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

extern uint32_t off_130828;
extern uint32_t dword_130830;
extern uint32_t off_13082C;

// sub_1307D0 @ 0x1307d0, size 88 bytes
int sub_1307D0()
{
  uint8_t *v0; // r4
  int result; // r0
  int v2; // r0
  int v3; // r2
  int v4; // r0

  v0 = off_130828;
  *((uint8_t *)off_130828 + 1) = 1;
  result = message_dispatch_n_d8(1070, 1);
  if ( !result )
  {
    rf_hw_timer_init();
    v0[6] = mmio_read_bitfield_7000101c();
    sub_1306CC();
    v2 = (uint8_t)v0[5];
    if ( (uint8_t)v0[6] != v2 )
    {
      sub_10ED90(v2);
      v3 = (uint8_t)v0[5];
      v4 = dword_130830;
      v0[6] = v3;
      sub_12ECB0(v4, v3);
    }
    return rf_level_apply_80c(1070, 1, 1000 * *((uint32_t *)off_13082C + 91));
  }
  return result;
}

