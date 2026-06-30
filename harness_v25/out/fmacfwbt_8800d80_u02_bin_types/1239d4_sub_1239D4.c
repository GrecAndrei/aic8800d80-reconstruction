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

extern uint32_t off_123A18;
extern uint32_t off_123A1C;
extern uint32_t dword_123A24;
extern uint32_t dword_123A20;

// sub_1239D4 @ 0x1239d4, size 68 bytes
int  sub_1239D4(int a1, uint8_t *a2, int a3, int a4)
{
  int v7; // r0
  int v8; // r3

  if ( **(int16_t **)off_123A18 < 0 )
  {
    v7 = *a2;
    if ( HIBYTE(*(uint32_t *)off_123A1C) + 8 >= v7 )
      goto LABEL_3;
    sub_12F694(dword_123A24, dword_123A20, 1801);
  }
  v7 = *a2;
LABEL_3:
  sub_1218D4(v7);
  message_dispatch_n84(39, a4, a3, v8);
  return 0;
}

