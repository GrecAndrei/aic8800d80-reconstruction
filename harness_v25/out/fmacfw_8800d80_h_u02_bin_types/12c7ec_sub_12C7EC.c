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

extern uint32_t off_12C840;
extern uint32_t dword_12C848;
extern uint32_t dword_12C844;

// sub_12C7EC @ 0x12c7ec, size 82 bytes
int  sub_12C7EC(int16_t a1, int16_t a2, int16_t a3, unsigned int a4)
{
  int v8; // r0
  int v9; // r4

  v8 = ((int ( *)(unsigned int))loc_12C9A4)(a4 + 12);
  v9 = v8;
  if ( **(int16_t **)off_12C840 < 0 && !v8 )
    sub_12F32C(dword_12C848, dword_12C844, 145);
  *(uint16_t *)(v9 + 4) = a1;
  *(uint16_t *)(v9 + 6) = a2;
  *(uint16_t *)(v9 + 8) = a3;
  *(uint16_t *)(v9 + 10) = a4;
  *(uint32_t *)v9 = 0;
  sub_100200((int *)(v9 + 12), 0, a4);
  return v9 + 12;
}

