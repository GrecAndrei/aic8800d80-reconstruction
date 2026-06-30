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

extern uint32_t off_117370;

// sub_11733C @ 0x11733c, size 52 bytes
BOOL  sub_11733C(int a1)
{
  if ( *((uint8_t *)off_117370 + 510) )
    return 0;
  if ( !sub_128744() )
    return 0;
  if ( *(uint8_t *)(a1 + 1224) )
    return sub_12A350(*(uint8_t *)(a1 + 1225)) != 0;
  return 1;
}

