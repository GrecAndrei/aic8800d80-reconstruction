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

extern uint32_t off_133B30;
extern uint32_t dword_133B38;
extern uint32_t dword_133B34;

// rf_stop @ 0x133afc, size 52 bytes
int  rf_stop(int a1)
{
  int v2; // r0

  if ( **(int16_t **)off_133B30 >= 0 || (a1 = hci_cmd_send_short(6u), a1 == 10) )
  {
    check_hw_ready_status(a1);
    return 0;
  }
  else
  {
    v2 = mmio_irq_clear(dword_133B38, dword_133B34, 898);
    check_hw_ready_status(v2);
    return 0;
  }
}

