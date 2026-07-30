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

extern uint32_t off_107ED8;
extern uint32_t off_107EDC;
extern uint32_t off_107EE0;

// sub_107E70 @ 0x107e70, size 104 bytes
int sub_107E70()
{
  uint32_t *v0; // r4
  uint32_t *v1; // r2
  int result; // r0
  uint32_t *v3; // r2
  int v4; // r3

  v0 = off_107ED8;
  sub_107518();
  *v0 &= ~1u;
  sub_100644(1);
  v1 = off_107EDC;
  *(uint32_t *)off_107EDC = *(uint32_t *)off_107EDC & 0xCFFFFFFF | 0x10000000;
  *v1 |= 0x40000000u;
  result = sub_100644(1);
  v3 = off_107EE0;
  *v0 |= 1u;
  *v0 |= 1u;
  while ( (*v3 & 1) == 0 )
  {
    LOWORD(v4) = 50;
    do
      v4 = (uint16_t)(v4 - 1);
    while ( v4 );
  }
  *(uint32_t *)off_107ED8 &= ~1u;
  return result;
}

