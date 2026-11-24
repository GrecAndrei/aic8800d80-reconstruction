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


extern uint32_t off_1159C8;

// check_op_mode @ 0x115990, size 50 bytes
void  check_op_mode()
{
  int v0; // r0
  int v1; // r0
  int v2; // r1
  int v3; // r0

  printf_wrapper(aPanic_0);
  if ( *(uint8_t *)(*(uint32_t *)off_1159C8 + 6) == 2 )
  {
    v3 = rf_mode_switch();
    periph_trigger_write(v3);
  }
  while ( 1 )
  {
    while ( !uart_rx_ready() )
      ;
    v0 = uart_getc();
    v1 = ke_malloc(v0);
    ke_event_send_1(v1, v2);
  }
}
