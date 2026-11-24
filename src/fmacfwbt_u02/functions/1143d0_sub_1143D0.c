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


extern uint32_t off_1143FC;
extern uint32_t off_114400;
extern uint32_t off_114404;

// log_and_check_hw @ 0x1143d0, size 40 bytes
int log_and_check_hw()
{
  int result; // r0
  uint8_t *v1; // r3
  uint32_t *v2; // r1

  result = ke_event_schedule_1(aErrorLpLevelPo_0);
  v1 = off_1143FC;
  if ( *((uint8_t *)off_1143FC + 3) )
  {
    v2 = off_114404;
    *(uint32_t *)off_114400 &= ~8u;
    *v2 &= 0xFFFFFFF0;
    v1[3] = 0;
    return 0;
  }
  return result;
}
