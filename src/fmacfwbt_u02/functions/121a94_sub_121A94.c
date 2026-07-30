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

extern uint32_t off_121AEC;
extern uint32_t dword_121AF0;
extern uint32_t off_121AE8;
extern uint32_t off_121AF4;
extern uint32_t off_121B08;
extern uint32_t dword_121B10;
extern uint32_t dword_121B0C;
extern uint32_t off_121AF8;
extern uint32_t dword_121B00;
extern uint32_t off_121B04;
extern uint32_t off_121AFC;

// sub_121A94 @ 0x121a94, size 84 bytes
unsigned int sub_121A94()
{
  int16_t **v0; // r0
  int v1; // r3
  int *v2; // r4
  int v3; // r2
  unsigned int result; // r0
  int v5; // r1
  uint32_t *v6; // r2

  v0 = (int16_t **)off_121AEC;
  v1 = dword_121AF0;
  *(uint32_t *)off_121AE8 |= 2u;
  v2 = (int *)off_121AF4;
  v3 = **v0;
  *(uint32_t *)off_121AF4 = v1;
  if ( v3 < 0 && *(uint32_t *)off_121B08 << 28 )
  {
    sub_12F6C4(dword_121B10, dword_121B0C, 472);
    v1 = *v2;
  }
  *(uint32_t *)off_121AF8 = v1 | v2[1];
  result = sub_11E4C0(0);
  v5 = dword_121B00;
  v6 = off_121B04;
  *(uint32_t *)off_121AFC = dword_121B00;
  *v6 |= v5;
  return result;
}

