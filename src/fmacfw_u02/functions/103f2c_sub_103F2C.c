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


extern uint32_t dword_103F9C;
extern uint32_t off_103F84;
extern uint32_t off_103F88;
extern uint32_t off_103F94;
extern uint32_t off_103F98;
extern uint32_t off_103FA0;

// mac_phy_config @ 0x103f2c, size 86 bytes
int mac_phy_config()
{
  int *v0; // r4
  int *v1; // r3
  int v2; // r1
  uint32_t *v3; // r2

  v0 = (int *)off_103F88;
  *(uint32_t *)off_103F84 = 777;
  while ( *v0 < 0 )
    timer_delay(1);
  event_dispatch("end_addr=%d\n", *(uint32_t *)off_103F88);
  *(uint32_t *)off_103F84 = 0;
  event_dispatch(aFinish);
  v1 = (int *)off_103F98;
  v2 = dword_103F9C;
  v3 = off_103FA0;
  *(uint32_t *)off_103F94 = 0;
  *v1 = v2;
  *v3 &= 0xFF00FFFF;
  return event_dispatch("*0* dump    r 00100000 %d**\n", 0x4000);
}
