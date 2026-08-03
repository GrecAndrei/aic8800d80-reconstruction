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

extern uint32_t off_11DC10;

// sub_11DBF0 @ 0x11dbf0, size 30 bytes
int sub_11DBF0()
{
  uint8_t *v0; // r4
  unsigned int v1; // r2
  unsigned int v2; // r3
  int result; // r0

  v0 = off_11DC10;
  v1 = *((uint8_t *)off_11DC10 + 11);
  v2 = (uint8_t)(*((uint8_t *)off_11DC10 + 10) + 1);
  *((uint8_t *)off_11DC10 + 10) = v2;
  if ( v1 < v2 )
  {
    result = j_nullsub_6();
    v0[10] = 0;
  }
  return result;
}

