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

extern uint32_t off_12188C;
extern uint32_t dword_121890;
extern uint32_t off_121888;
extern uint32_t off_121894;
extern uint32_t off_1218A8;
extern uint32_t dword_1218B0;
extern uint32_t dword_1218AC;
extern uint32_t off_121898;
extern uint32_t dword_1218A0;
extern uint32_t off_1218A4;
extern uint32_t off_12189C;

// sub_121834 @ 0x121834, size 84 bytes
unsigned int sub_121834()
{
  int16_t **v0; // r0
  int v1; // r3
  int *v2; // r4
  int v3; // r2
  unsigned int result; // r0
  int v5; // r1
  uint32_t *v6; // r2

  v0 = (int16_t **)off_12188C;
  v1 = dword_121890;
  *(uint32_t *)off_121888 |= 2u;
  v2 = (int *)off_121894;
  v3 = **v0;
  *(uint32_t *)off_121894 = v1;
  if ( v3 < 0 && *(uint32_t *)off_1218A8 << 28 )
  {
    sub_12F49C(dword_1218B0, dword_1218AC, 472);
    v1 = *v2;
  }
  *(uint32_t *)off_121898 = v1 | v2[1];
  result = mmio_reg_bit_modify(0);
  v5 = dword_1218A0;
  v6 = off_1218A4;
  *(uint32_t *)off_12189C = dword_1218A0;
  *v6 |= v5;
  return result;
}

