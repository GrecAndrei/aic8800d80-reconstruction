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

extern uint32_t off_12198C;
extern uint32_t dword_1219A0;
extern uint32_t dword_12199C;
extern uint32_t off_121990;
extern uint32_t off_121994;
extern uint32_t off_121998;

// sub_121934 @ 0x121934, size 86 bytes
int sub_121934()
{
  if ( **(int16_t **)off_12198C < 0 && sub_12CD48(0) != 3 )
    sub_12F32C(dword_1219A0, dword_12199C, 1785);
  if ( *((uint8_t *)off_121990 + 31) && *((uint8_t *)off_121994 + 18) + *((uint8_t *)off_121994 + 17) <= 1 )
    return sub_12CBF4(0);
  *(uint32_t *)off_121998 = 48;
  return sub_12CBF4(0);
}

