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

extern uint32_t off_12D460;
extern uint32_t dword_12D464;

// state_init @ 0x12d438, size 40 bytes
int state_init()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r3
  int v2; // r1

  v0 = align_and_irq_lock();
  v1 = off_12D460;
  v2 = dword_12D464;
  *((uint32_t *)off_12D460 + 7) = v0;
  v1[3] = 0;
  v1[4] = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[9] = v2;
  return set_system_flag_2(-1);
}

