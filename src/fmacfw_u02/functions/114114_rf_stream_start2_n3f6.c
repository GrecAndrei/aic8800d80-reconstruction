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

extern uint32_t off_114154;
extern uint32_t dword_114160;
extern uint32_t off_114158;
extern uint32_t off_11415C;
extern uint32_t dword_114164;

// invoke_callback @ 0x114114, size 64 bytes
// Doc: rf_msg_process_body_alt_12a [rf]: Alternate RF message body processor
// rf_msg_process_body_alt_12a [rf]: Alternate RF message body processor
int invoke_callback()
{
  int v0; // r0
  uint32_t *v1; // r4
  int result; // r0

  v0 = (*(int ( **)(uint32_t))(*((uint32_t *)off_114154 + 2) + 16))(*((uint32_t *)off_114154 + 1));
  if ( !v0 )
    return log_printf(dword_114160);
  v1 = (uint32_t *)v0;
  result = irq_state_load_b(*(uint32_t *)off_114158 + v0, *(uint32_t *)off_11415C);
  if ( result < 0 )
  {
    is_controller_mode(v1);
    return log_printf(dword_114164);
  }
  return result;
}

