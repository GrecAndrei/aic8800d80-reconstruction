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

extern uint32_t off_12C8B8;
extern uint32_t dword_12C8BC;
extern uint32_t dword_12C8C4;
extern uint32_t dword_12C8C0;
extern uint32_t dword_12C8C8;
extern uint32_t off_12C8CC;

// rx_process_packet @ 0x12c84c, size 106 bytes
int  rx_process_packet(int a1)
{
  int16_t v1; // r3
  uint16_t *v4; // r0

  v1 = *(uint16_t *)(a1 - 6);
  if ( **(int16_t **)off_12C8B8 >= 0 || (uint8_t)v1 <= 0xEu )
  {
    if ( (uint8_t)v1 <= 0xCu )
    {
      wlan_ioctl_handler_1(dword_12C8BC);
      return irq_disable_global_2(0x4000000);
    }
  }
  else
  {
    irq_disable_mmio_write(dword_12C8C4, dword_12C8C0, 183);
  }
  alloc_tx_event(dword_12C8C8, *(uint16_t *)(a1 - 8), *(uint16_t *)(a1 - 4));
  v4 = (uint16_t *)(a1 - 12);
  if ( *(uint8_t *)off_12C8CC )
    return tx_pkt_process(v4);
  else
    return state_check_0x182ba0(v4);
}

