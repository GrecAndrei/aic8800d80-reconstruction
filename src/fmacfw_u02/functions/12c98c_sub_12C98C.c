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

extern uint32_t off_12C9F8;
extern uint32_t dword_12C9FC;
extern uint32_t dword_12CA04;
extern uint32_t dword_12CA00;
extern uint32_t dword_12CA08;
extern uint32_t off_12CA0C;

// ke_msg_send @ 0x12c98c, size 106 bytes
int  ke_msg_send(int a1)
{
  int16_t v1; // r3
  uint16_t *v4; // r0

  v1 = *(uint16_t *)(a1 - 6);
  if ( **(int16_t **)off_12C9F8 >= 0 || (uint8_t)v1 <= 0xEu )
  {
    if ( (uint8_t)v1 <= 0xCu )
    {
      cmd_handler_a(dword_12C9FC);
      return unknown_func_12d104(0x4000000);
    }
  }
  else
  {
    mmio_clear_register(dword_12CA04, dword_12CA00, 183);
  }
  event_dispatch(dword_12CA08, *(uint16_t *)(a1 - 8), *(uint16_t *)(a1 - 4));
  v4 = (uint16_t *)(a1 - 12);
  if ( *(uint8_t *)off_12CA0C )
    return tx_pkt_enqueue(v4);
  else
    return read_mode_0x182ba0(v4);
}

