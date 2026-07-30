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

extern uint32_t off_1237E4;
extern uint32_t off_1237E8;
extern uint32_t dword_1237F0;
extern uint32_t dword_1237EC;

// sub_1237A0 @ 0x1237a0, size 68 bytes
int  sub_1237A0(int a1, uint8_t *a2, int a3, int a4)
{
  int v7; // r0

  if ( **(int16_t **)off_1237E4 < 0 )
  {
    v7 = *a2;
    if ( HIBYTE(*(uint32_t *)off_1237E8) + 8 >= v7 )
      goto LABEL_3;
    sub_12F46C(dword_1237F0, dword_1237EC, 1801);
  }
  v7 = *a2;
LABEL_3:
  sub_121674(v7);
  sub_12CA10(39, a4, a3);
  return 0;
}

