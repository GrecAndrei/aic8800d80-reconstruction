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

extern uint32_t dword_114178;

// sub_114168 @ 0x114168, size 16 bytes
// Doc: sub_1214168 [util]: Store byte and branch helper
// sub_1214168 [util]: Store byte and branch helper
int  sub_114168(int a1, int a2, int a3)
{
  msg_parse(dword_114178, a2, a3);
  return rf_stream_start2_n3f6();
}

