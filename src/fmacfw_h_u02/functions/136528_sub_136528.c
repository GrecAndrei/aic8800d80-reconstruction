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

extern uint32_t off_13655C;
extern uint32_t off_136564;
extern uint32_t dword_136560;
extern uint32_t dword_136568;
extern uint32_t dword_13656C;

// sub_136528 @ 0x136528, size 52 bytes
uint32_t *sub_136528()
{
  if ( **(int16_t **)off_13655C >= 0 || !*((uint32_t *)off_136564 + 1) )
    return sub_12D100((uint32_t *)dword_136560);
  sub_12F32C(dword_136568, dword_13656C, 46);
  return sub_12D100((uint32_t *)dword_136560);
}

