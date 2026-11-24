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


extern uint32_t off_10D21C;
extern uint32_t off_10D220;

// callback_post @ 0x10d1fc, size 26 bytes
int  callback_post(int a1)
{
  int result; // r0
  uint32_t *v3; // r3

  result = event_dispatch("chan notify: %x\r\n", a1);
  v3 = off_10D220;
  *(uint32_t *)off_10D21C = a1;
  *v3 = 0x1000000;
  return result;
}
