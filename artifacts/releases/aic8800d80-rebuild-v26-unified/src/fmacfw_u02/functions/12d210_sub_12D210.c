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

extern uint32_t off_12D238;
extern uint32_t off_12D23C;

// sub_12D210 @ 0x12d210, size 40 bytes
int sub_12D210()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r3
  void *v2; // r1

  v0 = rx_queue_head_init();
  v1 = off_12D238;
  v2 = off_12D23C;
  *((uint32_t *)off_12D238 + 7) = v0;
  v1[3] = 0;
  v1[4] = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[9] = v2;
  return clear_flags(-1);
}

