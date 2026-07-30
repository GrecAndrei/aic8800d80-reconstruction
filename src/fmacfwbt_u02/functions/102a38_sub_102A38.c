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

extern uint32_t dword_102A64;
extern uint32_t dword_102A60;
extern uint32_t off_102A68;
extern uint32_t dword_102A70;
extern uint32_t dword_102A6C;

// sub_102A38 @ 0x102a38, size 38 bytes
int  sub_102A38(int a1, int a2, int a3)
{
  int result; // r0

  result = sub_12ECB0(dword_102A64, dword_102A60, a3);
  if ( **(int16_t **)off_102A68 < 0 )
    return sub_12F694(dword_102A70, dword_102A6C, 61);
  return result;
}

