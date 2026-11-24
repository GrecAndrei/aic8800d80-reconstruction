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


extern uint32_t dword_115F70;
extern uint32_t dword_115F74;
extern uint32_t off_115F68;
extern uint32_t off_115F6C;

// rf_acquire @ 0x115e98, size 208 bytes
uint32_t *rf_acquire()
{
  uint8_t *v0; // r5
  int v1; // r8
  int v2; // r7
  int *v3; // r4
  int v4; // r6
  unsigned int v5; // r9
  int v6; // r6
  uint16_t v7; // r4
  int v8; // r2
  uint32_t *result; // r0
  uint32_t *v10; // r3
  int buf[9]; // [sp+0h] [bp-24h] BYREF

  v0 = off_115F68;
  v1 = dword_115F74;
  enter_critical_section_1(1966080);
  v0[142] = 1;
  v2 = (int)(v0 + 12);
  v3 = buf;
  v4 = 0;
  do
  {
    v5 = (uint8_t)v4;
    list_init_1(v3);
    wlan_hw_init((uint8_t)v4++, v1);
    wlan_hw_init(v5, v2);
    v1 += 8;
    v3 += 2;
    v2 += 28;
  }
  while ( v4 != 4 );
  v6 = off_115F6C;
  wlan_clk_init(5, off_115F6C);
  clear_config_32();
  v7 = *((uint16_t *)v0 + 70);
  memset_thunk((int *)(v6 - 124), 0, 0x94u);
  *((uint16_t *)v0 + 70) = v7;
  list_init_1((uint32_t *)(v6 - 112));
  *(uint32_t *)(v6 + 0xFFFFFF84) = 0;
  v0[26] = 0;
  list_init_1((uint32_t *)(v6 - 84));
  *((uint32_t *)v0 + 7) = 0;
  v0[54] = 0;
  list_init_1((uint32_t *)(v6 - 56));
  *((uint32_t *)v0 + 14) = 0;
  v0[82] = 0;
  list_init_1((uint32_t *)(v6 - 28));
  v8 = dword_115F70;
  *((uint32_t *)v0 + 21) = 0;
  v0[110] = 0;
  result = (uint32_t *)(v8 + 144);
  do
  {
    v10 = (uint32_t *)(v8 - 36);
    do
      *v10++ = 0;
    while ( v10 != (uint32_t *)v8 );
    v8 = (int)(v10 + 9);
  }
  while ( v10 + 9 != result );
  return result;
}
