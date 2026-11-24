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


extern uint32_t off_10D388;
extern uint32_t off_10D38C;
extern uint32_t off_10D390;
extern uint32_t off_10D39C;
extern uint32_t off_10D3A4;

// rf_read_status_bit @ 0x10d304, size 130 bytes
int rf_read_status_bit()
{
  int v0; // r4
  char *v2; // r2
  volatile unsigned int v3; // r1
  unsigned int v4; // r1
  unsigned int v5; // r4
  int v6; // r3
  int v7; // r5

  if ( (*((uint32_t *)off_10D388 + 75) & 0x80) == 0 )
    return 1;
  v0 = (*(uint32_t *)off_10D38C >> 3) & 1;
  if ( (*(uint32_t *)off_10D38C & 8) != 0 )
  {
    v0 = (*(uint32_t *)off_10D38C >> 1) & 1;
    if ( (*(uint32_t *)off_10D38C & 2) != 0 )
    {
      v2 = (char *)off_10D38C + 5050236;
      *(uint32_t *)off_10D390 = 0x200000;
      *((uint32_t *)v2 + 1) |= 0x400000u;
      check_status_bits(2, aAsk);
      v3 = (*(volatile uint32_t *)0x40501010u);
      v4 = v3 + 2000;
      while ( 1 )
      {
        v5 = *(uint32_t *)off_10D39C;
        v6 = v4 - (*(volatile uint32_t *)0x40501010u);
        v7 = *(uint32_t *)off_10D39C & 0x300000;
        if ( v6 < 0 )
          break;
        if ( v7 )
          goto LABEL_10;
      }
      event_dispatch(aAskto);
LABEL_10:
      *(uint32_t *)off_10D3A4 = v7;
      v0 = (v5 >> 20) & 1;
      check_status_bits(2, "a_e:%d\n", v0);
    }
  }
  return v0;
}
