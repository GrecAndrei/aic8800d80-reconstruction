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

extern uint32_t off_127B4C;
extern uint32_t off_127B48;
extern uint32_t dword_127B58;
extern uint32_t dword_127B54;
extern uint32_t off_127B50;

// sub_127AD0 @ 0x127ad0, size 118 bytes
int  sub_127AD0(int16_t *a1, int a2, char a3)
{
  uint8_t *v3; // r4
  int16_t v7; // r3
  uint8_t *v8; // r2

  v3 = off_127B4C;
  if ( **(int16_t **)off_127B48 < 0 && *((uint8_t *)off_127B4C + 108) != 255 )
    sub_12F46C(dword_127B58, dword_127B54, 2838);
  v3[108] = 3;
  *((uint16_t *)v3 + 49) = 255;
  v3[88] = *((uint8_t *)a1 + 2);
  v7 = *a1;
  *((uint16_t *)v3 + 46) = *a1;
  *((uint16_t *)v3 + 45) = v7;
  v8 = off_127B50;
  v3[96] = *((uint8_t *)a1 + 4);
  LOBYTE(v7) = v8[88];
  v3[97] = *((uint8_t *)a1 + 3);
  v8[88] = v7 | 2;
  v3[110] = a3;
  *((uint32_t *)v3 + 26) = a2;
  v3[100] = 1;
  return sub_127344();
}

