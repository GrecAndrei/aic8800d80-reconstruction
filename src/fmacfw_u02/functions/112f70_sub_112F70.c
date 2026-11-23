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


extern uint32_t dword_112FF0;
extern uint32_t dword_112FF4;
extern uint32_t dword_112FF8;
extern uint32_t dword_112FFC;
extern uint32_t dword_113004;
extern uint32_t dword_113008;
extern uint32_t dword_11300C;

// after_helper_call @ 0x112f70, size 126 bytes
int after_helper_call()
{
  int *v0; // r4
  uint8_t *v1; // r5
  int v2; // r2
  int v3; // r3
  volatile unsigned int v4; // r2
  unsigned int v5; // r2
  int v6; // r3
  uint16_t v7; // r1
  int result; // r0
  int v9; // r3
  int v10; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)dword_112FF0 = 1;
  }
  v0 = (int *)dword_112FF4;
  v1 = (uint8_t *)dword_112FF8;
  v2 = *(uint8_t *)dword_112FF8;
  v3 = *(uint32_t *)dword_112FF4 + 1;
  *(uint32_t *)dword_112FF4 = v3;
  if ( v2 )
  {
    *(uint32_t *)(dword_112FFC + 0x804) |= 1u;
    v4 = (*(volatile uint32_t *)0x40501010u);
    v5 = v4 + 9000;
    do
      v6 = v5 - (*(volatile uint32_t *)0x40501010u);
    while ( v6 >= 0 );
    v7 = *(uint16_t *)(dword_113004 + 0xB2);
    *(uint32_t *)(dword_112FFC + 0x804) &= ~1u;
    if ( (v7 & 0x4000) != 0 )
      result = sub_10D7B4(dword_113008);
    else
      result = sub_12EA88(dword_11300C);
    v3 = *v0;
    *v1 = 0;
  }
  if ( v3 )
  {
    v9 = v3 - 1;
    v10 = *(uint32_t *)dword_112FF0;
    *v0 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}
