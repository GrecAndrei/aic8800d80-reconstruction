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

extern uint32_t off_11AA80;
extern uint32_t off_11AA88;
extern uint32_t off_11AA84;

// sub_11AA5C @ 0x11aa5c, size 34 bytes
uint8_t * sub_11AA5C(uint8_t *result)
{
  unsigned int v1; // r2
  uint8_t *v2; // r3
  uint8_t *v3; // r4

  v1 = *result;
  if ( v1 <= 2 )
  {
    v2 = (uint8_t *)off_11AA80;
    v3 = off_11AA88;
    *(uint8_t *)off_11AA84 = v1;
    *v3 = v1;
    return (uint8_t *)sub_102E84(v2[36], v2[37], v1);
  }
  return result;
}

