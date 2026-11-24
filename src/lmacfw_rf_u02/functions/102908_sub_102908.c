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


extern uint32_t dword_10293C;

// sub_102908 @ 0x102908, size 52 bytes
int  sub_102908(uint8_t *a1, int a2)
{
  int result; // r0
  int v4; // r1
  int v5; // r3

  if ( a2 )
    return sub_11F504("\x9B\x87%s: radio %d does not exist\n", aPhySetChannel, a2);
  sub_101E18(*a1, *((uint16_t *)a1 + 1), *((uint16_t *)a1 + 2), a1[1], a1[9], 0);
  result = *(uint32_t *)a1;
  v4 = *((uint32_t *)a1 + 1);
  v5 = dword_10293C;
  *(uint32_t *)dword_10293C = *(uint32_t *)a1;
  *(uint32_t *)(v5 + 4) = v4;
  *(uint16_t *)(v5 + 8) = *((uint16_t *)a1 + 4);
  return result;
}
