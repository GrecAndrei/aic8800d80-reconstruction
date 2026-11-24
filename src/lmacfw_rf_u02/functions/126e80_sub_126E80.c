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


extern uint32_t off_126EF8;
extern uint32_t off_126F08;

// rf_param_build @ 0x126e80, size 118 bytes
int rf_param_build()
{
  uint8_t *v0; // r4
  int v1; // r4
  int v2; // r0
  int a3; // [sp+14h] [bp-4h]

  v0 = (uint8_t *)off_126EF8;
  dispatch_event_handler_1(
    "temp_comp: init=%d, en=%d, lvl_cal=%d, t_last=%d C\n",
    *(char *)off_126EF8,
    *((char *)off_126EF8 + 1),
    *((char *)off_126EF8 + 2),
    *((char *)off_126EF8 + 3));
  dispatch_event_handler_1("xtal_cap: cal=0x%x, tgt=0x%x, cur=0x%x\n", v0[4], v0[5], v0[6]);
  dispatch_event_handler_1(
    "ofst2x: 2G4=%d,%d,%d; 5G=%d,%d,%d\n",
    (char)v0[8],
    (char)v0[9],
    (char)v0[10],
    (char)v0[11],
    (char)v0[12],
    (char)v0[13]);
  v1 = *(uint8_t *)(off_126F08 + 0x16B);
  a3 = *(uint32_t *)(off_126F08 + 0x16C);
  v2 = ke_task_retrieve(1070, 1);
  return dispatch_event_handler_1("settings: en=%d, tmr=%d, act=%d\n", v1, a3, v2);
}
