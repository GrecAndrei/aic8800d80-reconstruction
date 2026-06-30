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

extern uint32_t off_126164;
extern uint32_t dword_126168;
extern uint32_t dword_12616C;
extern uint32_t dword_126170;

// sub_126104 @ 0x126104, size 94 bytes
// Doc: patch_apply_nc4 [patch]: Applies RF register patch (sets 0xf00000 bit mask and writes value)
// patch_apply_nc4 [patch]: Applies RF register patch (sets 0xf00000 bit mask and writes value)
int sub_126104()
{
  int v1; // r4
  int v2; // [sp+Ch] [bp-14h] BYREF
  uint16_t v3; // [sp+10h] [bp-10h]
  uint16_t v4; // [sp+12h] [bp-Eh]
  uint8_t v5; // [sp+14h] [bp-Ch]

  if ( (*(uint32_t *)off_126164 & 0x2000000) != 0 )
    return 0;
  sub_100200(&v2, 0, 0xAu);
  v1 = sub_114880((int)&v2);
  msg_parse(dword_126168, v1);
  if ( v1 )
    msg_parse(dword_12616C);
  else
    msg_parse(dword_126170, (uint16_t)v2, HIWORD(v2), v3, v4, v5);
  return 0;
}

