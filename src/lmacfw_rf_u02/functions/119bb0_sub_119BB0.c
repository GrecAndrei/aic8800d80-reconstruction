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

// sub_119BB0 @ 0x119bb0, size 38 bytes
// Doc: rf_alloc_buf_0x34 [rf]: Allocate 0x34-byte RF buffer via helper, returns indexed handle
// rf_alloc_buf_0x34 [rf]: Allocate 0x34-byte RF buffer via helper, returns indexed handle
int  sub_119BB0(int a1, int a2, int a3, int a4)
{
  uint8_t *v5; // r4

  v5 = (uint8_t *)rf_setup_dispatch(52, a4, a3, 2);
  *v5 = sub_11BD44(a2, v5 + 1);
  sub_11DE50(v5);
  return 0;
}

