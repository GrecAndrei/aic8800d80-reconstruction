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

extern uint32_t dword_12B184;
extern uint32_t off_12B188;

// sub_12B150 @ 0x12b150, size 48 bytes
int  sub_12B150(int a1, int a2, int a3, int a4)
{
  int v5; // r4

  v5 = sub_12D0B0(2);
  sub_12EEF8(4, dword_12B184);
  if ( v5 )
    *((uint8_t *)off_12B188 + 11) = 1;
  else
    sub_12B708(1, a4);
  return 0;
}

