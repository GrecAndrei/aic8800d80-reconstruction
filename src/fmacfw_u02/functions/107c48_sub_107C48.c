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


extern uint32_t dword_107E00;
extern uint32_t off_107DEC;
extern uint32_t off_107DF0;
extern uint32_t off_107DF4;
extern uint32_t off_107DFC;

// rf_tx_cfg_write @ 0x107c48, size 418 bytes
int  rf_tx_cfg_write(int a1)
{
  uint32_t *v1; // r4
  uint32_t *v2; // r5
  int *v3; // r8
  int v4; // r9
  int *v5; // r6
  uint32_t *v6; // r10
  int *v8; // r5
  unsigned int v9; // r3
  int v10; // r3
  int v11; // r6
  int v12; // cc
  uint32_t *v13; // r4
  int v14; // r3
  int v15; // r11
  int v16; // r8
  int result; // r0
  uint32_t *v18; // r3
  unsigned int a1a; // [sp+18h] [bp-14h] BYREF
  unsigned int v20; // [sp+1Ch] [bp-10h]
  int v21; // [sp+20h] [bp-Ch]
  int v22; // [sp+24h] [bp-8h]

  v1 = off_107DEC;
  v2 = off_107DF0;
  v3 = (int *)off_107DFC;
  v4 = dword_107E00;
  v5 = (int *)off_107DF4;
  v6 = off_107DF4;
  timer_ticks_to_usec(a1);
  *v1 |= 0x1000000u;
  *v1 |= 0x2000000u;
  check_status_bits(1, aAdjQ);
  rf_synth_set_freq();
  *v2 &= ~1u;
  timer_delay(20);
  *v2 |= 4u;
  *v2 |= 8u;
  timer_delay(20);
  v8 = (int *)off_107DFC;
  *v1 |= 0x400000u;
  *v3 = *v3 & v4 | 0xC00;
  timer_delay(20);
  *v1 |= 0x4000000u;
  v9 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  a1a = v9;
  *v3 = *v3 & v4 | 0x400;
  timer_delay(20);
  *v1 |= 0x4000000u;
  v10 = *v5;
  v11 = dword_107E00;
  v20 = v10 & 0x7FFF;
  *v1 &= ~0x4000000u;
  v12 = a1a > v20;
  v13 = off_107DEC;
  if ( a1a > v20 )
    v14 = 1536;
  else
    v14 = 3584;
  *v8 = *v8 & v11 | v14;
  if ( v12 )
    v15 = 512;
  else
    v15 = 2560;
  v16 = v14;
  timer_delay(20);
  *v13 |= 0x4000000u;
  v21 = *v6 & 0x7FFF;
  *v13 &= ~0x4000000u;
  *v8 = *v8 & v11 | v15;
  timer_delay(20);
  *v13 |= 0x4000000u;
  v22 = *v6 & 0x7FFF;
  *v13 &= ~0x4000000u;
  *v13 &= ~0x400000u;
  check_status_bits(1, " [1]=%x %d\n [2]=%x %d\n [3]=%x %d\n[4]=%x %d\n", 3072, a1a, 1024, v20, v16, v21, v15, v22);
  result = sched_min_delta(&a1a, a1);
  v18 = off_107DF0;
  *(uint32_t *)off_107DF0 &= ~4u;
  *v18 &= ~8u;
  *v8 &= v11;
  *v13 &= ~0x1000000u;
  *v13 &= ~0x2000000u;
  return result;
}
