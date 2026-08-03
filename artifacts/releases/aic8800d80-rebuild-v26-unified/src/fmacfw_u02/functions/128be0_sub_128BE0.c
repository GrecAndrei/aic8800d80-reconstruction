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

extern uint32_t dword_128C24;
extern uint32_t off_128C2C;
extern uint32_t off_128C28;
extern uint32_t off_128C30;
extern uint32_t dword_128C34;

// sub_128BE0 @ 0x128be0, size 66 bytes
int  sub_128BE0(int a1, int a2)
{
  int result; // r0
  uint8_t *v4; // r5
  int v5; // r3

  result = sub_128B2C(a1, a2, dword_128C24);
  if ( result )
  {
    v4 = off_128C2C;
    v5 = *((uint8_t *)off_128C28 + 2);
    *((uint8_t *)off_128C2C + 28) = 0;
    if ( v5 )
      *(uint32_t *)off_128C30 |= 0x80000000;
    if ( v4[8] )
      --v4[8];
    result = timestamp_remove(dword_128C34);
    v4[29] = 0;
    *(uint32_t *)(a1 + 4) &= 0xFFFFFDF9;
  }
  return result;
}

