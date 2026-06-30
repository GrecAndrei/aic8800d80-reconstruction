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

extern uint32_t dword_122B54;
extern uint32_t off_122B50;
extern uint32_t dword_122B5C;
extern uint32_t dword_122B58;

// sub_122AF4 @ 0x122af4, size 92 bytes
int  sub_122AF4(int a1, uint8_t *a2, int a3, int a4)
{
  int v4; // r7
  int v6; // r5
  int v9; // r0

  v4 = dword_122B54;
  v6 = *a2;
  if ( **(int16_t **)off_122B50 < 0 && *(uint8_t *)(dword_122B54 + 1320 * v6 + 106) )
    sub_12F32C(dword_122B5C, dword_122B58, 2639);
  v9 = v4 + 1320 * v6;
  *(uint16_t *)(v9 + 112) = *((uint16_t *)a2 + 1);
  *(uint8_t *)(v9 + 114) = a2[4];
  sub_12C8D0(76, a4, a3);
  return 0;
}

