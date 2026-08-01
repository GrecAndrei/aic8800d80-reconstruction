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

extern uint32_t off_11DEC0;
extern uint32_t dword_11DED4;
extern uint32_t dword_11DED0;
extern uint32_t dword_11DEC8;
extern uint32_t off_11DECC;
extern uint32_t dword_11DEC4;

// rx_irq_handler @ 0x11de50, size 110 bytes
int  rx_irq_handler(int a1)
{
  int16_t v1; // r5
  uint16_t *v4; // r0

  v1 = *(uint16_t *)(a1 - 6);
  if ( **(int16_t **)off_11DEC0 < 0 && (uint8_t)v1 > 5u )
    flash_ctrl_init(dword_11DED4, dword_11DED0, 183);
  if ( (v1 & 0xFC) != 0 )
  {
    dispatch_event_handler(dword_11DEC8, *(uint16_t *)(a1 - 8));
    v4 = (uint16_t *)(a1 - 12);
    if ( *(uint8_t *)off_11DECC )
      return check_buffer_size(v4);
    else
      return patch_trampoline(v4);
  }
  else
  {
    check_kernel_state(dword_11DEC4);
    return set_busy_flag_alt(0x4000000);
  }
}

