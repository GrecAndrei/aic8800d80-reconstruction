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

extern uint32_t off_12A048;
extern uint32_t dword_12A054;
extern uint32_t dword_12A050;
extern uint32_t dword_12A04C;

// sub_12A000 @ 0x12a000, size 72 bytes
unsigned int  sub_12A000(int a1, uint32_t *a2, uint32_t *a3)
{
  int v6; // r3
  int v7; // r0

  if ( **(int16_t **)off_12A048 < 0 && !*(uint8_t *)(a1 + 1224) )
    sub_12F32C(dword_12A054, dword_12A050, 1311);
  v6 = dword_12A04C + 140 * *(uint8_t *)(a1 + 1225);
  *a2 = *(uint32_t *)(v6 + 128);
  v7 = *(uint32_t *)(v6 + 124);
  *a3 = v7;
  return (unsigned int)(v7 - *a2) >> 31;
}

