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

extern uint32_t dword_124F98;
extern uint32_t dword_124F9C;
extern uint32_t dword_124FA8;
extern uint32_t dword_124FA0;
extern uint32_t off_124F94;
extern uint32_t dword_124FB0;
extern uint32_t dword_124FAC;
extern uint32_t dword_124FA4;

// sub_124EFC @ 0x124efc, size 152 bytes
int  sub_124EFC(int a1, int a2)
{
  int v4; // r5

  switch ( a2 )
  {
    case 2:
      v4 = dword_124F98;
      *(uint32_t *)(dword_124F9C + 20 * a1 + 4) = 0;
      break;
    case 3:
      v4 = dword_124F98;
      sub_12AA90(*(uint8_t *)(dword_124F98 + 1320 * a1 + 1225), dword_124FA8 + 38 * a1);
      break;
    case 1:
      v4 = dword_124F98;
      *(uint32_t *)(dword_124F9C + 20 * a1 + 4) = dword_124FA0 + 20 * a1;
      break;
    default:
      v4 = dword_124F98;
      if ( **(int16_t **)off_124F94 < 0 )
        sub_12F32C(dword_124FB0, dword_124FAC, 1214);
      break;
  }
  *(uint8_t *)(a1 + dword_124FA4 + 20) = 0;
  return sub_12AB58(*(uint8_t *)(v4 + 1320 * a1 + 1225), a2);
}

