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


extern uint32_t off_114460;
extern uint32_t off_114464;
extern uint32_t off_114468;

// process_event @ 0x114434, size 40 bytes
int process_event()
{
  int result; // r0
  uint8_t *v1; // r3
  uint32_t *v2; // r1

  result = alloc_tx_event(aErrorLpLevelPo_0);
  v1 = off_114460;
  if ( *((uint8_t *)off_114460 + 3) )
  {
    v2 = off_114468;
    *(uint32_t *)off_114464 &= ~8u;
    *v2 &= 0xFFFFFFF0;
    v1[3] = 0;
    return 0;
  }
  return result;
}
