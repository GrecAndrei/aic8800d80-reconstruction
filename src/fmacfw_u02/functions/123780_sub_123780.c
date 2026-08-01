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

// ble_msg_helper @ 0x123780, size 32 bytes
int  ble_msg_helper(int a1, uint8_t *a2, int a3, int a4)
{
  rf_channel_calc(*a2);
  ke_msg_send_no_param(13, a4, a3);
  return 0;
}

