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

extern uint32_t off_121604;
extern uint32_t dword_121608;
extern uint32_t off_12160C;

// bt_set_reg_0x42e @ 0x1215a8, size 90 bytes
int bt_set_reg_0x42e()
{
  uint8_t *v0; // r5
  int v1; // r0
  int v2; // r4

  v0 = off_121604;
  v1 = ke_int_lock(1070, 1);
  v2 = (char)v0[1];
  if ( v2 == 1 )
  {
    jump_10de98();
    ke_event_loop(1070, 1, dword_121608);
    v0[1] = 2;
    return 0;
  }
  else
  {
    if ( v2 == 2 )
    {
      rf_set_frequency(v1);
      ke_event_loop(1070, 1, 1000 * *((uint32_t *)off_12160C + 91));
      v0[1] = 1;
    }
    return 0;
  }
}

