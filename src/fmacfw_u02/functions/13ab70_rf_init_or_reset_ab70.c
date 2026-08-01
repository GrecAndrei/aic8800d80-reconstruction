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

// ll_conn_event_type_check @ 0x13ab70, size 54 bytes
// Doc: ll_conn_event_type_check [rf]: RF subsystem initialization or reset sequence
// ll_conn_event_type_check [rf]: RF subsystem initialization or reset sequence
int  ll_conn_event_type_check(int a1, uint16_t *a2)
{
  unsigned int v2; // r2
  uint16_t *v4; // r1

  v2 = *(uint16_t *)(a1 + 24);
  if ( (uint16_t)__rev16(v2) >= 0x600u )
  {
    *(a2 - 4) = -21846;
    a2 -= 4;
    a2[3] = v2;
    a2[1] = 3;
    a2[2] = 0;
  }
  v4 = ll_conn_context_get(a1, a2, 1);
  return rf_apply_chan_cfg(a1, (int)v4);
}

