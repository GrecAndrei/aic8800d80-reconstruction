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

extern uint32_t dword_135B7C;

// hci_vendor_cmd_dispatch @ 0x135b4c, size 46 bytes
uint32_t * hci_vendor_cmd_dispatch(int a1)
{
  irq_lock(6154, 6);
  if ( !a1 )
    return rf_lookup_alt_by_index();
  state_check_feature(256, dword_135B7C, a1);
  return (uint32_t *)event_dispatch(a1);
}

