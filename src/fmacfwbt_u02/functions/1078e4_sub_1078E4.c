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


extern uint32_t dword_107A90;
extern uint32_t off_107A84;
extern uint32_t off_107A88;
extern uint32_t off_107A8C;
extern uint32_t off_107A9C;

// rf_configure_rx @ 0x1078e4, size 414 bytes
int  rf_configure_rx(int a1)
{
  uint32_t *v1; // r4
  uint32_t *v2; // r6
  int *v3; // r5
  int v4; // r7
  uint32_t *v5; // r11
  unsigned int v7; // r3
  int v8; // cc
  int v9; // r2
  int v10; // r3
  int v11; // r9
  int v12; // r10
  int result; // r0
  int v14; // [sp+1Ch] [bp-18h]
  unsigned int a1a; // [sp+20h] [bp-14h] BYREF
  unsigned int v16; // [sp+24h] [bp-10h]
  int v17; // [sp+28h] [bp-Ch]
  int v18; // [sp+2Ch] [bp-8h]

  v1 = off_107A84;
  v2 = off_107A88;
  v3 = (int *)off_107A8C;
  v4 = dword_107A90;
  v5 = off_107A9C;
  rf_load_tx_config(a1);
  *v1 |= 0x1000000u;
  *v1 |= 0x2000000u;
  state_check_feature(1, aAdjI);
  rf_set_frequency();
  *v2 &= ~1u;
  timer_set(20);
  *v2 |= 4u;
  *v2 |= 8u;
  timer_set(20);
  *v1 |= 0x800000u;
  *v3 = *v3 & v4 | 0xC000000;
  timer_set(20);
  *v1 |= 0x4000000u;
  v7 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  a1a = v7;
  *v3 = *v3 & v4 | 0x4000000;
  timer_set(20);
  *v1 |= 0x4000000u;
  v16 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  v8 = a1a > v16;
  if ( a1a <= v16 )
    v9 = 234881024;
  else
    v9 = 100663296;
  *v3 = *v3 & v4 | v9;
  if ( v8 )
    v10 = 1536;
  else
    v10 = 3584;
  if ( v8 )
    v11 = 0x2000000;
  else
    v11 = 167772160;
  if ( v8 )
    v12 = 512;
  else
    v12 = 2560;
  v14 = v10;
  timer_set(20);
  *v1 |= 0x4000000u;
  v17 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  *v3 = *v3 & v4 | v11;
  timer_set(20);
  *v1 |= 0x4000000u;
  v18 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  *v1 &= ~0x800000u;
  state_check_feature(1, " [1]=%x %d\n [2]=%x %d\n [3]=%x %d\n[4]=%x %d\n", 3072, a1a, 1024, v16, v14, v17, v12, v18);
  result = util_min_max(&a1a, a1);
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 &= v4;
  *v1 &= ~0x1000000u;
  *v1 &= ~0x2000000u;
  return result;
}
