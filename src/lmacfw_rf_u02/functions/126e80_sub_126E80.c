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
extern uint32_t dword_126EFC;
extern uint32_t dword_126F00;
extern uint32_t dword_126F04;
extern uint32_t off_126F08;
extern uint32_t dword_126F0C;

// rf_param_build @ 0x126e80, size 118 bytes
// Doc: rf_level_apply_nc6 [rf]: Apply 9 signed RF level/IQ compensation values from a level table to chain 6 via rf_reg_write helper.
// rf_level_apply_nc6 [rf]: Apply 9 signed RF level/IQ compensation values from a level table to chain 6 via rf_reg_write helper.
int rf_param_build()
{
  uint8_t *v0; // r4
  int v1; // r4
  int v2; // r0
  int v4; // [sp+14h] [bp-4h]

  v0 = (uint8_t *)off_126EF8;
  dispatch_event_handler(
    dword_126EFC,
    *(char *)off_126EF8,
    *((char *)off_126EF8 + 1),
    *((char *)off_126EF8 + 2),
    *((char *)off_126EF8 + 3));
  dispatch_event_handler(dword_126F00, v0[4], v0[5], v0[6]);
  dispatch_event_handler(dword_126F04, (char)v0[8], (char)v0[9], (char)v0[10], (char)v0[11], (char)v0[12], (char)v0[13]);
  v1 = *((uint8_t *)off_126F08 + 363);
  v4 = *((uint32_t *)off_126F08 + 91);
  v2 = ke_task_retrieve(1070, 1);
  return dispatch_event_handler(dword_126F0C, v1, v4, v2);
}

