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

extern uint32_t off_137094;
extern uint32_t off_137098;

// sub_137064 @ 0x137064, size 48 bytes
int sub_137064()
{
  uint8_t *v0; // r2
  char v1; // r3
  unsigned int v2; // r1

  v0 = off_137094;
  v1 = *((uint8_t *)off_137094 + 3851);
  if ( !v1 )
  {
    v2 = *((uint16_t *)off_137094 + 2);
    if ( v2 >= 7 )
      v2 = 7;
    *(uint32_t *)off_137098 = *(uint32_t *)off_137098 & 0xFFFFFE3F | (v2 << 6);
  }
  v0[3851] = v1 + 1;
  sub_13819C();
  return 0;
}

