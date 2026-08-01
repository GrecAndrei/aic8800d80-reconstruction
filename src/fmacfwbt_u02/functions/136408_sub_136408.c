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

extern uint32_t off_13643C;
extern uint32_t dword_136444;
extern uint32_t dword_136440;

// rf_cal_trigger @ 0x136408, size 52 bytes
// Doc: sub_1236408 [util]: Check shared half-word status flag from globals table and branch
// sub_1236408 [util]: Check shared half-word status flag from globals table and branch
int  rf_cal_trigger(int value)
{
  int v2; // r0

  if ( **(int16_t **)off_13643C >= 0 || (value = hci_cmd_send_short(7u), value == 3) )
  {
    txpwr_get_state(value);
    return 0;
  }
  else
  {
    v2 = mmio_irq_clear(dword_136444, dword_136440, 415);
    txpwr_get_state(v2);
    return 0;
  }
}

