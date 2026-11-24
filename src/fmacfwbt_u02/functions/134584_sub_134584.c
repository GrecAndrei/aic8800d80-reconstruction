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


extern uint32_t off_1345A4;

// ll_state_error_check @ 0x134584, size 26 bytes
int ll_state_error_check()
{
  int result; // r0

  ke_event_schedule_1(aTs2);
  result = (int)irq_lock((char *)0x180B, 6);
  *((uint8_t *)off_1345A4 + 15) = 0;
  return result;
}
