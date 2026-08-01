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

extern uint32_t off_1151BC;
extern uint32_t dword_1151C0;
extern uint32_t off_1151C4;
extern uint32_t dword_1151C8;
extern uint32_t dword_1151CC;
extern uint32_t dword_1151D0;
extern uint32_t dword_1151FC;
extern uint32_t dword_115200;
extern uint32_t dword_1151F4;
extern uint32_t dword_1151F8;
extern uint32_t dword_1151F0;
extern uint32_t dword_1151E8;
extern uint32_t dword_1151D4;
extern uint32_t dword_1151D8;
extern uint32_t dword_1151EC;
extern uint32_t dword_1151DC;
extern uint32_t dword_1151E0;
extern uint32_t dword_1151E4;
extern uint32_t dword_115208;
extern uint32_t dword_11520C;
extern uint32_t dword_115210;
extern uint32_t dword_115204;

// apply_patch_table @ 0x114fec, size 464 bytes
int apply_patch_table()
{
  uint32_t *v0; // r7
  int v1; // r6
  int *v2; // r5
  int i; // r4
  int v4; // r1
  int v5; // t1
  uint32_t *v6; // r5
  unsigned int v7; // r4
  int v8; // r3
  int v9; // r1
  int v10; // r1
  unsigned int CPSR; // r2
  unsigned int v12; // r3
  int result; // r0
  int v14; // r4
  int v15; // r4
  int v16; // r7
  int v17; // r6
  unsigned int v18; // r4
  unsigned int v19; // r5
  int v20; // t1
  int v21; // r8
  int v22; // r6
  unsigned int v23; // r4
  unsigned int v24; // r5
  int v25; // t1
  unsigned int v26; // [sp+0h] [bp-18h]

  v0 = off_1151BC;
  v1 = dword_1151C0;
  v2 = (int *)off_1151BC;
  for ( i = 0; i != 13; ++i )
  {
    v4 = i;
    v5 = *v2++;
    debug_printf(v1, v4, v5);
  }
  v6 = off_1151C4;
  debug_printf(dword_1151C8, v0[13], v0[14], v0[15], v0[16], v0[17], v0[18]);
  debug_printf(dword_1151CC, *v6, v6[1], v6[2], v6[3]);
  debug_printf(dword_1151D0, v6[9], v6[10], v6[11], v6[12], v6[15]);
  v7 = v6[10];
  if ( (uint8_t)v7 )
  {
    debug_printf(
      dword_1151FC,
      (uint8_t)v6[10],
      v7 & 1,
      (v7 >> 1) & 1,
      (v7 >> 3) & 1,
      (v7 >> 4) & 1,
      (v7 >> 5) & 1,
      (v7 >> 7) & 1);
    if ( (v7 & 0x80) != 0 )
      debug_printf(dword_115200, v6[13]);
  }
  if ( (v7 & 0xFF00) != 0 )
  {
    debug_printf(
      dword_1151F4,
      BYTE1(v7),
      (v7 >> 8) & 1,
      (v7 >> 9) & 1,
      (v7 >> 10) & 1,
      (v7 >> 11) & 1,
      (v7 >> 12) & 1,
      (v7 >> 13) & 1,
      (v7 >> 15) & 1);
    if ( (v7 & 0x8000) != 0 )
      debug_printf(dword_1151F8, *((uint32_t *)off_1151C4 + 14));
  }
  if ( HIWORD(v7) )
    debug_printf(
      dword_1151F0,
      HIWORD(v7),
      HIWORD(v7) & 1,
      (v7 >> 17) & 1,
      (v7 >> 18) & 1,
      (v7 >> 19) & 1,
      HIBYTE(v7) & 1,
      (v7 >> 25) & 1);
  if ( (v0[19] & 8) == 0 )
  {
    debug_printf(dword_1151E8);
    goto LABEL_9;
  }
  debug_printf(dword_1151D4);
  if ( (v0[20] & 1) == 0 )
  {
LABEL_9:
    debug_printf(dword_1151D8);
    goto LABEL_10;
  }
  debug_printf(dword_1151EC);
LABEL_10:
  v8 = v0[19];
  v9 = v8 << 29;
  if ( (v8 & 4) != 0 )
    debug_printf(dword_1151DC, v9);
  else
    debug_printf(dword_1151E0, v9);
  v10 = v0[20];
  CPSR = __get_CPSR();
  v12 = __get_CPSR();
  v26 = __get_CPSR();
  result = debug_printf(dword_1151E4, v10, CPSR, v12, v26);
  v14 = v0[18];
  if ( v14 )
  {
    v21 = dword_115208;
    v22 = dword_11520C;
    v23 = v14 & 0xFFFFFFF0;
    debug_printf(dword_115210);
    v24 = v23 + 256;
    do
    {
      if ( !(v23 << 28) )
        debug_printf(v21, v23);
      v25 = *(uint32_t *)v23;
      v23 += 4;
      result = debug_printf(v22, v25);
    }
    while ( v24 != v23 );
  }
  v15 = v0[17];
  if ( v15 )
  {
    v16 = dword_115208;
    v17 = dword_11520C;
    v18 = v15 & 0xFFFFFFF0;
    debug_printf(dword_115204);
    v19 = v18 + 256;
    do
    {
      if ( !(v18 << 28) )
        debug_printf(v16, v18);
      v20 = *(uint32_t *)v18;
      v18 += 4;
      result = debug_printf(v17, v20);
    }
    while ( v19 != v18 );
  }
  return result;
}

