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

extern uint32_t off_1291A4;
extern uint32_t off_1291A0;
extern uint32_t off_1291A8;
extern uint32_t off_1291AC;

// sub_12917C @ 0x12917c, size 34 bytes
int  sub_12917C(int a1, int16_t a2)
{
  uint8_t *v2; // r2
  uint8_t *v3; // r3
  int v4; // zf
  int (*v5)(void); // r3

  v2 = off_1291A4;
  v3 = *(uint8_t **)off_1291A0;
  *((uint16_t *)off_1291A4 + 1) = a2;
  v4 = *v3 == 2;
  v5 = (int (*)(void))off_1291A8;
  if ( !v4 && a1 )
    v5 = (int (*)(void))off_1291AC;
  v2[8] = 0;
  return v5();
}

