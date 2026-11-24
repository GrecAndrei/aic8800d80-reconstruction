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


extern uint32_t dword_11D89C;
extern uint32_t dword_11D8A0;
extern uint32_t dword_11D8A4;
extern uint32_t dword_11D8A8;
extern uint32_t dword_11D8AC;
extern uint32_t dword_11D8B4;
extern uint32_t dword_11D8B8;
extern uint32_t dword_11D8C0;
extern uint32_t dword_11D8C4;
extern uint32_t dword_11D8C8;

// rf_cmd_clear @ 0x11d778, size 290 bytes
void  rf_cmd_clear(int a1, int a2)
{
  int v2; // r4
  uint32_t *v3; // r0
  uint32_t *v4; // r1
  int v5; // r2
  int v6; // r3
  uint32_t *v7; // r1
  volatile unsigned int v8; // r2
  signed int v9; // r3
  uint32_t *v10; // r1
  uint32_t *v11; // r5
  signed int v12; // r3
  uint32_t *v13; // r4
  signed int v14; // r3
  signed int v15; // r3
  uint32_t *v16; // r4
  unsigned int v17; // r2
  int v18; // r3

  v2 = *(uint32_t *)dword_11D89C & *(uint32_t *)dword_11D8A0;
  *(uint32_t *)(dword_11D89C + 0xFFFFFFFC) = v2;
  if ( v2 << 30 )
  {
    v3 = (uint32_t *)dword_11D8A4;
    v4 = (uint32_t *)dword_11D8A8;
    v5 = *(uint32_t *)dword_11D8A4;
    v6 = *(uint32_t *)dword_11D8A8;
    if ( (v2 & 1) != 0 && !*(uint8_t *)(dword_11D8AC + 0x24) )
    {
      *(uint32_t *)dword_11D8A4 = v5 | 0x5400;
      *v3 = v5 | 0xFC00;
      *v4 = v6 | 0x500000;
      *v4 = v6 | 0xF00000;
      dispatch_event_handler_1(aWf);
    }
    else
    {
      v7 = (uint32_t *)dword_11D8A8;
      *(uint32_t *)dword_11D8A4 = v5 & 0xFFFF57FF;
      *v7 = v6 & 0xFF5FFFFF;
      dispatch_event_handler_1(aBt);
    }
  }
  if ( (v2 & 4) != 0 )
  {
    if ( (*(uint32_t *)dword_11D8B4 & 1) != 0 )
    {
      *(uint32_t *)dword_11D8B8 |= 0x400000u;
      v8 = (*(volatile uint32_t *)0x40501010u);
      do
        v9 = v8 + 3 - (*(volatile uint32_t *)0x40501010u);
      while ( v9 >= 0 );
      v10 = (uint32_t *)dword_11D8C4;
      v11 = (uint32_t *)dword_11D8C8;
      *(uint32_t *)dword_11D8C0 = *(uint32_t *)dword_11D8C0 & 0xFFFE1FFF | 0xE000;
      *v10 |= 1u;
      *v11 = 0;
      do
        v12 = v8 + 4 - (*(volatile uint32_t *)0x40501010u);
      while ( v12 >= 0 );
      v13 = (uint32_t *)dword_11D8C8;
      *(uint32_t *)dword_11D8B4 &= ~1u;
      *v13 = 1;
      do
        v14 = v8 + 5 - (*(volatile uint32_t *)0x40501010u);
      while ( v14 >= 0 );
      *(uint32_t *)dword_11D8C8 = 0;
      do
        v15 = v8 + 6 - (*(volatile uint32_t *)0x40501010u);
      while ( v15 >= 0 );
      v16 = (uint32_t *)dword_11D8C8;
      *(uint32_t *)dword_11D8B4 |= 1u;
      v17 = v8 + 36;
      *v16 = 1;
      do
        v18 = v17 - (*(volatile uint32_t *)0x40501010u);
      while ( v18 >= 0 );
      *(uint32_t *)dword_11D8B8 &= 0xFF9FFFFF;
      dispatch_event_handler_1(aUnlock, REG_4050_1000);
    }
    else
    {
      *(uint32_t *)dword_11D8C4 |= 1u;
      dispatch_event_handler_1(aUnlock, a2);
    }
  }
}
