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

extern uint32_t off_1005DC;
extern uint32_t off_1005D8;
extern uint32_t dword_1005E0;
extern uint32_t off_1005E4;

// hw_config_init @ 0x1005a4, size 50 bytes
// Doc: hw_config_init [rf]: Initialize RF hardware config (peripheral base, RF params)
// hw_config_init [rf]: Initialize RF hardware config (peripheral base, RF params)
int hw_config_init()
{
  int *v0; // r4
  int v1; // r5
  int result; // r0
  int16_t v3; // r2

  v0 = (int *)off_1005DC;
  v1 = sub_1004CC(HIBYTE(*(uint32_t *)off_1005D8) & 3);
  sub_100200(v0, 0, 8u);
  result = dword_1005E0 + 16 * v1;
  v3 = *(uint16_t *)(result + 6);
  *(uint32_t *)off_1005E4 = *(uint16_t *)(result + 4);
  *((uint8_t *)v0 + 1) = v3;
  *(uint8_t *)v0 = -1;
  return result;
}

