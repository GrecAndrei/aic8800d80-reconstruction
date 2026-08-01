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

extern uint32_t off_11DC34;
extern uint32_t off_11DC38;

// seq_count_restart @ 0x11dc14, size 30 bytes
// Doc: seq_count_restart [bt]: Reads byte flag from BT global state struct
// seq_count_restart [bt]: Reads byte flag from BT global state struct
int seq_count_restart()
{
  uint8_t *v0; // r4
  unsigned int *v1; // r2
  int v2; // r3
  int result; // r0

  v0 = off_11DC34;
  if ( *((uint8_t *)off_11DC34 + 10) )
    result = j_nullsub_6();
  v1 = (unsigned int *)off_11DC38;
  v2 = *(uint32_t *)off_11DC38;
  v0[10] = v0[11];
  *v1 = v2 & 0xFFFFFEFF;
  return result;
}

