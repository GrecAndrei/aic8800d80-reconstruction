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

extern uint32_t off_12BB5C;
extern uint32_t off_12BB60;
extern uint32_t off_12BB64;
extern uint32_t off_12BB68;
extern uint32_t dword_12BB6C;
extern uint32_t off_12BB74;
extern uint32_t dword_12BB7C;
extern uint32_t dword_12BB78;
extern uint32_t off_12BB70;

// sub_12BAEC @ 0x12baec, size 110 bytes
unsigned int sub_12BAEC()
{
  uint32_t *v0; // r2
  uint32_t *v1; // r0
  int16_t **v2; // r5
  int *v3; // r4
  int v4; // r3
  int16_t *v5; // r2
  unsigned int result; // r0
  uint32_t *v7; // r2

  v0 = off_12BB5C;
  v1 = off_12BB60;
  *(uint32_t *)off_12BB5C &= ~1u;
  v2 = (int16_t **)off_12BB64;
  v3 = (int *)off_12BB68;
  v4 = dword_12BB6C;
  *v0 &= ~2u;
  *v1 |= 0x700u;
  v5 = *v2;
  *v3 = v4;
  if ( *v5 < 0 && *(uint32_t *)off_12BB74 << 28 )
  {
    sub_12F35C(dword_12BB7C, dword_12BB78, 472);
    v4 = *v3;
  }
  *(uint32_t *)off_12BB70 = v4 | v3[1];
  result = sub_11DF40(1);
  v7 = off_12BB60;
  *(uint32_t *)off_12BB60 = *(uint32_t *)off_12BB60 & 0xFFFE3FFF | 0x10000;
  *v7 |= 0x2000u;
  return result;
}

