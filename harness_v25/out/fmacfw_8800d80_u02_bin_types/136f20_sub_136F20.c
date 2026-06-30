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

extern uint32_t off_136F48;
extern uint32_t dword_136F4C;

// sub_136F20 @ 0x136f20, size 40 bytes
// Doc: sub_1236F20 [mmio]: Performs MMIO writes via helper (likely RF register config)
// sub_1236F20 [mmio]: Performs MMIO writes via helper (likely RF register config)
int sub_136F20()
{
  uint16_t *v0; // r4
  int v1; // r0

  v0 = (uint16_t *)off_136F48;
  v1 = sub_12C92C(4107, *((uint16_t *)off_136F48 + 1924), 4, 1u);
  sdio_buffer_prepare_n_4e8(v1);
  feature_guard_check(8, dword_136F4C, v0[1924]);
  return 0;
}

