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
extern uint32_t dword_12C1D8;
extern uint32_t dword_12C1DC;
extern uint32_t dword_12C1E0;
extern uint32_t dword_12C1E8;
extern uint32_t dword_12C1EC;
extern uint32_t dword_12C1F0;
extern uint32_t dword_12C1F4;
extern uint32_t dword_12C1F8;

// rf_process_event @ 0x12c0a0, size 290 bytes
void  rf_process_event(int a1, int *a2)
{
  int v2; // r4
  uint32_t *v3; // r0
  uint32_t *v4; // r1
  int v5; // r2
  int v6; // r3
  uint32_t *v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r2
  unsigned int v10; // r3
  volatile unsigned int v11; // r2
  signed int v12; // r3
  uint32_t *v13; // r1
  uint32_t *v14; // r5
  signed int v15; // r3
  uint32_t *v16; // r4
  signed int v17; // r3
  signed int v18; // r3
  uint32_t *v19; // r4
  unsigned int v20; // r2
  int v21; // r3
  unsigned int v22; // r2
  unsigned int v23; // r0
  unsigned int v24; // r3
  int v25; // r6
  int v26; // r5
  int v27; // r2
  int v28; // r3
  unsigned int v29; // r0

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
      v25 = v5 | 0x5400;
      v26 = v6 | 0x500000;
      v27 = v5 | 0xFC00;
      v28 = v6 | 0xF00000;
      *(uint32_t *)dword_12C1CC = v25;
      *v3 = v27;
      *v4 = v26;
      v29 = dword_12C1F8;
      *v4 = v28;
      msg_parse(v29, v4, v27, v28);
    }
    else
    {
      v7 = (uint32_t *)dword_12C1D0;
      v8 = dword_12C1D8;
      v9 = v5 & 0xFFFF57FF;
      v10 = v6 & 0xFF5FFFFF;
      *(uint32_t *)dword_12C1CC = v9;
      *v7 = v10;
      msg_parse(v8, v7, v9, v10);
    }
  }
  if ( (v2 & 4) != 0 )
  {
    if ( (*(uint32_t *)dword_12C1DC & 1) != 0 )
    {
      *(uint32_t *)dword_12C1E0 |= 0x400000u;
      v11 = (*(volatile uint32_t *)0x40501010u);
      do
        v12 = v11 + 3 - (*(volatile uint32_t *)0x40501010u);
      while ( v12 >= 0 );
      v13 = (uint32_t *)dword_12C1EC;
      v14 = (uint32_t *)dword_12C1F0;
      *(uint32_t *)dword_12C1E8 = *(uint32_t *)dword_12C1E8 & 0xFFFE1FFF | 0xE000;
      *v13 |= 1u;
      *v14 = 0;
      do
        v15 = v11 + 4 - (*(volatile uint32_t *)0x40501010u);
      while ( v15 >= 0 );
      v16 = (uint32_t *)dword_12C1F0;
      *(uint32_t *)dword_12C1DC &= ~1u;
      *v16 = 1;
      do
        v17 = v11 + 5 - (*(volatile uint32_t *)0x40501010u);
      while ( v17 >= 0 );
      *(uint32_t *)dword_12C1F0 = 0;
      do
        v18 = v11 + 6 - (*(volatile uint32_t *)0x40501010u);
      while ( v18 >= 0 );
      v19 = (uint32_t *)dword_12C1F0;
      a2 = &REG_4050_1000;
      *(uint32_t *)dword_12C1DC |= 1u;
      v20 = v11 + 36;
      *v19 = 1;
      do
        v21 = v20 - (*(volatile uint32_t *)0x40501010u);
      while ( v21 >= 0 );
      v22 = dword_12C1E0;
      v23 = dword_12C1F4;
      v24 = *(uint32_t *)dword_12C1E0 & 0xFF9FFFFF;
      *(uint32_t *)dword_12C1E0 = v24;
    }
    else
    {
      v22 = dword_12C1EC;
      v23 = dword_12C1F4;
      v24 = *(uint32_t *)dword_12C1EC | 1;
      *(uint32_t *)dword_12C1EC = v24;
    }
    msg_parse(v23, a2, v22, v24);
  }
}
