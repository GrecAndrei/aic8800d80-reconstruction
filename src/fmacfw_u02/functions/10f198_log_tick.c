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

extern uint32_t off_10F1F8;
extern uint32_t off_10F1F4;
extern uint32_t dword_10F1FC;
extern uint32_t off_10F200;

// rf_update_rx_status @ 0x10f198, size 90 bytes
// Doc: rf_update_rx_status [util]: Periodic log tick sampling byte/sbyte state fields
// rf_update_rx_status [util]: Periodic log tick sampling byte/sbyte state fields
int rf_update_rx_status()
{
  uint8_t *v0; // r6
  int v1; // r5
  int v2; // r4
  int v3; // r0
  int result; // r0

  v0 = off_10F1F8;
  v1 = (char)(*((uint8_t *)off_10F1F8 + 5) + (*(uint8_t *)off_10F1F4 & 3));
  v2 = *((char *)off_10F1F8 + 7) - v1;
  if ( v2 < -62 )
    LOBYTE(v2) = -62;
  write_phy_config(v2);
  v3 = dword_10F1FC;
  v0[7] = v2;
  result = event_dispatch(v3, (char)v2, v1);
  if ( (char)v2 >= -61 )
    return unknown_worker(v0 + 12, *((uint32_t *)off_10F200 + 4) + 30000 * *((uint16_t *)v0 + 4));
  v0[11] = 0;
  return result;
}

