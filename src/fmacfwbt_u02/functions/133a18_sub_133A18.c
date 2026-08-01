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

extern uint32_t off_133A54;
extern uint32_t dword_133A5C;
extern uint32_t dword_133A58;

// rf_check_status @ 0x133a18, size 58 bytes
int  rf_check_status(int a1, int a2)
{
  if ( **(int16_t **)off_133A54 >= 0 || hci_cmd_send_short(6u) == 7 )
  {
    hci_vendor_get_state(a2);
    return 1;
  }
  else
  {
    mmio_irq_clear(dword_133A5C, dword_133A58, 1012);
    hci_vendor_get_state(a2);
    return 1;
  }
}

