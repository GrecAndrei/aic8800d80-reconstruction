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

extern uint32_t off_121EFC;
extern uint32_t dword_121F18;
extern uint32_t dword_121F14;
extern uint32_t off_121F00;
extern uint32_t off_121F04;
extern uint32_t off_121F08;
extern uint32_t off_121F0C;
extern uint32_t off_121F10;

// fmacfwbt_sub_1221E68 @ 0x121e68, size 148 bytes
// Doc: fmacfwbt_sub_1221E68 [util]: Check/return firmware build version from signature word
// fmacfwbt_sub_1221E68 [util]: Check/return firmware build version from signature word
int fmacfwbt_sub_1221E68()
{
  int *v1; // r4
  int v2; // r3
  int v3; // r2

  if ( **(int16_t **)off_121EFC < 0 && (msg_get_value(0) == 3 || !msg_get_value(0)) )
    sub_12F694(dword_121F18, dword_121F14, 1862);
  if ( msg_get_value(0) == 2 )
  {
    *(uint32_t *)off_121F00 = 48;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_121F04 = 1;
    }
    v1 = (int *)off_121F08;
    ++*(uint32_t *)off_121F08;
    sub_12D374(0x2000000);
    if ( (*(uint32_t *)off_121F0C & 4) != 0 )
      *(uint32_t *)off_121F10 = 4;
    if ( *v1 )
    {
      v2 = *v1 - 1;
      v3 = *(uint32_t *)off_121F04;
      *v1 = v2;
      if ( !v2 )
      {
        if ( v3 )
          __enable_irq();
      }
    }
  }
  return rf_bus_mark_n_3b7(0);
}

