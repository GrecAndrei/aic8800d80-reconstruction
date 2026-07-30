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

extern uint32_t off_122794;
extern uint32_t off_122790;
extern uint32_t dword_1227A4;
extern uint32_t dword_1227A0;
extern uint32_t off_122798;
extern uint32_t off_12279C;

// sub_122744 @ 0x122744, size 76 bytes
char *sub_122744()
{
  int v0; // r4

  v0 = *(uint32_t *)off_122794 & 0x1800000;
  if ( **(int16_t **)off_122790 < 0 && v0 == 25165824 )
    sub_12F32C(dword_1227A4, dword_1227A0, 1308);
  sub_12D00C(v0);
  if ( *((uint8_t *)off_122798 + 18) )
    return (char *)sub_120FB8();
  else
    return sub_122654(*((char **)off_12279C + 8));
}

