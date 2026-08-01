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

extern uint32_t dword_10F0FC;
extern uint32_t dword_10F104;
extern uint32_t dword_10F100;
extern uint32_t dword_10F108;
extern uint32_t dword_10F10C;

// ke_event_set @ 0x10f0b8, size 66 bytes
// Doc: ke_event_set [rf]: Check RF state, store halfword and trigger 0x1119c0
// ke_event_set [rf]: Check RF state, store halfword and trigger 0x1119c0
int  ke_event_set(int a1)
{
  dispatch_event_handler(dword_10F0FC, a1);
  critical_enter3(dword_10F104, 196608, dword_10F100, 1);
  critical_enter3(1879048192, 1, 1, 1);
  critical_enter2(dword_10F108, a1, 1);
  return critical_enter3(dword_10F10C, 2, 2, 1);
}

