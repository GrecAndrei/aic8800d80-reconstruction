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

extern uint32_t off_1271E8;
extern uint32_t off_1271EC;
extern uint32_t dword_1271FC;
extern uint32_t dword_1271F8;
extern uint32_t dword_1271F0;
extern uint32_t dword_127200;
extern uint32_t dword_1271F4;

// sub_127160 @ 0x127160, size 134 bytes
int sub_127160()
{
  uint8_t *v0; // r4
  int v1; // r3
  int result; // r0

  v0 = off_1271E8;
  v1 = *((uint8_t *)off_1271E8 + 88);
  result = v1 << 31;
  if ( (v1 & 1) != 0 )
  {
    if ( **(int16_t **)off_1271EC < 0 && (v1 & 4) != 0 )
    {
      sub_12F32C(dword_1271FC, dword_1271F8, 1720);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xFA | 4;
    return sub_127030(dword_1271F0);
  }
  else if ( (v1 & 6) == 2 )
  {
    if ( **(int16_t **)off_1271EC < 0 && (v1 & 8) != 0 )
    {
      sub_12F32C(dword_127200, dword_1271F8, 1731);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xF5 | 8;
    return sub_127030(dword_1271F4);
  }
  return result;
}

