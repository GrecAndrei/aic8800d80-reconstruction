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

extern uint32_t off_1336F8;
extern uint32_t dword_133700;
extern uint32_t dword_1336FC;

// ble_state_check_1336bc @ 0x1336bc, size 58 bytes
int  ble_state_check_1336bc(int a1, int a2)
{
  if ( **(int16_t **)off_1336F8 >= 0 || hci_cmd_handler(6u) == 7 )
  {
    ke_msg_dispatch(a2);
    return 1;
  }
  else
  {
    irq_disable_mmio_write(dword_133700, dword_1336FC, 1012);
    ke_msg_dispatch(a2);
    return 1;
  }
}

