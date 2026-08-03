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

extern uint32_t off_12B448;
extern uint32_t off_12B454;
extern uint32_t dword_12B45C;
extern uint32_t dword_12B458;
extern uint32_t off_12B44C;
extern uint32_t off_12B450;

// sub_12B400 @ 0x12b400, size 72 bytes
int sub_12B400()
{
  uint32_t *v0; // r4
  unsigned int v1; // r2
  int result; // r0

  if ( **(int16_t **)off_12B448 < 0 && *(uint32_t *)off_12B454 << 28 )
    return sub_12F2C8(dword_12B45C, dword_12B458, 105, *(uint32_t *)off_12B454);
  if ( (*(uint32_t *)off_12B44C & 0x80) != 0 )
  {
    v0 = off_12B450;
    v1 = *((uint32_t *)off_12B450 + 1) & 0xFFFFFFFB;
    *(uint32_t *)off_12B44C &= ~0x80u;
    v0[1] = v1;
    return sub_12CFC4(0x2000000);
  }
  return result;
}

