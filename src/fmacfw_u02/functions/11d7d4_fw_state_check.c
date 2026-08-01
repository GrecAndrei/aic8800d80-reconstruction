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

extern uint32_t off_11D7F4;
extern uint32_t off_11D7F8;

// rf_counter_get @ 0x11d7d4, size 30 bytes
// Doc: rf_counter_get [util]: Reads firmware state flag byte for status check
// rf_counter_get [util]: Reads firmware state flag byte for status check
int rf_counter_get()
{
  uint8_t *v0; // r4
  unsigned int *v1; // r2
  int v2; // r3
  int result; // r0

  v0 = off_11D7F4;
  if ( *((uint8_t *)off_11D7F4 + 10) )
    result = j_nullsub_6();
  v1 = (unsigned int *)off_11D7F8;
  v2 = *(uint32_t *)off_11D7F8;
  v0[10] = v0[11];
  *v1 = v2 & 0xFFFFFEFF;
  return result;
}

