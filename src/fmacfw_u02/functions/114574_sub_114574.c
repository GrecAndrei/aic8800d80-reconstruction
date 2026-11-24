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


extern uint32_t off_1145A0;
extern uint32_t off_1145A4;
extern uint32_t off_1145A8;

// process_global_167204 @ 0x114574, size 40 bytes
int process_global_167204()
{
  int result; // r0
  uint8_t *v1; // r3
  uint32_t *v2; // r1

  result = event_dispatch(aErrorLpLevelPo_0);
  v1 = off_1145A0;
  if ( *((uint8_t *)off_1145A0 + 3) )
  {
    v2 = off_1145A8;
    *(uint32_t *)off_1145A4 &= ~8u;
    *v2 &= 0xFFFFFFF0;
    v1[3] = 0;
    return 0;
  }
  return result;
}
