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


extern uint32_t dword_12605C;
extern uint32_t off_126054;

// check_radio_flag @ 0x125ffc, size 88 bytes
int  check_radio_flag(int a1, int a2, int a3)
{
  uint8_t v4[8]; // [sp+4h] [bp-8h] BYREF

  if ( (*(uint32_t *)off_126054 & 0x2000000) != 0 )
  {
    dispatch_event_handler_1("getcc: %s\r\n", (const char *)dword_12605C);
    return 0;
  }
  else
  {
    *(uint16_t *)v4 = 0;
    rf_cmd_wait_n_7e((int)v4);
    if ( v4[0] == 255 || v4[1] == 255 )
    {
      dispatch_event_handler_1(aNoCountrycodeI);
      return 0;
    }
    else
    {
      dispatch_event_handler_1("getcc: %s\r\n", (const char *)v4);
      return 0;
    }
  }
}
