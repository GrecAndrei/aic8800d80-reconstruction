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

extern uint32_t off_12490C;
extern uint32_t dword_124910;

// rf_lmac_init_n190 @ 0x1248f0, size 26 bytes
// Doc: rf_lmac_init_n190 [rf]: LMAC RF subsystem init: clear status byte and invoke bringup at 0x11dc54
// rf_lmac_init_n190 [rf]: LMAC RF subsystem init: clear status byte and invoke bringup at 0x11dc54
int rf_lmac_init_n190()
{
  *(uint8_t *)off_12490C = 0;
  event_queue_push(144, 0);
  msg_parse(dword_124910);
  return 0;
}

