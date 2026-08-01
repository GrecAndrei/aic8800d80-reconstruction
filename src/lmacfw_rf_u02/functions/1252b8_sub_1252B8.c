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

extern uint32_t dword_125378;
extern uint32_t dword_125370;
extern uint32_t dword_125374;

// set_local_name @ 0x1252b8, size 184 bytes
int  set_local_name(int a1, uint8_t **a2)
{
  int v4; // r0
  unsigned int v6; // r4
  int v7; // r0
  unsigned int v8; // r4
  int v9; // r5
  unsigned int v10; // r5
  int v11; // r6
  int v12; // r0
  unsigned int v13; // r1

  v4 = parse_number(a2[1], 0, 0);
  if ( v4 == 1 )
  {
    if ( a1 > 3 )
    {
      v8 = parse_number(a2[2], 0, 0);
      v9 = parse_number(a2[3], 0, 0x10u);
      dispatch_event_handler(dword_125378, v8, v9);
      mmio_write32(v8, v9);
    }
  }
  else
  {
    if ( v4 != 2 )
      return -(v4 != 0);
    v6 = parse_number(a2[2], 0, 0);
    if ( v6 <= 0x1F )
    {
      if ( a1 > 3 )
      {
        v10 = parse_number(a2[3], 0, 0) + v6;
        if ( v10 >= 0x20 )
          v10 = 32;
        dispatch_event_handler(dword_125370);
        if ( v6 < v10 )
        {
          v11 = dword_125374;
          do
          {
            v12 = mmio_read32(v6);
            v13 = v6++;
            dispatch_event_handler(v11, v13, v12);
          }
          while ( v10 > v6 );
        }
      }
      else
      {
        dispatch_event_handler(dword_125370);
        v7 = mmio_read32(v6);
        dispatch_event_handler(dword_125374, v6, v7);
      }
    }
  }
  return 0;
}

