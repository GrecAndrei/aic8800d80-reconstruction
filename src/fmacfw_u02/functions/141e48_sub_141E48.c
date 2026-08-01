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

extern uint32_t dword_141ECC;
extern uint32_t off_141ED0;

// timeout_handler @ 0x141e48, size 130 bytes
uint8_t * timeout_handler(int a1)
{
  int v2; // r5
  int16_t v3; // r3
  int v4; // r2
  uint8_t *result; // r0
  int v6; // r5
  uint64_t v7; // r2
  int i; // r8
  unsigned uint64_t v9; // r6
  unsigned uint64_t v10; // r0

  v2 = *(uint8_t *)(a1 + 47);
  fault_handler(a1 + 52);
  v3 = *(uint16_t *)a1;
  v4 = dword_141ECC;
  result = off_141ED0;
  *(uint16_t *)a1 &= ~8u;
  v6 = v4 + 1320 * v2;
  LOBYTE(v4) = result[1] - 1;
  *(uint32_t *)(v6 + 4) &= ~0x100u;
  result[1] = v4;
  if ( (v3 & 0x60) == 0x20 )
  {
    v7 = *(uint64_t *)(a1 + 24);
    for ( i = 1; ; i = (uint8_t)(i + 1) )
    {
      v9 = v7 - *(uint64_t *)(v6 + 40);
      LODWORD(v10) = util_unknown();
      if ( v9 >= v10 )
        break;
      v7 = *(uint64_t *)(a1 + 24) + *(unsigned int *)(a1 + 16);
      *(uint64_t *)(a1 + 24) = v7;
    }
    return (uint8_t *)ll_rx_window_calc(a1, i);
  }
  return result;
}

