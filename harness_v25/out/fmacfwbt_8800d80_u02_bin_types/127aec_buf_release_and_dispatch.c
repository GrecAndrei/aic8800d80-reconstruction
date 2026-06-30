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

// buf_release_and_dispatch @ 0x127aec, size 38 bytes
// Doc: buf_release_and_dispatch [util]: Releases object at offset 0x58 then dispatches a task via outer call
// buf_release_and_dispatch [util]: Releases object at offset 0x58 then dispatches a task via outer call
int  buf_release_and_dispatch(int a1)
{
  int v2; // r0
  int result; // r0

  v2 = sub_121BE4(*(uint32_t *)(a1 + 88));
  *(uint32_t *)(a1 + 88) = v2;
  result = rf_bus_reset_n_1b2_acf8(a1, v2);
  *(uint8_t *)(a1 + 85) = *(uint8_t *)(a1 + 85) & 0x9F | 0x20;
  return result;
}

