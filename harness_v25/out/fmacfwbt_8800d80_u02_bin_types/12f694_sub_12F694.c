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

extern uint32_t dword_12F6BC;
extern uint32_t off_12F6B8;
extern uint32_t off_12F6C0;

// sub_12F694 @ 0x12f694, size 36 bytes
int  sub_12F694(int a1, int a2, int a3)
{
  int v4; // r0
  int result; // r0

  __disable_irq();
  v4 = dword_12F6BC;
  *(uint32_t *)off_12F6B8 = 0;
  result = sub_12ECB0(v4, a1, a2, a3 & 0xFFFFF);
  while ( *(uint32_t *)off_12F6C0 )
    ;
  return result;
}

