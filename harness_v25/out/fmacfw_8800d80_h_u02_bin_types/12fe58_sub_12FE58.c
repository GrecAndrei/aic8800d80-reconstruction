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

extern uint32_t off_12FEB8;
extern uint32_t off_12FEBC;
extern uint32_t dword_12FEC0;
extern uint32_t dword_12FEC4;
extern uint32_t dword_12FEC8;
extern uint32_t dword_12FECC;
extern uint32_t dword_12FED0;
extern uint32_t dword_12FED4;

// sub_12FE58 @ 0x12fe58, size 94 bytes
int sub_12FE58()
{
  int *v0; // r4
  uint32_t *v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  sub_10D634();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12FEB8 = 1;
  }
  v0 = (int *)off_12FEBC;
  v1 = (uint32_t *)dword_12FEC0;
  ++*(uint32_t *)off_12FEBC;
  sub_12D100(v1);
  sub_12D100((uint32_t *)dword_12FEC4);
  sub_12D108(dword_12FEC0, (uint32_t *)dword_12FEC8);
  sub_12D108(dword_12FEC0, (uint32_t *)dword_12FECC);
  sub_12D108(dword_12FEC0, (uint32_t *)dword_12FED0);
  result = sub_12D108(dword_12FEC0, (uint32_t *)dword_12FED4);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_12FEB8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

