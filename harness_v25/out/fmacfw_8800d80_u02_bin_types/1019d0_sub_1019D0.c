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

extern uint32_t off_1019E4;
extern uint32_t dword_1019EC;
extern uint32_t dword_1019E8;

// sub_1019D0 @ 0x1019d0, size 18 bytes
int  sub_1019D0(int a1, int a2, int a3)
{
  int result; // r0

  if ( *(uint32_t *)off_1019E4 << 28 )
    return msg_parse(dword_1019EC, dword_1019E8, a3);
  return result;
}

