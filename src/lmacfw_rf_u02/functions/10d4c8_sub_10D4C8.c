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

extern uint32_t off_10D4E0;
extern uint32_t off_10D4DC;
extern uint32_t off_10D4E4;

// panic_fatal @ 0x10d4c8, size 20 bytes
void panic_fatal()
{
  uint32_t *v0; // r3

  v0 = off_10D4E0;
  *(uint32_t *)(*((uint32_t *)off_10D4DC + 2) + 148) = off_10D4E4;
  *v0 = 0x200000;
}

