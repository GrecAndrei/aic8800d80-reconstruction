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


extern uint32_t off_10F4A8;
extern uint32_t off_10F4AC;

// tx_power_temperature_comp @ 0x10f44c, size 90 bytes
int tx_power_temperature_comp()
{
  uint8_t *v0; // r6
  int v1; // r5
  int v2; // r4
  int result; // r0
  volatile unsigned int v4; // r3

  v0 = off_10F4AC;
  v1 = (char)(*((uint8_t *)off_10F4AC + 5) + (*(uint8_t *)off_10F4A8 & 3));
  v2 = *((char *)off_10F4AC + 7) - v1;
  if ( v2 < -62 )
    LOBYTE(v2) = -62;
  gpio_config(v2);
  v0[7] = v2;
  result = dispatch_event_handler_1("update# =%d %d\r\n", (char)v2, v1);
  if ( (char)v2 < -61 )
  {
    v0[11] = 0;
  }
  else
  {
    v4 = (*(volatile uint32_t *)0x40501010u);
    return ke_enter_critical((uint32_t *)v0 + 3, v4 + 30000 * *((uint16_t *)v0 + 4));
  }
  return result;
}
