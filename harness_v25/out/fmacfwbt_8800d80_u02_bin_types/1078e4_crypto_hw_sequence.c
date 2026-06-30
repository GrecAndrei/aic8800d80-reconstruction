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

extern uint32_t off_107A84;
extern uint32_t off_107A88;
extern uint32_t off_107A8C;
extern uint32_t dword_107A90;
extern uint32_t off_107A9C;
extern uint32_t dword_107A94;
extern uint32_t dword_107A98;

// crypto_hw_sequence @ 0x1078e4, size 414 bytes
// Doc: crypto_hw_sequence [ke]: Runs hardware crypto sequence via MMIO register block
// crypto_hw_sequence [ke]: Runs hardware crypto sequence via MMIO register block
int  crypto_hw_sequence(int a1)
{
  uint32_t *v1; // r4
  uint32_t *v2; // r6
  int *v3; // r5
  int v4; // r7
  uint32_t *v5; // r11
  int v7; // r1
  int v8; // r3
  int v9; // cc
  int v10; // r2
  int v11; // r9
  int v12; // r1
  int result; // r0
  unsigned int v14; // [sp+20h] [bp-14h] BYREF
  unsigned int v15; // [sp+24h] [bp-10h]
  int v16; // [sp+28h] [bp-Ch]
  int v17; // [sp+2Ch] [bp-8h]

  v1 = off_107A84;
  v2 = off_107A88;
  v3 = (int *)off_107A8C;
  v4 = dword_107A90;
  v5 = off_107A9C;
  crypto_state_dump(a1);
  v7 = dword_107A94;
  *v1 |= 0x1000000u;
  *v1 |= 0x2000000u;
  feature_guard_sdio(1, v7);
  sub_107370();
  *v2 &= ~1u;
  delay_us(20);
  *v2 |= 4u;
  *v2 |= 8u;
  delay_us(20);
  *v1 |= 0x800000u;
  *v3 = *v3 & v4 | 0xC000000;
  delay_us(20);
  *v1 |= 0x4000000u;
  v8 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  v14 = v8;
  *v3 = *v3 & v4 | 0x4000000;
  delay_us(20);
  *v1 |= 0x4000000u;
  v15 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  v9 = v14 > v15;
  if ( v14 <= v15 )
    v10 = 234881024;
  else
    v10 = 100663296;
  *v3 = *v3 & v4 | v10;
  if ( v9 )
    v11 = 0x2000000;
  else
    v11 = 167772160;
  delay_us(20);
  *v1 |= 0x4000000u;
  v16 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  *v3 = *v3 & v4 | v11;
  delay_us(20);
  v12 = dword_107A98;
  *v1 |= 0x4000000u;
  v17 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  *v1 &= ~0x800000u;
  feature_guard_sdio(1, v12);
  result = crypto_power_calc(&v14, a1);
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 &= v4;
  *v1 &= ~0x1000000u;
  *v1 &= ~0x2000000u;
  return result;
}

