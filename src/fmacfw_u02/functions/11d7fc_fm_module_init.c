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

extern uint32_t off_11D820;

// fm_module_init @ 0x11d7fc, size 34 bytes
// Doc: fm_module_init [util]: Initialize FMAC module subsystems
// fm_module_init [util]: Initialize FMAC module subsystems
int fm_module_init()
{
  uint8_t *v0; // r4
  int v1; // r0
  char v2; // r0

  v0 = off_11D820;
  sub_11DFF0();
  v1 = sub_12D240(v0);
  v2 = sub_12F530(v1) - 1;
  v0[11] = v2;
  v0[10] = v2;
  return rf_fault_dump_n_27c();
}

