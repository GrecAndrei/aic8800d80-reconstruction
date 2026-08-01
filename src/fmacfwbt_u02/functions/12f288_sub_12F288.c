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

extern uint32_t off_12F2E4;
extern uint32_t dword_12F2E8;
extern uint32_t off_12F2EC;

// rf_command_start @ 0x12f288, size 90 bytes
int rf_command_start()
{
  uint8_t *v0; // r5
  int v1; // r0
  int v2; // r4

  v0 = off_12F2E4;
  v1 = irq_lock(1070, 1);
  v2 = (char)v0[1];
  if ( v2 == 1 )
  {
    sub_123058C();
    patch_aware_dispatch(1070, 1, dword_12F2E8);
    v0[1] = 2;
    return 0;
  }
  else
  {
    if ( v2 == 2 )
    {
      rf_calibrate_value(v1);
      patch_aware_dispatch(1070, 1, 1000 * *((uint32_t *)off_12F2EC + 91));
      v0[1] = 1;
    }
    return 0;
  }
}

