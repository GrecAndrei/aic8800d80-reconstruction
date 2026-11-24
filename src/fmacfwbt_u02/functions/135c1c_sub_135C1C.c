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

// hci_vendor_read_rf_cache @ 0x135c1c, size 124 bytes
int  hci_vendor_read_rf_cache(uint16_t *a1)
{
  uint16_t *v1; // r6
  int v3; // r5
  int result; // r0
  int v5; // r3
  int v6; // r3

  v1 = a1 + 6;
  irq_lock((char *)0x180A, 6);
  v3 = v1[2];
  result = state_check_feature(256, "auth_handler:%d\r\n", v3);
  if ( v3 )
    return event_dispatch_1(v3);
  v5 = a1[6];
  if ( !a1[6] )
    return rf_lookup_alt_by_index();
  if ( v5 != 1 )
  {
    if ( v5 == 2 )
      return send_hci_vendor_cmd(*((uint8_t *)a1 + 8), (int)(a1 + 9), (uint16_t)(*a1 - 6));
    return result;
  }
  v6 = v1[1];
  if ( v6 == 4 )
  {
    wait_for_hw_data(0xBB8u);
    return rf_lookup_alt_by_index();
  }
  if ( v6 == 2 && *a1 > 0x22u )
    return rf_lookup_by_index(3, (int)(a1 + 10));
  return result;
}
