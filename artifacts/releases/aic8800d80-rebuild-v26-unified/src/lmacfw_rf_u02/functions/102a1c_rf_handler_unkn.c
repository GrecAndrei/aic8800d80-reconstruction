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

extern uint32_t dword_102A48;
extern uint32_t dword_102A44;
extern uint32_t off_102A4C;
extern uint32_t dword_102A54;
extern uint32_t dword_102A50;

// rf_handler_unkn @ 0x102a1c, size 38 bytes
// Doc: rf_handler_unkn [rf]: Unidentified RF helper routine
// rf_handler_unkn [rf]: Unidentified RF helper routine
int rf_handler_unkn()
{
  int result; // r0

  result = msg_parse(dword_102A48, dword_102A44);
  if ( **(int16_t **)off_102A4C < 0 )
    return rf_cmd_send_n264(dword_102A54, dword_102A50, 61);
  return result;
}

