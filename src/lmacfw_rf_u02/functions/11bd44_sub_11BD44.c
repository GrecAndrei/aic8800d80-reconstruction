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

extern uint32_t dword_11BD7C;
extern uint32_t dword_11BD84;
extern uint32_t dword_11BD80;

// env_get @ 0x11bd44, size 54 bytes
// Doc: sub_121BD44 [util]: LMAC RF helper: load constant and tail-call helper
// sub_121BD44 [util]: LMAC RF helper: load constant and tail-call helper
int  env_get(int a1, uint8_t *a2)
{
  int v4; // r0
  char v5; // r2
  int v6; // r1

  v4 = list_pop_front(dword_11BD7C);
  if ( !v4 )
    return 1;
  v5 = dword_11BD84 * ((v4 - dword_11BD80) >> 2);
  *(uint8_t *)(v4 + 24) = v5;
  *a2 = v5;
  v6 = *(uint32_t *)(a1 + 4);
  *(uint32_t *)(v4 + 4) = *(uint32_t *)a1;
  *(uint32_t *)(v4 + 8) = v6;
  *(uint16_t *)(v4 + 12) = *(uint16_t *)(a1 + 8);
  return 0;
}

