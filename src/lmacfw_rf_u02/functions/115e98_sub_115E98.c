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

extern uint32_t off_115F68;
extern uint32_t dword_115F74;
extern uint32_t off_115F6C;
extern uint32_t dword_115F70;

// rf_acquire @ 0x115e98, size 208 bytes
uint32_t *rf_acquire()
{
  uint8_t *v0; // r5
  int v1; // r8
  char *v2; // r7
  int *v3; // r4
  int v4; // r6
  int v5; // r9
  int *v6; // r6
  int v7; // r0
  int16_t v8; // r4
  int v9; // r2
  uint32_t *result; // r0
  uint32_t *v11; // r3
  int v12; // [sp+0h] [bp-24h] BYREF

  v0 = off_115F68;
  v1 = dword_115F74;
  enter_critical_section(1966080);
  v0[142] = 1;
  v2 = v0 + 12;
  v3 = &v12;
  v4 = 0;
  do
  {
    v5 = (uint8_t)v4;
    list_init(v3);
    wlan_hw_init((uint8_t)v4++, v1, v3);
    wlan_hw_init(v5, v2, v3);
    v1 += 8;
    v3 += 2;
    v2 += 28;
  }
  while ( v4 != 4 );
  v6 = (int *)off_115F6C;
  v7 = wlan_clk_init(5, off_115F6C, 0);
  clear_config_32(v7);
  v8 = *((uint16_t *)v0 + 70);
  sub_100200(v6 - 31, 0, 0x94u);
  *((uint16_t *)v0 + 70) = v8;
  list_init(v6 - 28);
  *(int *)((char *)v6 + 0xFFFFFF84) = 0;
  v0[26] = 0;
  list_init(v6 - 21);
  *((uint32_t *)v0 + 7) = 0;
  v0[54] = 0;
  list_init(v6 - 14);
  *((uint32_t *)v0 + 14) = 0;
  v0[82] = 0;
  list_init(v6 - 7);
  v9 = dword_115F70;
  *((uint32_t *)v0 + 21) = 0;
  v0[110] = 0;
  result = (uint32_t *)(v9 + 144);
  do
  {
    v11 = (uint32_t *)(v9 - 36);
    do
      *v11++ = 0;
    while ( v11 != (uint32_t *)v9 );
    v9 = (int)(v11 + 9);
  }
  while ( v11 + 9 != result );
  return result;
}

