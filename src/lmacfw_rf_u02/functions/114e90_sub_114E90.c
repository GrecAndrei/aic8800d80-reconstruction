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


extern uint32_t off_114EC8;

// bt_check_state @ 0x114e90, size 50 bytes
void  bt_check_state()
{
  int v0; // r0
  int v1; // r0

  log_printf(aPanic_0);
  if ( *(uint8_t *)(*(uint32_t *)off_114EC8 + 6) == 2 )
  {
    v1 = wait_hw_ready();
    ke_event_set(v1);
  }
  while ( 1 )
  {
    while ( !uart_rx_ready() )
      ;
    v0 = uart_rx_byte();
    process_queue_message(v0);
    exit_critical_section();
  }
}
