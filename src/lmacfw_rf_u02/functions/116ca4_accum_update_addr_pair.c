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

extern uint32_t off_116CD0;
extern uint32_t off_116CCC;

// timestamp_add @ 0x116ca4, size 38 bytes
// Doc: timestamp_add [util]: Add two 32-bit address pairs and store accumulator
// timestamp_add [util]: Add two 32-bit address pairs and store accumulator
int timestamp_add()
{
  uint32_t *v0; // r3
  uint64_t v1; // kr00_8
  uint64_t v2; // kr08_8

  v0 = off_116CD0;
  v1 = *((uint64_t *)off_116CCC + 17);
  v2 = *((uint64_t *)off_116CCC + 18);
  *((uint32_t *)off_116CD0 + 1) = HIDWORD(v1) + v1;
  v0[2] = v1;
  v0[3] = v2;
  v0[4] = HIDWORD(v2) + v2;
  *v0 = v1;
  v0[5] = v2;
  return event_count_update();
}

