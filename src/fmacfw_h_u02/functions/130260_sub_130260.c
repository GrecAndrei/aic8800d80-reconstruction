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


extern uint32_t off_1302D8;
extern uint32_t off_1302E8;

// rf_tx_power_lookup @ 0x130260, size 118 bytes
int rf_tx_power_lookup()
{
  uint8_t *v0; // r4
  int v1; // r4
  int v2; // r0
  int v4; // [sp+14h] [bp-4h]

  v0 = (uint8_t *)off_1302D8;
  alloc_tx_event(
    "temp_comp: init=%d, en=%d, lvl_cal=%d, t_last=%d C\n",
    *(char *)off_1302D8,
    *((char *)off_1302D8 + 1),
    *((char *)off_1302D8 + 2),
    *((char *)off_1302D8 + 3));
  alloc_tx_event("xtal_cap: cal=0x%x, tgt=0x%x, cur=0x%x\n", v0[4], v0[5], v0[6]);
  alloc_tx_event(
    "ofst2x: 2G4=%d,%d,%d; 5G=%d,%d,%d\n",
    (char)v0[8],
    (char)v0[9],
    (char)v0[10],
    (char)v0[11],
    (char)v0[12],
    (char)v0[13]);
  v1 = HIBYTE(((uint32_t *)(uintptr_t)off_1302E8)[90]);
  v4 = ((uint32_t *)(uintptr_t)off_1302E8)[91];
  v2 = rf_get_state_1(1070, 1);
  return alloc_tx_event("settings: en=%d, tmr=%d, act=%d\n", v1, v4, v2);
}
