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


extern uint32_t off_136F48;

// rf_send_channel @ 0x136f20, size 40 bytes
int rf_send_channel()
{
  uint16_t *v0; // r4
  int v1; // r0

  v0 = (uint16_t *)off_136F48;
  v1 = ke_msg_alloc(4107, *((uint16_t *)off_136F48 + 1924), 4, 1);
  ke_msg_send_2(v1);
  check_status_bits(8, "scan idle cancel cfm %d\r\n", v0[1924]);
  return 0;
}
