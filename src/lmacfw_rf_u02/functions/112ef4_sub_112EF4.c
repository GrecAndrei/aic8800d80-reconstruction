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

extern uint32_t off_112F4C;
extern uint32_t dword_112F50;
extern uint32_t off_112F54;
extern uint32_t dword_112F48;
extern uint32_t dword_112F44;

// map_event_type @ 0x112ef4, size 80 bytes
// Doc: rf_init_helper_n0c [util]: RF init helper, copies 18 bytes and checks config byte
// rf_init_helper_n0c [util]: RF init helper, copies 18 bytes and checks config byte
uint32_t * map_event_type(int a1)
{
  uint32_t *v2; // r4
  int v3; // r0
  unsigned int v4; // r0

  switch ( a1 )
  {
    case 1:
      v2 = off_112F4C;
      v3 = memcpy_large(off_112F4C, dword_112F50, 18);
      if ( *((uint8_t *)off_112F54 + 370) && rf_get_reg1_bit9(v3) )
      {
        v4 = rf_get_reg2();
        v2[2] = ((HIWORD(v4) << 16) + 0x10000) | (uint16_t)v4;
        return v2;
      }
      else
      {
        return off_112F4C;
      }
    case 6:
      return (uint32_t *)dword_112F48;
    case 15:
      return (uint32_t *)dword_112F44;
    default:
      return 0;
  }
}

