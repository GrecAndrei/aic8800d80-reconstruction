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

extern uint32_t off_11C548;
extern uint32_t off_11C544;
extern uint32_t dword_11C54C;

// sub_11C528 @ 0x11c528, size 26 bytes
int  sub_11C528(int a1)
{
  uint32_t *v1; // r3
  int v2; // r1

  v1 = off_11C548;
  v2 = *((uint32_t *)off_11C544 + 4);
  *((uint32_t *)off_11C548 + 1) = dword_11C54C;
  v1[2] = a1;
  return timestamp_update(v1, v2 + 5000);
}

