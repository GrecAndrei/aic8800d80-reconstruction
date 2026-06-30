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

extern uint32_t off_11EC5C;
extern uint32_t dword_11EC60;

// sub_11EC18 @ 0x11ec18, size 68 bytes
uint64_t *sub_11EC18()
{
  uint64_t *result; // r0
  uint64_t v1; // [sp+4h] [bp-20h] BYREF
  int v2; // [sp+Ch] [bp-18h]
  int v3; // [sp+10h] [bp-14h]
  int v4; // [sp+14h] [bp-10h]
  int v5; // [sp+18h] [bp-Ch]

  v2 = *(uint32_t *)off_11EC5C;
  v3 = *(uint32_t *)dword_11EC60;
  v4 = *(uint32_t *)(dword_11EC60 + 8 + 0xFFFFFFFC);
  v5 = *(uint32_t *)(dword_11EC60 + 8);
  result = sub_1018F0(&v1, 0);
  if ( (v2 & 0xF) == 2 )
    return (uint64_t *)sub_12F448(&v1);
  return result;
}

