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

extern uint32_t off_114014;
extern uint32_t dword_114020;
extern uint32_t off_114018;
extern uint32_t off_11401C;
extern uint32_t dword_114024;

// sub_113FD4 @ 0x113fd4, size 64 bytes
int sub_113FD4()
{
  int v0; // r0
  uint32_t *v1; // r4
  int result; // r0

  v0 = (*(int ( **)(uint32_t))(*((uint32_t *)off_114014 + 2) + 16))(*((uint32_t *)off_114014 + 1));
  if ( !v0 )
    return sub_10DAE4(dword_114020);
  v1 = (uint32_t *)v0;
  result = sub_113210(*(uint32_t *)off_114018 + v0, *(uint32_t *)off_11401C);
  if ( result < 0 )
  {
    sub_10FEC8(v1);
    return sub_10DAE4(dword_114024);
  }
  return result;
}

