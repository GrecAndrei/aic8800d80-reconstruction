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

extern uint32_t off_128F80;
extern uint32_t off_128F7C;
extern uint32_t off_128F84;
extern uint32_t off_128F88;

// sub_128F58 @ 0x128f58, size 34 bytes
int  sub_128F58(int a1, int16_t a2)
{
  uint8_t *v2; // r2
  uint8_t *v3; // r3
  int v4; // zf
  int (*v5)(void); // r3

  v2 = off_128F80;
  v3 = *(uint8_t **)off_128F7C;
  *((uint16_t *)off_128F80 + 1) = a2;
  v4 = *v3 == 2;
  v5 = (int (*)(void))off_128F84;
  if ( !v4 && a1 )
    v5 = (int (*)(void))off_128F88;
  v2[8] = 0;
  return v5();
}

