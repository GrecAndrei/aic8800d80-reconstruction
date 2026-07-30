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

extern uint32_t off_10DF00;
extern uint32_t dword_10DEE8;
extern uint32_t dword_10DEEC;
extern uint32_t dword_10DEF0;
extern uint32_t dword_10DEF4;
extern uint32_t dword_10DEF8;
extern uint32_t dword_10DEFC;

// sub_10DEA0 @ 0x10dea0, size 72 bytes
int sub_10DEA0()
{
  uint32_t *v0; // r3
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  int v4; // r0

  while ( *((uint32_t *)off_10DF00 + 7) != 1 )
    ;
  v0 = off_10DF00;
  *((uint32_t *)off_10DF00 + 7) = 1;
  v1 = sub_142A50(v0[4]);
  v2 = sub_142B44(v1, HIDWORD(v1), dword_10DEE8, dword_10DEEC);
  v3 = sub_142D98(v2, HIDWORD(v2), dword_10DEF0, dword_10DEF4);
  v4 = sub_1427D4(v3, HIDWORD(v3), dword_10DEF8, dword_10DEFC);
  return sub_143108(v4);
}

