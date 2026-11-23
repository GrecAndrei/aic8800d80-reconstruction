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
extern uint32_t dword_11D8B0;
extern uint32_t dword_11D8B4;
extern uint32_t dword_11D8B8;
extern uint32_t dword_11D8C0;
extern uint32_t dword_11D8C4;
extern uint32_t dword_11D8C8;
extern uint32_t dword_11D8CC;
extern uint32_t dword_11D8D0;

// rf_cmd_clear @ 0x11d778, size 290 bytes
void rf_cmd_clear()
{
  int v0; // r4
  uint32_t *v1; // r0
  uint32_t *v2; // r1
  int v3; // r2
  int v4; // r3
  uint32_t *v5; // r1
  unsigned int v6; // r0
  volatile unsigned int v7; // r2
  signed int v8; // r3
  uint32_t *v9; // r1
  uint32_t *v10; // r5
  signed int v11; // r3
  uint32_t *v12; // r4
  signed int v13; // r3
  signed int v14; // r3
  uint32_t *v15; // r4
  unsigned int v16; // r2
  int v17; // r3
  unsigned int v18; // r0
  unsigned int v19; // r0
  unsigned int v20; // r0

  v0 = *(uint32_t *)dword_11D89C & *(uint32_t *)dword_11D8A0;
  *(uint32_t *)(dword_11D89C + 0xFFFFFFFC) = v0;
  if ( v0 << 30 )
  {
    v1 = (uint32_t *)dword_11D8A4;
    v2 = (uint32_t *)dword_11D8A8;
    v3 = *(uint32_t *)dword_11D8A4;
    v4 = *(uint32_t *)dword_11D8A8;
    if ( (v0 & 1) != 0 && !*(uint8_t *)(dword_11D8AC + 0x24) )
    {
      *(uint32_t *)dword_11D8A4 = v3 | 0x5400;
      *v1 = v3 | 0xFC00;
      *v2 = v4 | 0x500000;
      v20 = dword_11D8D0;
      *v2 = v4 | 0xF00000;
      sub_11F504(v20);
    }
    else
    {
      v5 = (uint32_t *)dword_11D8A8;
      v6 = dword_11D8B0;
      *(uint32_t *)dword_11D8A4 = v3 & 0xFFFF57FF;
      *v5 = v4 & 0xFF5FFFFF;
      sub_11F504(v6);
    }
  }
  if ( (v0 & 4) != 0 )
  {
    if ( (*(uint32_t *)dword_11D8B4 & 1) != 0 )
    {
      *(uint32_t *)dword_11D8B8 |= 0x400000u;
      v7 = (*(volatile uint32_t *)0x40501010u);
      do
        v8 = v7 + 3 - (*(volatile uint32_t *)0x40501010u);
      while ( v8 >= 0 );
      v9 = (uint32_t *)dword_11D8C4;
      v10 = (uint32_t *)dword_11D8C8;
      *(uint32_t *)dword_11D8C0 = *(uint32_t *)dword_11D8C0 & 0xFFFE1FFF | 0xE000;
      *v9 |= 1u;
      *v10 = 0;
      do
        v11 = v7 + 4 - (*(volatile uint32_t *)0x40501010u);
      while ( v11 >= 0 );
      v12 = (uint32_t *)dword_11D8C8;
      *(uint32_t *)dword_11D8B4 &= ~1u;
      *v12 = 1;
      do
        v13 = v7 + 5 - (*(volatile uint32_t *)0x40501010u);
      while ( v13 >= 0 );
      *(uint32_t *)dword_11D8C8 = 0;
      do
        v14 = v7 + 6 - (*(volatile uint32_t *)0x40501010u);
      while ( v14 >= 0 );
      v15 = (uint32_t *)dword_11D8C8;
      *(uint32_t *)dword_11D8B4 |= 1u;
      v16 = v7 + 36;
      *v15 = 1;
      do
        v17 = v16 - (*(volatile uint32_t *)0x40501010u);
      while ( v17 >= 0 );
      v18 = dword_11D8CC;
      *(uint32_t *)dword_11D8B8 &= 0xFF9FFFFF;
      sub_11F504(v18);
    }
    else
    {
      v19 = dword_11D8CC;
      *(uint32_t *)dword_11D8C4 |= 1u;
      sub_11F504(v19);
    }
  }
}
