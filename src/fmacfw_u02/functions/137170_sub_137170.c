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

// rf_set_config_803 @ 0x137170, size 40 bytes
int rf_set_config_803()
{
  int v0; // r0
  int v1; // r0

  v0 = ke_msg_alloc(2051, 2, 4, 1);
  ke_msg_send_2(v0);
  v1 = rx_rate_field_parse(4u);
  check_status_bits(8, "scanu cancel:%d\r\n", v1);
  return 0;
}
