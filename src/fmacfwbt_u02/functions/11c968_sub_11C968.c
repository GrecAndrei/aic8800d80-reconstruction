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

extern uint32_t off_11C988;
extern uint32_t off_11C984;
extern uint32_t dword_11C98C;

// configure_dma @ 0x11c968, size 26 bytes
int  configure_dma(int a1)
{
  uint32_t *v1; // r3
  int v2; // r1

  v1 = off_11C988;
  v2 = *((uint32_t *)off_11C984 + 4);
  *((uint32_t *)off_11C988 + 1) = dword_11C98C;
  v1[2] = a1;
  return ke_event_lock(v1, v2 + 5000);
}

