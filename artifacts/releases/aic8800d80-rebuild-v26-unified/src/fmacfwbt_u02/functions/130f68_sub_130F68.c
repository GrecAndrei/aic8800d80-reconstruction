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

extern uint32_t off_130FA8;

// sub_130F68 @ 0x130f68, size 64 bytes
int  sub_130F68(int a1, int a2, int16_t a3, char a4, int16_t a5)
{
  uint8_t *v5; // r4

  *(uint8_t *)(a1 + 2) = a4;
  *(uint8_t *)a1 = 3;
  v5 = off_130FA8;
  *(uint16_t *)(a1 + 3) = a5;
  *(uint8_t *)(a1 + 1) = 1;
  if ( !v5[371] )
    a3 &= ~1u;
  *(uint16_t *)(a1 + 5) = a3;
  if ( a5 )
  {
    *(uint8_t *)(a1 + 7) = 0;
    *(uint8_t *)(a1 + 8) = 0;
  }
  else
  {
    *(uint16_t *)(a1 + 7) = *(uint16_t *)(a2 + 14);
  }
  return 9;
}

