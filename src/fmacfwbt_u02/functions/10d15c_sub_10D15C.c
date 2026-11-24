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


extern uint32_t off_10D1E0;
extern uint32_t off_10D1E4;
extern uint32_t off_10D1E8;
extern uint32_t off_10D1F4;
extern uint32_t off_10D1FC;

// status_poll @ 0x10d15c, size 130 bytes
int status_poll()
{
  int v0; // r4
  char *v2; // r2
  volatile unsigned int v3; // r1
  unsigned int v4; // r1
  unsigned int v5; // r4
  int v6; // r3
  int v7; // r5

  if ( (*((uint32_t *)off_10D1E0 + 75) & 0x80) == 0 )
    return 1;
  v0 = (*(uint32_t *)off_10D1E4 >> 3) & 1;
  if ( (*(uint32_t *)off_10D1E4 & 8) != 0 )
  {
    v0 = (*(uint32_t *)off_10D1E4 >> 1) & 1;
    if ( (*(uint32_t *)off_10D1E4 & 2) != 0 )
    {
      v2 = (char *)off_10D1E4 + 5050236;
      *(uint32_t *)off_10D1E8 = 0x200000;
      *((uint32_t *)v2 + 1) |= 0x400000u;
      state_check_feature(2, aAsk);
      v3 = (*(volatile uint32_t *)0x40501010u);
      v4 = v3 + 2000;
      while ( 1 )
      {
        v5 = *(uint32_t *)off_10D1F4;
        v6 = v4 - (*(volatile uint32_t *)0x40501010u);
        v7 = *(uint32_t *)off_10D1F4 & 0x300000;
        if ( v6 < 0 )
          break;
        if ( v7 )
          goto LABEL_10;
      }
      ke_event_schedule_1(aAskto);
LABEL_10:
      *(uint32_t *)off_10D1FC = v7;
      v0 = (v5 >> 20) & 1;
      state_check_feature(2, "a_e:%d\n", v0);
    }
  }
  return v0;
}
