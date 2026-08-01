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

extern uint32_t off_118D10;
extern uint32_t off_118D0C;
extern uint32_t dword_118D04;
extern uint32_t dword_118D08;
extern uint32_t off_118D14;
extern uint32_t off_118D18;
extern uint32_t off_118D20;
extern uint32_t off_118D24;
extern uint32_t off_118D1C;

// convert_handle_index @ 0x118c90, size 114 bytes
unsigned int  convert_handle_index(unsigned int result)
{
  int v1; // r3
  uint32_t *v2; // r1
  uint32_t *v3; // r2
  uint32_t *v4; // r2
  unsigned int *v5; // r1
  uint32_t *v6; // r5
  uint32_t *v7; // r4

  if ( result <= 0xF )
  {
    v3 = off_118D10;
    *(uint32_t *)off_118D0C = -1;
    *v3 = -1;
  }
  else
  {
    v1 = dword_118D04 + 152 * (uint8_t)(result - 16);
    if ( *(uint8_t *)(dword_118D08 + 224 * *(uint8_t *)(v1 + 32) + 94) == 2 )
      return result;
    v2 = off_118D10;
    *(uint32_t *)off_118D0C = *(uint16_t *)(v1 + 36) | (*(uint16_t *)(v1 + 38) << 16);
    *v2 = *(uint16_t *)(v1 + 40);
  }
  v4 = off_118D14;
  v5 = (unsigned int *)off_118D18;
  v6 = off_118D20;
  v7 = off_118D24;
  result = (result << 16) | 0x40000000;
  *(uint32_t *)off_118D1C = 0;
  *v6 = 0;
  *v4 = 0;
  *v7 = 0;
  *v5 = result;
  while ( (*v5 & 0x40000000) != 0 )
    ;
  return result;
}

