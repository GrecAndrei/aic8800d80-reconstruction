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

extern uint32_t off_10F4AC;
extern uint32_t off_10F4A8;
extern uint32_t dword_10F4B0;
extern uint32_t off_10F4B4;

// tx_power_temperature_comp @ 0x10f44c, size 90 bytes
int tx_power_temperature_comp()
{
  uint8_t *v0; // r6
  int v1; // r4
  int v2; // r0
  int result; // r0

  v0 = off_10F4AC;
  v1 = *((char *)off_10F4AC + 7) - (char)(*((uint8_t *)off_10F4AC + 5) + (*(uint8_t *)off_10F4A8 & 3));
  if ( v1 < -62 )
    LOBYTE(v1) = -62;
  gpio_config(v1);
  v2 = dword_10F4B0;
  v0[7] = v1;
  result = dispatch_event_handler(v2, (char)v1);
  if ( (char)v1 >= -61 )
    return ke_enter_critical(v0 + 12, *((uint32_t *)off_10F4B4 + 4) + 30000 * *((uint16_t *)v0 + 4));
  v0[11] = 0;
  return result;
}

