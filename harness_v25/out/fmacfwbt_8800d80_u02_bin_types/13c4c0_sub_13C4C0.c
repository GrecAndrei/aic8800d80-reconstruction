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

extern uint32_t dword_13C50C;
extern uint32_t off_13C508;
extern uint32_t dword_13C51C;
extern uint32_t dword_13C518;
extern uint32_t dword_13C510;
extern uint32_t off_13C514;

// sub_13C4C0 @ 0x13c4c0, size 70 bytes
int  sub_13C4C0(int a1, int a2)
{
  int result; // r0
  unsigned int v3; // r4

  result = 696 * a1 + 12 * a2 + dword_13C50C;
  v3 = *(uint8_t *)(result + 452);
  if ( **(int16_t **)off_13C508 < 0 && v3 > 0x20 )
    result = sub_12F694(dword_13C51C, dword_13C518, 1152);
  *(uint32_t *)(dword_13C510 + 32 * v3 + 8) = *((uint32_t *)off_13C514 + 4);
  return result;
}

