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


extern uint32_t off_127160;
extern uint32_t off_127164;

// rf_enable_2 @ 0x127108, size 88 bytes
int rf_enable_2()
{
  uint8_t *v0; // r4
  int result; // r0
  int v2; // r0
  int v3; // r0
  int v4; // r2

  v0 = off_127160;
  *((uint8_t *)off_127160 + 1) = 1;
  result = ke_task_retrieve(1070, 1);
  if ( !result )
  {
    sdio_core_reset_alt();
    v2 = get_xtal_ftune();
    v0[6] = v2;
    rf_set_frequency_2(v2);
    v3 = (uint8_t)v0[5];
    if ( (uint8_t)v0[6] != v3 )
    {
      set_xtal_ftune(v3);
      v4 = (uint8_t)v0[5];
      v0[6] = v4;
      dispatch_event_handler_1("\x9D\x89adjust xtal_cap: tgt=0x%x, cur=0x%x\n", v4, v4);
    }
    return ke_event_loop(1070, 1, 1000 * *(uint32_t *)(off_127164 + 0x16C));
  }
  return result;
}
