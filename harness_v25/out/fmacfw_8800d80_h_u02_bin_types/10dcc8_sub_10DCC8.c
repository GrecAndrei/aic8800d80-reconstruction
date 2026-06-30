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

extern uint32_t off_10DCDC;

// sub_10DCC8 @ 0x10dcc8, size 18 bytes
int sub_10DCC8()
{
  if ( *((uint8_t *)off_10DCDC + 369) )
    return sub_10DBC0(2);
  else
    return sub_10DBD4(2);
}

