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

extern uint32_t dword_115298;
extern uint32_t dword_1152A8;
extern uint32_t dword_1152B0;
extern uint32_t dword_1152AC;
extern uint32_t dword_11529C;
extern uint32_t dword_1152A0;
extern uint32_t dword_1152A4;

// sub_115250 @ 0x115250, size 72 bytes
void  __noreturn sub_115250(int a1)
{
  sub_10DAE4(dword_115298);
  switch ( a1 )
  {
    case '0':
      sub_10DAE4(dword_1152A8);
      break;
    case '@':
      sub_10DAE4(dword_1152B0);
      break;
    case ' ':
      sub_10DAE4(dword_1152AC);
      break;
    default:
      sub_10DAE4(dword_11529C);
      break;
  }
  sub_10DAE4(dword_1152A0);
  sub_114FEC();
  sub_10DAE4(dword_1152A4);
  sub_115214();
}

