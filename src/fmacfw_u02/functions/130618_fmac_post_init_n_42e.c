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

extern uint32_t off_13063C;

// fmac_post_init_n_42e @ 0x130618, size 36 bytes
// Doc: fmac_post_init_n_42e [util]: FMAC post-init/config write to MMIO 0x42e
// fmac_post_init_n_42e [util]: FMAC post-init/config write to MMIO 0x42e
int fmac_post_init_n_42e()
{
  int result; // r0

  *((uint8_t *)off_13063C + 1) = 0;
  result = message_dispatch_c8b4(1070, 1);
  if ( result )
    return event_queue_push(1070, 1);
  return result;
}

