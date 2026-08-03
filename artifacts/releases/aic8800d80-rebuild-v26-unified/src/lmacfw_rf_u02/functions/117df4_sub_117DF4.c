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

extern uint32_t off_117E50;
extern uint32_t dword_117E54;
extern uint32_t dword_117E58;

// sub_117DF4 @ 0x117df4, size 90 bytes
int sub_117DF4()
{
  uint8_t *v0; // r8
  int v1; // r4
  int v2; // r7
  int v3; // r6
  int result; // r0

  v0 = off_117E50;
  sub_100200((int *)off_117E50, 0, 0x14u);
  sub_11E71C(v0);
  v1 = dword_117E54;
  v2 = dword_117E58;
  sub_11E71C(v0 + 8);
  v3 = v1 + 896;
  do
  {
    sub_100200((int *)v1, 0, 0xE0u);
    *(uint8_t *)(v1 + 94) = 5;
    *(uint8_t *)(v1 + 97) = 127;
    *(uint32_t *)(v1 + 52) = v2;
    *(uint32_t *)(v1 + 56) = v1;
    v1 += 224;
    result = list_push_tail(v0);
  }
  while ( v1 != v3 );
  v0[16] = -1;
  return result;
}

