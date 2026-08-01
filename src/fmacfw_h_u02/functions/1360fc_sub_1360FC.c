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

extern uint32_t off_136144;
extern uint32_t dword_13614C;
extern uint32_t dword_136148;

// is_bt_initialized @ 0x1360fc, size 70 bytes
int is_bt_initialized()
{
  if ( **(int16_t **)off_136144 < 0 && hci_cmd_handler(7u) != 3 && hci_cmd_handler(7u) )
    irq_disable_mmio_write(dword_13614C, dword_136148, 442);
  if ( hci_cmd_handler(7u) == 3 )
    acquire_lock_check_state(3);
  return 0;
}

