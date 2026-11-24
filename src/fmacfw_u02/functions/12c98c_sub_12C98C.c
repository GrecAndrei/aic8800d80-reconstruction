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


extern uint32_t dword_12C9FC;
extern uint32_t off_12C9F8;
extern uint32_t off_12CA0C;

// ke_msg_send_2 @ 0x12c98c, size 106 bytes
uint32_t * ke_msg_send_2(int a1)
{
  int v1; // r3

  v1 = *(uint16_t *)(a1 - 6);
  if ( **(uint16_t **)off_12C9F8 >= 0 || (uint8_t)v1 <= 0xEu )
  {
    if ( (uint8_t)v1 <= 0xCu )
    {
      cmd_handler_a(dword_12C9FC, (uint32_t *)(a1 - 12));
      return (uint32_t *)unknown_func_12d104(0x4000000);
    }
  }
  else
  {
    mmio_clear_register((int)aIdTaskMax, (int)aKeTaskLocal, 183);
    v1 = *(uint16_t *)(a1 - 6);
  }
  event_dispatch(
    "\x9D\x80Dispatching msg:%x from tsk:%x to tsk:%x\n",
    *(uint16_t *)(a1 - 8),
    *(uint16_t *)(a1 - 4),
    v1);
  if ( *(uint8_t *)off_12CA0C )
    return tx_pkt_enqueue((char *)(a1 - 12));
  else
    return (uint32_t *)read_mode_0x182ba0();
}
