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

extern uint32_t dword_1190AC;
extern uint32_t dword_1190B0;

// event_notify @ 0x119084, size 38 bytes
// Doc: sub_1219084 [util]: Helper that loads a context struct via helper at 0x12d4f8 and returns object
// sub_1219084 [util]: Helper that loads a context struct via helper at 0x12d4f8 and returns object
int  event_notify(int a1, int a2)
{
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r4

  v4 = list_pop_front(dword_1190AC);
  v7 = v4;
  if ( v4 )
  {
    tx_packet_enqueue(v4, a1, a2);
    return v7;
  }
  else
  {
    ke_event_schedule(dword_1190B0, v5, v6);
    return 0;
  }
}

