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

// sub_1236C8 @ 0x1236c8, size 32 bytes
// Doc: sub_12236C8 [ipc]: Send 0x3a trace/debug message to host
// sub_12236C8 [ipc]: Send 0x3a trace/debug message to host
int  sub_1236C8(int a1, uint8_t *a2, int a3, int a4)
{
  sub_1285BC(*a2);
  sub_12CA10(58, a4, a3);
  return 0;
}

