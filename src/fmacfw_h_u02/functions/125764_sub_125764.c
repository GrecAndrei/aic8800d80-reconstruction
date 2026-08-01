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

extern uint32_t off_12577C;

// co_list_push @ 0x125764, size 22 bytes
int  co_list_push(uint16_t *a1)
{
  if ( *((uint32_t *)off_12577C + 1) )
    return wlan_ioctl_handler_1((char *)off_12577C + 12);
  else
    return rx_pkt_parse(a1);
}

