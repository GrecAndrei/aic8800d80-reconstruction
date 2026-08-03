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

// mac_cmd_send_status_query @ 0x122248, size 30 bytes
// Doc: mac_cmd_send_status_query [mac]: Send MAC command 0x43 status query
// mac_cmd_send_status_query [mac]: Send MAC command 0x43 status query
int  mac_cmd_send_status_query(int a1)
{
  uint8_t *v2; // r0

  v2 = (uint8_t *)rf_bus_setup_n3a8(67, 6, 0, 1);
  *v2 = *(uint8_t *)(a1 + 107);
  return sub_12CBB4(v2);
}

