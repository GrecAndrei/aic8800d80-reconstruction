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


extern uint32_t dword_12C8BC;
extern uint32_t off_12C8B8;
extern uint32_t off_12C8CC;

// rx_process_packet_1 @ 0x12c84c, size 106 bytes
uint32_t * rx_process_packet_1(int a1)
{
  int v1; // r3

  v1 = *(uint16_t *)(a1 - 6);
  if ( **(uint16_t **)off_12C8B8 >= 0 || (uint8_t)v1 <= 0xEu )
  {
    if ( (uint8_t)v1 <= 0xCu )
    {
      wlan_ioctl_handler_1(dword_12C8BC, (uint32_t *)(a1 - 12));
      return (uint32_t *)irq_disable_global_2(0x4000000);
    }
  }
  else
  {
    irq_disable_mmio_write((int)aIdTaskMax, (int)aKeTaskLocal, 183);
    v1 = *(uint16_t *)(a1 - 6);
  }
  alloc_tx_event(
    "\x9D\x80Dispatching msg:%x from tsk:%x to tsk:%x\n",
    *(uint16_t *)(a1 - 8),
    *(uint16_t *)(a1 - 4),
    v1);
  if ( *(uint8_t *)off_12C8CC )
    return tx_pkt_process((char *)(a1 - 12));
  else
    return (uint32_t *)state_check_0x182ba0();
}
