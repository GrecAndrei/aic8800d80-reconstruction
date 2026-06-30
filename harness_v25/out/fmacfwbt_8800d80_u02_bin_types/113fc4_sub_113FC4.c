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

extern uint32_t dword_113FD4;

// sub_113FC4 @ 0x113fc4, size 16 bytes
// Doc: sub_1213FC4 [util]: Store byte field and save callee-saved regs
// sub_1213FC4 [util]: Store byte field and save callee-saved regs
int  sub_113FC4(int a1, int a2, int a3)
{
  sub_12ECB0(dword_113FD4, a2, a3);
  return sub_113F70();
}

