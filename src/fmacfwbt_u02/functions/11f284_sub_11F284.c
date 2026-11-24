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


extern uint32_t dword_11F47C;
extern uint32_t dword_11F480;
extern uint32_t dword_11F484;
extern uint32_t dword_11F490;
extern uint32_t dword_11F494;
extern uint32_t dword_11F49C;
extern uint32_t off_11F4A0;
extern uint32_t off_11F4A4;

// wlc_detach @ 0x11f284, size 504 bytes
int  wlc_detach(int *a1, uint8_t *a2)
{
  int v3; // r8
  uint32_t *v5; // r0
  uint32_t *v6; // r4
  int v7; // r7
  char *v8; // r2
  int v9; // r1
  int v10; // r3
  unsigned int v11; // r0
  char v12; // r3
  char v13; // r3
  int v14; // r0
  int v15; // r3
  int v16; // r2
  uint32_t *v17; // r2
  uint32_t *v18; // r3
  int v19; // r8
  int v20; // r1
  int v21; // r12
  int v22; // r2
  volatile unsigned int v23; // r2
  unsigned int v24; // r1
  unsigned int v25; // r2
  uint32_t *v26; // r3
  int v27; // r0
  int v28; // r2
  int v29; // r1
  uint32_t *v30; // r1
  unsigned int v31; // r3
  unsigned int v32; // r7
  volatile unsigned int v33; // r3
  uint32_t *v35; // r0
  char v36; // r1
  uint16_t v37; // r12
  uint16_t v38; // r3
  uint16_t v39; // r1
  uint16_t v40; // r3
  int v41; // r1

  v3 = *((uint8_t *)a1 + 25);
  v5 = list_pop_front(dword_11F47C);
  if ( !v5 )
    return 1;
  v6 = v5;
  if ( *((uint8_t *)a1 + 29) )
  {
    v35 = list_pop_front(dword_11F47C);
    if ( !v35 )
    {
      check_abort_flag(dword_11F47C, v6);
      return 1;
    }
    v6[11] = v35;
    v35[11] = v6;
    v36 = *((uint8_t *)a1 + 30);
    v8 = (char *)a1 + 18;
    v37 = *((uint8_t *)a1 + 29);
    *(uint32_t *)((char *)v35 + 38) = *(int *)((char *)a1 + 18);
    *((uint16_t *)v35 + 21) = *((uint16_t *)a1 + 11);
    v7 = dword_11F480;
    v38 = ((1 << v36) - 1) << 8;
    v39 = *((uint16_t *)v35 + 21) & ~v38;
    *((uint16_t *)v35 + 21) = v39;
    v40 = v38 & (*((uint16_t *)a1 + 11) - (v37 << 8)) | v39;
    v41 = dword_11F484 * (((int)v35 - v7) >> 3);
    *((uint16_t *)v35 + 21) = v40;
    *((uint8_t *)v35 + 35) = v41;
    *((uint16_t *)v35 + 16) = -1;
  }
  else
  {
    v7 = dword_11F480;
    v8 = (char *)a1 + 18;
  }
  v9 = *(uint32_t *)v8;
  v10 = *a1;
  *((uint16_t *)v6 + 21) = *((uint16_t *)v8 + 2);
  *(uint32_t *)((char *)v6 + 38) = v9;
  v6[1] = v10;
  v11 = *((uint8_t *)a1 + 24);
  v12 = dword_11F484;
  if ( v11 < 0x10 )
    LOBYTE(v11) = 16;
  *((uint8_t *)v6 + 28) = v11;
  *((uint16_t *)v6 + 10) = *((uint16_t *)a1 + 8);
  v6[4] = a1[2];
  v6[3] = a1[1];
  v6[6] = a1[3];
  v13 = v12 * (((int)v6 - v7) >> 3);
  *((uint8_t *)v6 + 34) = *((uint8_t *)a1 + 25);
  *a2 = v13;
  *((uint8_t *)v6 + 35) = v13;
  state_check_feature(256, aSStaIdxD, aStaMgmtRegiste);
  v14 = dword_11F490;
  v15 = dword_11F490 + 1320 * v3;
  v16 = *(uint8_t *)(v15 + 1224);
  v6[2] = 102400;
  if ( v16 )
    ++*(uint8_t *)(v15 + 1226);
  *((uint16_t *)v6 + 276) = -1;
  v17 = v6 + 138;
  v18 = v6;
  do
  {
    *((uint16_t *)v17 + 1) = -1;
    v17 = (uint32_t *)((char *)v17 + 2);
  }
  while ( v17 != (uint32_t *)((char *)v6 + 570) );
  v19 = 1320 * v3;
  v20 = (uint8_t)*a2;
  *((uint8_t *)v6 + 52) = 0;
  v21 = *(uint32_t *)(v14 + v19 + 1208);
  v6[84] = dword_11F494 + (v20 << 6);
  if ( (v21 & 8) != 0 )
    v22 = (int)(v6 + 46);
  else
    v22 = v19 + 1200;
  if ( (v21 & 8) == 0 )
    v22 += v14;
  v6[47] = v22;
  v23 = (*(volatile uint32_t *)0x40501010u);
  v24 = v23 - 1000000;
  v25 = v23 - 500000;
  do
  {
    v18[111] = v24;
    v18[112] = v25;
    v18 += 3;
  }
  while ( v6 + 27 != v18 );
  if ( (v21 & 0x10) != 0 )
    v6[1] |= 8u;
  check_abort_flag(v14 + v19 + 240, v6);
  v6[145] = dword_11F49C;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11F4A0 = 1;
  }
  v26 = off_11F4A4;
  v27 = v6[11];
  v28 = *(uint32_t *)off_11F4A4;
  v29 = *(uint32_t *)off_11F4A4 + 1;
  *(uint32_t *)off_11F4A4 = v29;
  *((uint8_t *)v6 + 37) = 1;
  if ( v27 )
    *(uint8_t *)(v27 + 37) = 1;
  if ( v29 )
  {
    v30 = off_11F4A0;
    *v26 = v28;
    if ( !v28 )
    {
      if ( *v30 )
        __enable_irq();
    }
  }
  v31 = (uint8_t)*a2;
  if ( v31 <= 0x23 )
  {
    v32 = v7 + 696 * v31;
    v33 = (*(volatile uint32_t *)0x40501010u);
    *(uint32_t *)(v32 + 664) = v33;
  }
  *((uint8_t *)v6 + 668) = 0;
  return 0;
}
