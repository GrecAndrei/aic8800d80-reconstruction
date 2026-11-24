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


extern uint32_t dword_11DEC4;
extern uint32_t off_11DEC0;
extern uint32_t off_11DECC;

// rx_irq_handler_1 @ 0x11de50, size 110 bytes
uint32_t * rx_irq_handler_1(int a1)
{
  uint16_t v1; // r5

  v1 = *(uint16_t *)(a1 - 6);
  if ( **(uint16_t **)off_11DEC0 < 0 && (uint8_t)v1 > 5u )
    flash_ctrl_init((int)aIdTaskMax, (int)aKeTaskLocal, 183);
  if ( (v1 & 0xFC) != 0 )
  {
    dispatch_event_handler_1(
      "\x9D\x80Dispatching msg:%x from tsk:%x to tsk:%x\n",
      *(uint16_t *)(a1 - 8),
      *(uint16_t *)(a1 - 4),
      *(uint16_t *)(a1 - 6));
    if ( *(uint8_t *)off_11DECC )
      return check_buffer_size((char *)(a1 - 12));
    else
      return (uint32_t *)patch_trampoline();
  }
  else
  {
    check_kernel_state(dword_11DEC4, (uint32_t *)(a1 - 12));
    return (uint32_t *)set_busy_flag_alt(0x4000000);
  }
}
