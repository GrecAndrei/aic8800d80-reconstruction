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

extern uint32_t dword_11904C;
extern uint32_t dword_119050;

// sub_118FD8 @ 0x118fd8, size 116 bytes
int  sub_118FD8(int a1, uint8_t *a2, uint8_t *a3)
{
  int v6; // r4
  int v8; // r8
  int v9; // r9
  int v10; // r3
  uint8_t *v11; // r8

  v6 = sub_117B4C((int *)a1, a2);
  if ( v6 )
    return v6;
  v8 = *(uint8_t *)(a1 + 25);
  v9 = dword_11904C + 152 * (uint8_t)*a2;
  *(uint8_t *)(v9 + 125) = 0;
  *(uint16_t *)(v9 + 126) = 0;
  *a3 = sub_11898C((uint8_t)*a2, v8);
  v10 = *(uint32_t *)(v9 + 44);
  if ( v10 )
    sub_11898C(*(uint8_t *)(v10 + 33), *(uint8_t *)(a1 + 25));
  v11 = (uint8_t *)(dword_119050 + 224 * v8);
  if ( v11[94] )
    return v6;
  v11[102] = *a2;
  v11[103] = *(uint8_t *)(a1 + 29);
  v11[104] = *(uint8_t *)(a1 + 30);
  return 0;
}

