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


extern uint32_t off_113680;
extern uint32_t off_113684;
extern uint32_t off_113688;

// dispatch_event_handler @ 0x113640, size 64 bytes
int dispatch_event_handler()
{
  int v0; // r0
  uint32_t *v1; // r4
  int result; // r0

  v0 = (*(int ( **)(uint32_t))(*((uint32_t *)off_113680 + 2) + 16))(*((uint32_t *)off_113680 + 1));
  if ( !v0 )
    return log_printf(aErrNoWlanDataB);
  v1 = (uint32_t *)v0;
  result = send_data_packet(*(uint32_t *)off_113684 + v0, *(uint32_t *)off_113688);
  if ( result < 0 )
  {
    mem_free(v1);
    return log_printf(aWlanDataRecvRe);
  }
  return result;
}
