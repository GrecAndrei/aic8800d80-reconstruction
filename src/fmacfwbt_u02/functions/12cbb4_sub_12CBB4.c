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


extern uint32_t dword_12CC24;
extern uint32_t off_12CC20;
extern uint32_t off_12CC34;

// hci_evt_send @ 0x12cbb4, size 106 bytes
uint32_t * hci_evt_send(int a1)
{
  int v1; // r3

  v1 = *(uint16_t *)(a1 - 6);
  if ( **(uint16_t **)off_12CC20 >= 0 || (uint8_t)v1 <= 0xEu )
  {
    if ( (uint8_t)v1 <= 0xCu )
    {
      check_abort_flag(dword_12CC24, (uint32_t *)(a1 - 12));
      return (uint32_t *)set_system_flag_1(0x4000000);
    }
  }
  else
  {
    mmio_irq_clear((int)aIdTaskMax, (int)aKeTaskLocal, 183);
    v1 = *(uint16_t *)(a1 - 6);
  }
  ke_event_schedule_1(
    "\x9D\x80Dispatching msg:%x from tsk:%x to tsk:%x\n",
    *(uint16_t *)(a1 - 8),
    *(uint16_t *)(a1 - 4),
    v1);
  if ( *(uint8_t *)off_12CC34 )
    return hci_tx_packet((char *)(a1 - 12));
  else
    return (uint32_t *)patch_jump();
}
