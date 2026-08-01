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

extern uint32_t off_11588C;

// ble_ll_init @ 0x115820, size 108 bytes
// Doc: ble_ll_init [rf]: LMAC RF interrupt/event handler
// ble_ll_init [rf]: LMAC RF interrupt/event handler
int ble_ll_init()
{
  int *v0; // r4
  int v1; // r0
  int v2; // r0
  int result; // r0

  v0 = (int *)off_11588C;
  v1 = read_sensor_value();
  v2 = nullsub_4(v1);
  clear_config_32(v2);
  wlan_attach(0);
  sub_100200(v0, 0, 0x94u);
  list_init(v0 + 3);
  *v0 = 0;
  *((uint8_t *)v0 + 26) = 0;
  list_init(v0 + 10);
  v0[7] = 0;
  *((uint8_t *)v0 + 54) = 0;
  list_init(v0 + 17);
  v0[14] = 0;
  *((uint8_t *)v0 + 82) = 0;
  list_init(v0 + 24);
  v0[21] = 0;
  *((uint8_t *)v0 + 110) = 0;
  result = list_init(v0 + 31);
  v0[28] = 0;
  *((uint8_t *)v0 + 138) = 0;
  *((uint16_t *)v0 + 70) = 0;
  return result;
}

