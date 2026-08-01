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

extern uint32_t off_11EF30;
extern uint32_t off_11EF34;

// tx_packet_finish @ 0x11eee0, size 78 bytes
int  tx_packet_finish(int a1)
{
  char *v2; // r0
  void *v3; // r0
  char v4; // r2

  tx_timestamp_get(a1, *(uint32_t *)(a1 + 28));
  v2 = (char *)off_11EF30;
  if ( *((uint32_t *)off_11EF30 + 14) )
  {
    *(uint8_t *)(a1 + 16) |= 1u;
    *(uint32_t *)(a1 + 4) = 0;
    v3 = v2 + 56;
    return check_abort_flag(v3);
  }
  v3 = off_11EF34;
  if ( *(uint32_t *)off_11EF34 )
  {
    v4 = *(uint8_t *)(a1 + 16);
    *(uint32_t *)(a1 + 4) = 0;
    *(uint8_t *)(a1 + 16) = v4 | 1;
    return check_abort_flag(v3);
  }
  return rf_tx_timestamp_check(a1);
}

