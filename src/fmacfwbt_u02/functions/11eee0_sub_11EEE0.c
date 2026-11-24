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
  void *v2; // r0
  uint32_t *v3; // r1
  int v4; // r0
  char v5; // r2

  tx_timestamp_get(a1, *(uint32_t *)(a1 + 28));
  v2 = off_11EF30;
  if ( *((uint32_t *)off_11EF30 + 14) )
  {
    *(uint8_t *)(a1 + 16) |= 1u;
    *(uint32_t *)(a1 + 4) = 0;
    v3 = (uint32_t *)a1;
    v4 = (int)v2 + 56;
    return check_abort_flag(v4, v3);
  }
  v4 = off_11EF34;
  if ( *(uint32_t *)off_11EF34 )
  {
    v5 = *(uint8_t *)(a1 + 16);
    *(uint32_t *)(a1 + 4) = 0;
    *(uint8_t *)(a1 + 16) = v5 | 1;
    v3 = (uint32_t *)a1;
    return check_abort_flag(v4, v3);
  }
  return rf_tx_timestamp_check(a1);
}
