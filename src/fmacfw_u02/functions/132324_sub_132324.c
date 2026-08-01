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

// ke_buf_alloc @ 0x132324, size 48 bytes
int  ke_buf_alloc(int a1)
{
  uint8_t *v2; // r4

  v2 = (uint8_t *)ke_msg_alloc(12, 0, 5, 1u);
  rf_scan_chan(a1);
  *v2 = a1;
  ke_msg_send((int)v2);
  return ke_msg_send_no_param(5130, 13, 5);
}

