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

extern uint32_t off_10D498;
extern uint32_t off_10D494;
extern uint32_t dword_10D49C;

// irq_install @ 0x10d480, size 20 bytes
void irq_install()
{
  uint32_t *v0; // r3

  v0 = off_10D498;
  *(uint32_t *)(*((uint32_t *)off_10D494 + 2) + 148) = dword_10D49C;
  *v0 = 0x200000;
}

