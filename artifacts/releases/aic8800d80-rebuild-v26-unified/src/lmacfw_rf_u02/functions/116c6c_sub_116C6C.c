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

extern uint32_t off_116C8C;
extern uint32_t off_116C90;

// sub_116C6C @ 0x116c6c, size 30 bytes
int sub_116C6C()
{
  uint8_t *v0; // r4
  unsigned int *v1; // r2
  int v2; // r3
  int result; // r0

  v0 = off_116C8C;
  if ( *((uint8_t *)off_116C8C + 10) )
    result = j_nullsub_6();
  v1 = (unsigned int *)off_116C90;
  v2 = *(uint32_t *)off_116C90;
  v0[10] = v0[11];
  *v1 = v2 & 0xFFFFFEFF;
  return result;
}

