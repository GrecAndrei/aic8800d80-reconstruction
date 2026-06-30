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

// sub_11930C @ 0x11930c, size 34 bytes
// Doc: sub_121930C [rf]: Unknown RF helper routine
// sub_121930C [rf]: Unknown RF helper routine
int  sub_11930C(int a1, int a2, int a3, int a4)
{
  uint8_t *v5; // r4

  v5 = (uint8_t *)rf_setup_dispatch(11, a4, a3, 3);
  *v5 = rf_dispatch_handler_n8(a2, v5 + 1, v5 + 2);
  return 0;
}

