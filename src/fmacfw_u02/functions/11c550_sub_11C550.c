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

extern uint32_t dword_11C580;
extern uint32_t off_11C584;

// check_channel_busy @ 0x11c550, size 46 bytes
unsigned int * check_channel_busy(unsigned int *result)
{
  int v1; // r2

  v1 = *(uint16_t *)(dword_11C580 + 1320 * *((uint8_t *)result + 28) + 1222);
  if ( v1 != 1023 && *((uint8_t *)off_11C584 + 361) != 2 )
    return check_packet_type((unsigned int *)(result[17] + 4), *(uint32_t *)(result[17] + 40), v1);
  return result;
}

