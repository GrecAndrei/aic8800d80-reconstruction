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

extern uint32_t off_125F48;
extern uint32_t dword_125F54;
extern uint32_t dword_125F50;
extern uint32_t dword_125F4C;

// rf_status_check_bit @ 0x125ef0, size 88 bytes
// Doc: rf_status_check_bit [rf]: Check RF status register bit 0x02000000
// rf_status_check_bit [rf]: Check RF status register bit 0x02000000
int  rf_status_check_bit(int a1, int a2, int a3)
{
  uint8_t v4[8]; // [sp+4h] [bp-8h] BYREF

  if ( (*(uint32_t *)off_125F48 & 0x2000000) != 0 )
  {
    msg_parse(dword_125F54, dword_125F50, a3, HIBYTE(*(uint32_t *)off_125F48) & 2);
    return 0;
  }
  else
  {
    *(uint16_t *)v4 = 0;
    sub_114838((int)v4);
    if ( v4[0] == 255 || v4[1] == 255 )
    {
      msg_parse(dword_125F4C);
      return 0;
    }
    else
    {
      msg_parse(dword_125F54, v4);
      return 0;
    }
  }
}

