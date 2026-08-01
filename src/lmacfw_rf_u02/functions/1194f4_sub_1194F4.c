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

// send_event_0x70 @ 0x1194f4, size 14 bytes
// Doc: sub_12194F4 [util]: Thin wrapper invoking helper with param 0x70
// sub_12194F4 [util]: Thin wrapper invoking helper with param 0x70
int  send_event_0x70(int a1, int a2, int a3, int a4)
{
  ke_evt_handler(112, a4, a3);
  return 0;
}

