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

// scan_done_check_alt @ 0x12c760, size 60 bytes
// Doc: message_dispatch_n_42a [ipc]: Dispatch a control message to message handler with tag 0x6d
// message_dispatch_n_42a [ipc]: Dispatch a control message to message handler with tag 0x6d
void  scan_done_check_alt(int a1, int a2, uint8_t *a3)
{
  int v3; // r4
  int v4; // r0

  if ( *((uint8_t *)message_dispatch_n_418_c79c + 197) )
  {
    v3 = *(uint32_t *)(*(uint32_t *)(a2 + 76) + 48);
    v4 = llm_rx_pdu_handler((*(uint32_t *)(v3 + 20) >> 11) & 7, *(uint32_t *)(v3 + 20) & 0x7F, a3);
    *(uint32_t *)(v3 + 36) = v4 | (v4 << 8);
  }
  else if ( **(int16_t **)tx_message_dispatch < 0 )
  {
    mmio_irq_clear(message_dispatch_n_40c_c7a8, message_dispatch_n_410, 109);
  }
}

