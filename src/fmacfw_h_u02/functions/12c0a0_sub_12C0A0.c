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


extern uint32_t dword_12C1C4;
extern uint32_t dword_12C1C8;
extern uint32_t dword_12C1CC;
extern uint32_t dword_12C1D0;
extern uint32_t dword_12C1D4;
extern uint32_t dword_12C1DC;
extern uint32_t dword_12C1E0;
extern uint32_t dword_12C1E8;
extern uint32_t dword_12C1EC;
extern uint32_t dword_12C1F0;

// rf_process_event @ 0x12c0a0, size 290 bytes
void  rf_process_event(int a1, int *a2)
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

  v2 = *(uint32_t *)dword_12C1C4 & *(uint32_t *)dword_12C1C8;
  *(uint32_t *)(dword_12C1C4 + 0xFFFFFFFC) = v2;
  if ( v2 << 30 )
  {
    v3 = (uint32_t *)dword_12C1CC;
    v4 = (uint32_t *)dword_12C1D0;
    v5 = *(uint32_t *)dword_12C1CC;
    v6 = *(uint32_t *)dword_12C1D0;
    if ( (v2 & 1) != 0 && !*(uint8_t *)(dword_12C1D4 + 0x24) )
    {
      *(uint32_t *)dword_12C1CC = v5 | 0x5400;
      *v3 = v5 | 0xFC00;
      *v4 = v6 | 0x500000;
      *v4 = v6 | 0xF00000;
      alloc_tx_event(aWf);
    }
    else
    {
      v7 = (uint32_t *)dword_12C1D0;
      *(uint32_t *)dword_12C1CC = v5 & 0xFFFF57FF;
      *v7 = v6 & 0xFF5FFFFF;
      alloc_tx_event(aBt);
    }
  }
  if ( (v2 & 4) != 0 )
  {
    if ( (*(uint32_t *)dword_12C1DC & 1) != 0 )
    {
      *(uint32_t *)dword_12C1E0 |= 0x400000u;
      v8 = (*(volatile uint32_t *)0x40501010u);
      do
        v9 = v8 + 3 - (*(volatile uint32_t *)0x40501010u);
      while ( v9 >= 0 );
      v10 = (uint32_t *)dword_12C1EC;
      v11 = (uint32_t *)dword_12C1F0;
      *(uint32_t *)dword_12C1E8 = *(uint32_t *)dword_12C1E8 & 0xFFFE1FFF | 0xE000;
      *v10 |= 1u;
      *v11 = 0;
      do
        v12 = v8 + 4 - (*(volatile uint32_t *)0x40501010u);
      while ( v12 >= 0 );
      v13 = (uint32_t *)dword_12C1F0;
      *(uint32_t *)dword_12C1DC &= ~1u;
      *v13 = 1;
      do
        v14 = v8 + 5 - (*(volatile uint32_t *)0x40501010u);
      while ( v14 >= 0 );
      *(uint32_t *)dword_12C1F0 = 0;
      do
        v15 = v8 + 6 - (*(volatile uint32_t *)0x40501010u);
      while ( v15 >= 0 );
      v16 = (uint32_t *)dword_12C1F0;
      *(uint32_t *)dword_12C1DC |= 1u;
      v17 = v8 + 36;
      *v16 = 1;
      do
        v18 = v17 - (*(volatile uint32_t *)0x40501010u);
      while ( v18 >= 0 );
      *(uint32_t *)dword_12C1E0 &= 0xFF9FFFFF;
      alloc_tx_event(aUnlock, &REG_4050_1000);
    }
    else
    {
      *(uint32_t *)dword_12C1EC |= 1u;
      alloc_tx_event(aUnlock, a2);
    }
  }
}
