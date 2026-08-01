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

extern uint32_t off_123E14;
extern uint32_t dword_123E1C;
extern uint32_t dword_123E18;
extern uint32_t off_123E20;
extern uint32_t dword_123E24;

// state_is_valid @ 0x123d9c, size 118 bytes
// Doc: state_is_valid [bt]: BT main message handler dispatch entry; checks a global flag and forwards args
// state_is_valid [bt]: BT main message handler dispatch entry; checks a global flag and forwards args
int  state_is_valid(int a1, void ( **a2)(int), int a3)
{
  int16_t **v3; // r5
  int result; // r0
  int v7; // r0

  v3 = (int16_t **)off_123E14;
  if ( **(int16_t **)off_123E14 < 0 && hci_cmd_send_short(a3) == 4 )
    mmio_irq_clear(dword_123E1C, dword_123E18, 1587);
  result = hci_cmd_send_short(a3);
  if ( result )
  {
    if ( result != 2 )
    {
      rf_check_clk_state(result);
      hci_cmd_send(a3);
      return 2;
    }
  }
  else
  {
    if ( **v3 < 0 && *(uint32_t *)off_123E20 << 28 )
      mmio_irq_clear(dword_123E24, dword_123E18, 1594);
    v7 = hci_cmd_send(a3);
    (*a2)(v7);
    return 0;
  }
  return result;
}

