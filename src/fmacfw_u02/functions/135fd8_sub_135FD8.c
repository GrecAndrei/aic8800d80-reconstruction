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

extern uint32_t dword_13601C;
extern uint32_t dword_136020;

// sub_135FD8 @ 0x135fd8, size 68 bytes
// Doc: sub_1235FD8 [mac]: Indexed table lookup and field copy from 0x18fb08 base
// sub_1235FD8 [mac]: Indexed table lookup and field copy from 0x18fb08 base
int  sub_135FD8(int a1, uint8_t *a2, int16_t a3, int16_t a4)
{
  uint16_t v5; // r7
  uint8_t *v8; // r0

  v5 = *((uint16_t *)a2 + 1);
  sub_143770(dword_13601C + (*a2 << 9), a2 + 4, v5);
  *(uint16_t *)(dword_136020 + 2 * *a2) = v5;
  v8 = (uint8_t *)sub_12C92C(7177, a4, a3, 2u);
  *v8 = 1;
  v8[1] = *a2;
  sdio_buffer_prepare_n_4e8((int)v8);
  return 0;
}

