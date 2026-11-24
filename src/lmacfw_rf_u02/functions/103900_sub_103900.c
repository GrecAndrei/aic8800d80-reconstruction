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


extern uint32_t dword_103970;
extern uint32_t off_103958;
extern uint32_t off_10395C;
extern uint32_t off_103968;
extern uint32_t off_10396C;
extern uint32_t off_103974;

// enable_bb_clock @ 0x103900, size 86 bytes
int enable_bb_clock()
{
  int *v0; // r4
  int *v1; // r3
  int v2; // r1
  uint32_t *v3; // r2

  v0 = (int *)off_10395C;
  *(uint32_t *)off_103958 = 777;
  while ( *v0 < 0 )
    write_timer_reg(1);
  dispatch_event_handler_1("end_addr=%d\n", *(uint32_t *)off_10395C);
  *(uint32_t *)off_103958 = 0;
  dispatch_event_handler_1(aFinish);
  v1 = (int *)off_10396C;
  v2 = dword_103970;
  v3 = (uint32_t *)off_103974;
  *(uint32_t *)off_103968 = 0;
  *v1 = v2;
  *v3 &= 0xFF00FFFF;
  return dispatch_event_handler_1("*0* dump    r 00100000 %d**\n", 0x4000);
}
