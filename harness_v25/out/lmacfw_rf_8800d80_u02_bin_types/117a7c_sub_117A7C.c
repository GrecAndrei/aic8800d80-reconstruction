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

extern uint32_t off_117AC0;
extern uint32_t dword_117AC4;

// sub_117A7C @ 0x117a7c, size 68 bytes
// Doc: sub_1217A7C [unknown]: Unknown firmware helper at 0x1217a7c
// sub_1217A7C [unknown]: Unknown firmware helper at 0x1217a7c
uint64_t *sub_117A7C()
{
  uint64_t *result; // r0
  uint64_t v1; // [sp+4h] [bp-20h] BYREF
  int v2; // [sp+Ch] [bp-18h]
  int v3; // [sp+10h] [bp-14h]
  int v4; // [sp+14h] [bp-10h]
  int v5; // [sp+18h] [bp-Ch]

  v2 = *(uint32_t *)off_117AC0;
  v3 = *(uint32_t *)dword_117AC4;
  v4 = *(uint32_t *)(dword_117AC4 + 8 + 0xFFFFFFFC);
  v5 = *(uint32_t *)(dword_117AC4 + 8);
  result = get_cached_1828f8(&v1, 0);
  if ( (v2 & 0xF) == 2 )
    return (uint64_t *)rf_cmd_dispatch_a84(&v1);
  return result;
}

