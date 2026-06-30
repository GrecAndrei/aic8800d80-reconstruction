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

extern uint32_t dword_131538;

// sub_131518 @ 0x131518, size 30 bytes
int  sub_131518(int a1, int a2, int16_t a3, int16_t a4)
{
  sub_143770(dword_131538, a2, 254);
  sub_12CA10(5123, a4, a3);
  return 0;
}

