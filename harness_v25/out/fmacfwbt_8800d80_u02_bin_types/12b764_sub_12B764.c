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

extern uint32_t off_12B7AC;
extern uint32_t off_12B7B8;
extern uint32_t dword_12B7C0;
extern uint32_t dword_12B7BC;
extern uint32_t off_12B7B0;
extern uint32_t off_12B7B4;

// sub_12B764 @ 0x12b764, size 72 bytes
int sub_12B764()
{
  uint32_t *v0; // r4
  unsigned int v1; // r2
  int result; // r0

  if ( **(int16_t **)off_12B7AC < 0 && *(uint32_t *)off_12B7B8 << 28 )
    return sub_12F630(dword_12B7C0, dword_12B7BC, 105, *(uint32_t *)off_12B7B8);
  if ( (*(uint32_t *)off_12B7B0 & 0x80) != 0 )
  {
    v0 = off_12B7B4;
    v1 = *((uint32_t *)off_12B7B4 + 1) & 0xFFFFFFFB;
    *(uint32_t *)off_12B7B0 &= ~0x80u;
    v0[1] = v1;
    return irq_nesting_or(0x2000000);
  }
  return result;
}

