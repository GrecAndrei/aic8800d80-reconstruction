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


extern uint32_t dword_12C304;
extern uint32_t dword_12C308;
extern uint32_t dword_12C30C;
extern uint32_t dword_12C310;
extern uint32_t dword_12C314;
extern uint32_t dword_12C318;
extern uint32_t dword_12C31C;
extern uint32_t dword_12C320;
extern uint32_t dword_12C328;
extern uint32_t dword_12C32C;
extern uint32_t dword_12C330;
extern uint32_t dword_12C334;
extern uint32_t dword_12C338;

// ipc_lock_acquire @ 0x12c1e0, size 290 bytes
void ipc_lock_acquire()
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

  v0 = *(uint32_t *)dword_12C304 & *(uint32_t *)dword_12C308;
  *(uint32_t *)(dword_12C304 + 0xFFFFFFFC) = v0;
  if ( v0 << 30 )
  {
    v1 = (uint32_t *)dword_12C30C;
    v2 = (uint32_t *)dword_12C310;
    v3 = *(uint32_t *)dword_12C30C;
    v4 = *(uint32_t *)dword_12C310;
    if ( (v0 & 1) != 0 && !*(uint8_t *)(dword_12C314 + 0x24) )
    {
      *(uint32_t *)dword_12C30C = v3 | 0x5400;
      *v1 = v3 | 0xFC00;
      *v2 = v4 | 0x500000;
      v20 = dword_12C338;
      *v2 = v4 | 0xF00000;
      sub_12EA88(v20);
    }
    else
    {
      v5 = (uint32_t *)dword_12C310;
      v6 = dword_12C318;
      *(uint32_t *)dword_12C30C = v3 & 0xFFFF57FF;
      *v5 = v4 & 0xFF5FFFFF;
      sub_12EA88(v6);
    }
  }
  if ( (v0 & 4) != 0 )
  {
    if ( (*(uint32_t *)dword_12C31C & 1) != 0 )
    {
      *(uint32_t *)dword_12C320 |= 0x400000u;
      v7 = (*(volatile uint32_t *)0x40501010u);
      do
        v8 = v7 + 3 - (*(volatile uint32_t *)0x40501010u);
      while ( v8 >= 0 );
      v9 = (uint32_t *)dword_12C32C;
      v10 = (uint32_t *)dword_12C330;
      *(uint32_t *)dword_12C328 = *(uint32_t *)dword_12C328 & 0xFFFE1FFF | 0xE000;
      *v9 |= 1u;
      *v10 = 0;
      do
        v11 = v7 + 4 - (*(volatile uint32_t *)0x40501010u);
      while ( v11 >= 0 );
      v12 = (uint32_t *)dword_12C330;
      *(uint32_t *)dword_12C31C &= ~1u;
      *v12 = 1;
      do
        v13 = v7 + 5 - (*(volatile uint32_t *)0x40501010u);
      while ( v13 >= 0 );
      *(uint32_t *)dword_12C330 = 0;
      do
        v14 = v7 + 6 - (*(volatile uint32_t *)0x40501010u);
      while ( v14 >= 0 );
      v15 = (uint32_t *)dword_12C330;
      *(uint32_t *)dword_12C31C |= 1u;
      v16 = v7 + 36;
      *v15 = 1;
      do
        v17 = v16 - (*(volatile uint32_t *)0x40501010u);
      while ( v17 >= 0 );
      v18 = dword_12C334;
      *(uint32_t *)dword_12C320 &= 0xFF9FFFFF;
      sub_12EA88(v18);
    }
    else
    {
      v19 = dword_12C334;
      *(uint32_t *)dword_12C32C |= 1u;
      sub_12EA88(v19);
    }
  }
}
