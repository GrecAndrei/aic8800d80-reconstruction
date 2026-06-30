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

extern uint32_t dword_13BDA0;

// sub_13BD60 @ 0x13bd60, size 64 bytes
// Doc: sub_123BD60 [util]: Builds a 16-bit control word with shift/and/or of args and constant 8
// sub_123BD60 [util]: Builds a 16-bit control word with shift/and/or of args and constant 8
int  sub_13BD60(char a1, int a2)
{
  int v2; // r4
  int v4; // r0
  int v5; // r1
  int v6; // r2

  v2 = a2;
  v4 = sub_12C92C(40, 0, ((uint16_t)a2 << 8) | 8, 8u);
  v5 = dword_13BDA0 + 32 * v2;
  v6 = *(uint8_t *)(v5 + 17);
  *(uint8_t *)(v4 + 1) = a1;
  *(uint8_t *)v4 = v6 != 1;
  *(uint8_t *)(v4 + 2) = *(uint8_t *)(v5 + 22);
  LOWORD(v2) = *(uint16_t *)(v5 + 20);
  *(uint16_t *)(v4 + 6) = *(uint16_t *)(v5 + 12);
  *(uint16_t *)(v4 + 4) = v2;
  return sdio_buffer_prepare_n_4e8(v4);
}

