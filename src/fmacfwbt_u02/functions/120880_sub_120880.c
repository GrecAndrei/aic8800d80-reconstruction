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

extern uint32_t off_1208D4;
extern uint32_t dword_1208DC;
extern uint32_t off_1208D8;
extern uint32_t off_1208E8;
extern uint32_t dword_1208F0;
extern uint32_t dword_1208EC;
extern uint32_t off_1208E0;
extern uint32_t dword_1208E4;

// init_ctx_struct @ 0x120880, size 82 bytes
int init_ctx_struct()
{
  uint8_t *v0; // r4
  int v1; // r3
  int16_t *v2; // r1
  int v3; // r1
  int result; // r0

  v0 = off_1208D4;
  memset_byte((int *)off_1208D4, 0, 0x34u);
  v1 = dword_1208DC;
  v2 = *(int16_t **)off_1208D8;
  *(uint32_t *)v0 = dword_1208DC;
  v0[31] = 1;
  *((uint16_t *)v0 + 9) = 0;
  v3 = *v2;
  *((uint32_t *)v0 + 1) = 0;
  if ( v3 < 0 && *(uint32_t *)off_1208E8 << 28 )
  {
    mmio_field_update(dword_1208F0, dword_1208EC, 472);
    v1 = *(uint32_t *)v0 | *((uint32_t *)v0 + 1);
  }
  *(uint32_t *)off_1208E0 = v1;
  result = wait_rf_calibration();
  *((uint32_t *)v0 + 9) = dword_1208E4;
  return result;
}

