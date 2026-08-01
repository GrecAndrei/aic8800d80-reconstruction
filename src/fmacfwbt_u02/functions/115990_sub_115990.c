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

extern uint32_t dword_1159C4;
extern uint32_t off_1159C8;

// check_op_mode @ 0x115990, size 50 bytes
void __noreturn check_op_mode()
{
  int v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r1
  int v4; // r2

  printf_wrapper(dword_1159C4);
  if ( *(uint8_t *)(*(uint32_t *)off_1159C8 + 6) == 2 )
  {
    v2 = rf_mode_switch();
    periph_trigger_write(v2, v3, v4);
  }
  while ( 1 )
  {
    while ( !uart_rx_ready() )
      ;
    v0 = uart_getc();
    v1 = ke_malloc(v0);
    ke_event_send(v1);
  }
}

