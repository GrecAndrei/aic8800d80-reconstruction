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

extern uint32_t off_113A9C;

// rf_msg_process_body_n_1bc @ 0x113a8c, size 16 bytes
// Doc: rf_msg_process_body_n_1bc [rf]: RF message processing body dispatcher
// rf_msg_process_body_n_1bc [rf]: RF message processing body dispatcher
BOOL rf_msg_process_body_n_1bc()
{
  return *((uint8_t *)off_113A9C + 8) == 1;
}

