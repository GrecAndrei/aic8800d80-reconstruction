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

extern uint32_t dword_1252FC;
extern uint32_t dword_125300;
extern uint32_t dword_12530C;
extern uint32_t dword_125304;
extern uint32_t off_1252F8;
extern uint32_t dword_125314;
extern uint32_t dword_125310;
extern uint32_t dword_125308;

// sub_125260 @ 0x125260, size 152 bytes
// Doc: sub_1225262_init [unknown]: Saves r4-r6,lr; moves args r0->r4, r1->r6; init stub
// sub_1225262_init [unknown]: Saves r4-r6,lr; moves args r0->r4, r1->r6; init stub
int  sub_125260(int a1, int a2)
{
  int v4; // r5

  switch ( a2 )
  {
    case 2:
      v4 = dword_1252FC;
      *(uint32_t *)(dword_125300 + 20 * a1 + 4) = 0;
      break;
    case 3:
      v4 = dword_1252FC;
      bt_link_lookup_entry(*(uint8_t *)(dword_1252FC + 1320 * a1 + 1225), dword_12530C + 38 * a1);
      break;
    case 1:
      v4 = dword_1252FC;
      *(uint32_t *)(dword_125300 + 20 * a1 + 4) = dword_125304 + 20 * a1;
      break;
    default:
      v4 = dword_1252FC;
      if ( **(int16_t **)off_1252F8 < 0 )
        sub_12F694(dword_125314, dword_125310, 1214);
      break;
  }
  *(uint8_t *)(a1 + dword_125308 + 20) = 0;
  return sub_12AEBC(*(uint8_t *)(v4 + 1320 * a1 + 1225), a2);
}

