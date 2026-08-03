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

extern uint32_t off_12EC74;

// rf_cmd_process_n4e @ 0x12ec6c, size 6 bytes
// Doc: rf_cmd_process_n4e [rf]: RF command processing: store header, call sub, shift nibble from r8
// rf_cmd_process_n4e [rf]: RF command processing: store header, call sub, shift nibble from r8
int rf_cmd_process_n4e()
{
  return *(uint32_t *)off_12EC74;
}

