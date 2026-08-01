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

// rx_parse_descriptor @ 0x133a98, size 98 bytes
// Doc: rf_cmd_send_n_356 [rf]: Clears cmd flag and disables RF cmd interrupt in MMIO 0x40200e00
// rf_cmd_send_n_356 [rf]: Clears cmd flag and disables RF cmd interrupt in MMIO 0x40200e00
int  rx_parse_descriptor(int a1, int a2)
{
  int v2; // r3

  v2 = *(uint16_t *)(a2 + 2) & 0xFC;
  switch ( v2 )
  {
    case 176:
      if ( hci_cmd_send_short(6u) == 5 )
        hci_vendor_read_rf_cache(a2);
      break;
    case 16:
    case 48:
      if ( hci_cmd_send_short(6u) == 8 )
        hci_vendor_read_rf(a2);
      break;
    case 192:
    case 160:
      return rf_check_channel_10(a2);
    default:
      if ( v2 == 208 && *(uint8_t *)(a2 + 12) == 8 )
        rf_get_power_by_index(a2);
      break;
  }
  return 0;
}

