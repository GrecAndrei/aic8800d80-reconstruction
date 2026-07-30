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

extern uint32_t off_121914;
extern uint32_t dword_121918;
extern uint32_t off_121910;
extern uint32_t off_12191C;
extern uint32_t off_121930;
extern uint32_t dword_121938;
extern uint32_t dword_121934;
extern uint32_t off_121920;
extern uint32_t off_121928;
extern uint32_t off_121924;
extern uint32_t dword_12192C;

// sub_1218B4 @ 0x1218b4, size 90 bytes
unsigned int sub_1218B4()
{
  int16_t **v0; // r0
  int v1; // r3
  int *v2; // r4
  int v3; // r2
  unsigned int result; // r0
  uint32_t *v5; // r2

  v0 = (int16_t **)off_121914;
  v1 = dword_121918;
  *(uint32_t *)off_121910 &= ~2u;
  v2 = (int *)off_12191C;
  v3 = **v0;
  *(uint32_t *)off_12191C = v1;
  if ( v3 < 0 && *(uint32_t *)off_121930 << 28 )
  {
    sub_12F49C(dword_121938, dword_121934, 472);
    v1 = *v2;
  }
  *(uint32_t *)off_121920 = v1 | v2[1];
  result = mmio_reg_bit_modify(0);
  v5 = off_121928;
  *(uint32_t *)off_121924 = dword_12192C;
  *v5 &= 0xFFFBFFFE;
  return result;
}

