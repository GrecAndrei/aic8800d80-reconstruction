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

extern uint32_t off_101830;
extern uint32_t off_10187C;
extern uint32_t dword_101884;
extern uint32_t dword_101880;

// sub_1016A8 @ 0x1016a8, size 390 bytes
void __noreturn sub_1016A8()
{
  if ( **(int16_t **)off_101830 < 0
    && (uint8_t)BYTE2(*(uint32_t *)off_10187C) + 10 * (HIBYTE(*(uint32_t *)off_10187C) + 2) != 32 )
  {
    sub_12F32C(dword_101884, dword_101880, 6119);
  }
  sub_1006D8();
}

