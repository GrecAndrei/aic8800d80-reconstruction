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

extern uint32_t off_11E9B0;
extern uint32_t off_11E9B4;

// tx_packet_kick @ 0x11e960, size 78 bytes
int  tx_packet_kick(int a1)
{
  char *v2; // r0
  void *v3; // r0
  char v4; // r2

  ble_get_rssi(a1, *(uint32_t *)(a1 + 28));
  v2 = (char *)off_11E9B0;
  if ( *((uint32_t *)off_11E9B0 + 14) )
  {
    *(uint8_t *)(a1 + 16) |= 1u;
    *(uint32_t *)(a1 + 4) = 0;
    v3 = v2 + 56;
    return wlan_ioctl_handler_1(v3);
  }
  v3 = off_11E9B4;
  if ( *(uint32_t *)off_11E9B4 )
  {
    v4 = *(uint8_t *)(a1 + 16);
    *(uint32_t *)(a1 + 4) = 0;
    *(uint8_t *)(a1 + 16) = v4 | 1;
    return wlan_ioctl_handler_1(v3);
  }
  return phy_rate_get(a1);
}

