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

extern uint32_t off_122BE0;
extern uint32_t off_122BDC;
extern uint32_t dword_122BE4;

// sub_122B9C @ 0x122b9c, size 64 bytes
int  sub_122B9C(int a1, uint8_t *a2, int a3, int a4)
{
  int v7; // r1
  uint8_t *v8; // r2
  BOOL v9; // r0

  if ( a2[1] != 255 )
    sub_13BBA8();
  v7 = *a2;
  v8 = off_122BE0;
  if ( *a2 )
    v7 = 1;
  v9 = a2[2] != 0;
  *(uint8_t *)off_122BDC = v9;
  *v8 = v7;
  sub_12E948(dword_122BE4, v7, v9);
  sub_12C8D0(100, a4, a3);
  return 0;
}

