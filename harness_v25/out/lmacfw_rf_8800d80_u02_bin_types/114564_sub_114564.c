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

// sub_114564 @ 0x114564, size 10 bytes
// Doc: sub_1214564 [unknown]: Unidentified helper at 0x1214564
// sub_1214564 [unknown]: Unidentified helper at 0x1214564
int  sub_114564(int a1)
{
  return rf_param_setup_44(1, a1, 4u);
}

