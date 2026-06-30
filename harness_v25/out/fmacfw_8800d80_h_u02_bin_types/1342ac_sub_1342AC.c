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

extern uint32_t off_1342E0;
extern uint32_t off_1342E8;
extern uint32_t dword_1342E4;
extern uint32_t dword_1342EC;
extern uint32_t dword_1342F0;

// sub_1342AC @ 0x1342ac, size 52 bytes
uint32_t *sub_1342AC()
{
  if ( **(int16_t **)off_1342E0 >= 0 || !*((uint32_t *)off_1342E8 + 6) )
    return sub_12D100((uint32_t *)dword_1342E4);
  sub_12F32C(dword_1342EC, dword_1342F0, 132);
  return sub_12D100((uint32_t *)dword_1342E4);
}

