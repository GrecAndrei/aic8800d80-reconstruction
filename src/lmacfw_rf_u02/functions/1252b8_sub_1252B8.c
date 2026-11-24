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

// set_local_name @ 0x1252b8, size 184 bytes
int  set_local_name(int a1, uint32_t *a2)
{
  int v4; // r0
  unsigned int v6; // r4
  int v7; // r0
  unsigned int v8; // r4
  int v9; // r5
  unsigned int v10; // r5
  int v11; // r0
  unsigned int v12; // r1

  v4 = parse_number((uint8_t *)a2[1], nullptr, 0);
  if ( v4 == 1 )
  {
    if ( a1 > 3 )
    {
      v8 = parse_number((uint8_t *)a2[2], nullptr, 0);
      v9 = parse_number((uint8_t *)a2[3], nullptr, 0x10u);
      dispatch_event_handler_1("wr efuse: [%d]=%08X\r\n", v8, v9);
      mmio_write32(v8, v9);
    }
  }
  else
  {
    if ( v4 != 2 )
      return -(v4 != 0);
    v6 = parse_number((uint8_t *)a2[2], nullptr, 0);
    if ( v6 <= 0x1F )
    {
      if ( a1 > 3 )
      {
        v10 = parse_number((uint8_t *)a2[3], nullptr, 0) + v6;
        if ( v10 >= 0x20 )
          v10 = 32;
        dispatch_event_handler_1(aRdEfuse);
        while ( v10 > v6 )
        {
          v11 = mmio_read32(v6);
          v12 = v6++;
          dispatch_event_handler_1("[%d]=%08X\r\n", v12, v11);
        }
      }
      else
      {
        dispatch_event_handler_1(aRdEfuse);
        v7 = mmio_read32(v6);
        dispatch_event_handler_1("[%d]=%08X\r\n", v6, v7);
      }
    }
  }
  return 0;
}
