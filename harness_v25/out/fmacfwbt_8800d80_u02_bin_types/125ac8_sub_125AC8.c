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

extern uint32_t off_125AE0;

// sub_125AC8 @ 0x125ac8, size 22 bytes
int  sub_125AC8(uint16_t *a1)
{
  if ( *((uint32_t *)off_125AE0 + 1) )
    return list_push_tail((char *)off_125AE0 + 12);
  else
    return sub_1254E8(a1);
}

