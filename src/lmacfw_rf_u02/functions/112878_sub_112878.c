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


extern uint32_t dword_1128F8;
extern uint32_t dword_1128FC;
extern uint32_t dword_112900;
extern uint32_t dword_112904;
extern uint32_t dword_11290C;

// critical_section_enter @ 0x112878, size 126 bytes
int critical_section_enter()
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
    *(uint32_t *)dword_1128F8 = 1;
  }
  v0 = (int *)dword_1128FC;
  v1 = (uint8_t *)dword_112900;
  v2 = *(uint8_t *)dword_112900;
  v3 = *(uint32_t *)dword_1128FC + 1;
  *(uint32_t *)dword_1128FC = v3;
  if ( v2 )
  {
    *(uint32_t *)(dword_112904 + 0x804) |= 1u;
    v4 = (*(volatile uint32_t *)0x40501010u);
    v5 = v4 + 9000;
    do
      v6 = v5 - (*(volatile uint32_t *)0x40501010u);
    while ( v6 >= 0 );
    v7 = *(uint16_t *)(dword_11290C + 0xB2);
    *(uint32_t *)(dword_112904 + 0x804) &= ~1u;
    if ( (v7 & 0x4000) != 0 )
      result = (int)uart_tx_string(aUsbRmtwkup);
    else
      result = dispatch_event_handler_1(aUsbRmtwkup_0);
    v3 = *v0;
    *v1 = 0;
  }
  if ( v3 )
  {
    v9 = v3 - 1;
    v10 = *(uint32_t *)dword_1128F8;
    *v0 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}
