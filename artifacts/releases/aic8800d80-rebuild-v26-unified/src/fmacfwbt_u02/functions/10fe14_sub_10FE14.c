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

extern uint32_t off_10FE54;
extern uint32_t dword_10FE58;
extern uint32_t dword_10FE5C;

// sub_10FE14 @ 0x10fe14, size 62 bytes
uint32_t * sub_10FE14(char a1)
{
  uint32_t *v2; // r4

  if ( **(uint8_t **)off_10FE54 == 1 )
    v2 = (uint32_t *)sub_1102D8();
  else
    v2 = sub_10F980(dword_10FE58, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( sub_10FD8C((unsigned int)v2) )
  {
    *((uint8_t *)v2 - 1) = a1;
    return v2;
  }
  sub_10DA7C(dword_10FE5C, v2);
  return v2;
}

