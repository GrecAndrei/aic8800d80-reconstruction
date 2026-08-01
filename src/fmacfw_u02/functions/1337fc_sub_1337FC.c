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

extern uint32_t off_133838;
extern uint32_t dword_133840;
extern uint32_t dword_13383C;

// patch_flag_set @ 0x1337fc, size 58 bytes
// Doc: sub_1233806 [util]: Trampoline stub with saved r4/lr
// sub_1233806 [util]: Trampoline stub with saved r4/lr
int  patch_flag_set(int a1, int a2)
{
  if ( **(int16_t **)off_133838 >= 0 || rx_rate_field_parse(6u) == 7 )
  {
    bt_send_hci_event(a2);
    return 1;
  }
  else
  {
    mmio_clear_register(dword_133840, dword_13383C, 1012);
    bt_send_hci_event(a2);
    return 1;
  }
}

