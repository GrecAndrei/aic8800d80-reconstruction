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

extern uint32_t off_11C30C;

// enable_radio_clock @ 0x11c2f4, size 24 bytes
// Doc: sub_121C2F4 [util]: Sets a one-shot flag byte, calls helper, then clears the flag
// sub_121C2F4 [util]: Sets a one-shot flag byte, calls helper, then clears the flag
void  enable_radio_clock(int a1)
{
  uint8_t *v1; // r4

  v1 = off_11C30C;
  *(uint8_t *)off_11C30C = 1;
  rf_irq_status_check(a1);
  *v1 = 0;
  check_power_flag();
}

