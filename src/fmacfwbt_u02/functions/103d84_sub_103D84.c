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


extern uint32_t dword_103DF4;
extern uint32_t off_103DDC;
extern uint32_t off_103DE0;
extern uint32_t off_103DEC;
extern uint32_t off_103DF0;
extern uint32_t off_103DF8;

// mac_set_rx_timeout @ 0x103d84, size 86 bytes
int mac_set_rx_timeout()
{
  int *v0; // r4
  int *v1; // r3
  int v2; // r1
  uint32_t *v3; // r2

  v0 = (int *)off_103DE0;
  *(uint32_t *)off_103DDC = 777;
  while ( *v0 < 0 )
    timer_set(1);
  ke_event_schedule_1("end_addr=%d\n", *(uint32_t *)off_103DE0);
  *(uint32_t *)off_103DDC = 0;
  ke_event_schedule_1(aFinish);
  v1 = (int *)off_103DF0;
  v2 = dword_103DF4;
  v3 = off_103DF8;
  *(uint32_t *)off_103DEC = 0;
  *v1 = v2;
  *v3 &= 0xFF00FFFF;
  return ke_event_schedule_1("*0* dump    r 00100000 %d**\n", 0x4000);
}
