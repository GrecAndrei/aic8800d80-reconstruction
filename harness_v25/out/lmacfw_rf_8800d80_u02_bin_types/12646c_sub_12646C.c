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

extern uint32_t dword_12647C;
extern uint32_t off_126478;

// sub_12646C @ 0x12646c, size 12 bytes
// Doc: sub_122646C [util]: Bitfield extract/shift helper (mask+shift primitive)
// sub_122646C [util]: Bitfield extract/shift helper (mask+shift primitive)
int  sub_12646C(char a1)
{
  int v2; // r0

  v2 = dword_12647C;
  *(uint8_t *)off_126478 = a1;
  return msg_parse(v2);
}

