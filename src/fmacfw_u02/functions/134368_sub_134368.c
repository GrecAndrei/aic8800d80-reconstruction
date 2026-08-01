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

extern uint32_t dword_134384;
extern uint32_t off_134388;

// send_app_message @ 0x134368, size 26 bytes
int send_app_message()
{
  int result; // r0

  event_dispatch(dword_134384);
  result = ke_int_lock(6155, 6);
  *((uint8_t *)off_134388 + 15) = 0;
  return result;
}

