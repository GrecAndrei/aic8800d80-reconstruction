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

extern uint32_t off_136490;
extern uint32_t dword_136498;
extern uint32_t dword_136494;

// rf_cal_cmd @ 0x136448, size 70 bytes
int rf_cal_cmd()
{
  if ( **(int16_t **)off_136490 < 0 && hci_cmd_send_short(7u) != 3 && hci_cmd_send_short(7u) )
    mmio_irq_clear(dword_136498, dword_136494, 442);
  if ( hci_cmd_send_short(7u) == 3 )
    txpwr_get_state(3);
  return 0;
}

