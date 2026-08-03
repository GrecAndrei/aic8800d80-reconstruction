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

extern uint32_t dword_124964;
extern uint32_t off_12495C;
extern uint32_t off_124960;

// rf_cmd_send_n_438_4944 @ 0x124944, size 22 bytes
// Doc: rf_cmd_send_n_438_4944 [rf]: Sends RF command toggling control bits in 0x804
// rf_cmd_send_n_438_4944 [rf]: Sends RF command toggling control bits in 0x804
int rf_cmd_send_n_438_4944()
{
  msg_parse(dword_124964, *(uint32_t *)off_12495C, *(uint32_t *)off_124960 + *(uint32_t *)off_12495C);
  return 0;
}

