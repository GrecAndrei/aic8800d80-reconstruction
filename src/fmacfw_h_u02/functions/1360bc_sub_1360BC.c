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

extern uint32_t off_1360F0;
extern uint32_t dword_1360F8;
extern uint32_t dword_1360F4;

// is_bt_enabled @ 0x1360bc, size 52 bytes
int  is_bt_enabled(int a1)
{
  int v2; // r0

  if ( **(int16_t **)off_1360F0 >= 0 || (a1 = hci_cmd_handler(7u), a1 == 3) )
  {
    acquire_lock_check_state(a1);
    return 0;
  }
  else
  {
    v2 = irq_disable_mmio_write(dword_1360F8, dword_1360F4, 415);
    acquire_lock_check_state(v2);
    return 0;
  }
}

