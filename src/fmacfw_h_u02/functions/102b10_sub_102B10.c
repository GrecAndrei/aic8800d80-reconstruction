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

extern uint32_t dword_102B3C;
extern uint32_t dword_102B38;
extern uint32_t off_102B40;
extern uint32_t dword_102B48;
extern uint32_t dword_102B44;

// sub_102B10 @ 0x102b10, size 38 bytes
int  sub_102B10(int a1, int a2, int a3)
{
  int result; // r0

  result = sub_12E948(dword_102B3C, dword_102B38, a3);
  if ( **(int16_t **)off_102B40 < 0 )
    return sub_12F32C(dword_102B48, dword_102B44, 61);
  return result;
}

