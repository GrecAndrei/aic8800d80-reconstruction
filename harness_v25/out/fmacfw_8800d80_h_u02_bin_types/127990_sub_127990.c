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

extern uint32_t off_127A0C;
extern uint32_t off_127A08;
extern uint32_t dword_127A18;
extern uint32_t dword_127A14;
extern uint32_t off_127A10;

// sub_127990 @ 0x127990, size 118 bytes
int  sub_127990(int16_t *a1, int a2, char a3)
{
  uint8_t *v3; // r4
  int16_t v7; // r3
  uint8_t *v8; // r2

  v3 = off_127A0C;
  if ( **(int16_t **)off_127A08 < 0 && *((uint8_t *)off_127A0C + 108) != 255 )
    sub_12F32C(dword_127A18, dword_127A14, 2838);
  v3[108] = 3;
  *((uint16_t *)v3 + 49) = 255;
  v3[88] = *((uint8_t *)a1 + 2);
  v7 = *a1;
  *((uint16_t *)v3 + 46) = *a1;
  *((uint16_t *)v3 + 45) = v7;
  v8 = off_127A10;
  v3[96] = *((uint8_t *)a1 + 4);
  LOBYTE(v7) = v8[88];
  v3[97] = *((uint8_t *)a1 + 3);
  v8[88] = v7 | 2;
  v3[110] = a3;
  *((uint32_t *)v3 + 26) = a2;
  v3[100] = 1;
  return sub_127204();
}

