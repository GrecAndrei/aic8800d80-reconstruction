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

extern uint32_t dword_13C3F4;
extern uint32_t dword_13C3F8;
extern uint32_t dword_13C3FC;

// reset_tx_descriptor @ 0x13c3ac, size 72 bytes
int  reset_tx_descriptor(int a1)
{
  int v1; // r5
  int result; // r0
  int16_t v4; // r2
  int v5; // r3
  int v6; // zf

  v1 = *(uint32_t *)(a1 + 28);
  memset((int *)(v1 + 6), 0, 0x100u);
  result = 348;
  v4 = *(uint16_t *)(dword_13C3F4 + 2 * (*(uint8_t *)(a1 + 22) + 348 * *(uint8_t *)(a1 + 16)) + 316);
  *(uint8_t *)(v1 + 262) = 0;
  v5 = *(uint8_t *)(a1 + 20);
  *(uint16_t *)(v1 + 4) = v4;
  v6 = ((v5 - 1) & v5) == 0;
  *(uint8_t *)(v1 + 263) = v5;
  if ( ((v5 - 1) & v5) != 0 )
    v5 = dword_13C3F8;
  else
    *(uint8_t *)(v1 + 264) = v5 - 1;
  if ( v6 )
    v5 = dword_13C3FC;
  *(uint32_t *)v1 = v5;
  return result;
}

