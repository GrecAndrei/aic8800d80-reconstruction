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

extern uint32_t off_1305B8;

// sub_130590 @ 0x130590, size 38 bytes
int sub_130590()
{
  if ( *((uint8_t *)off_1305B8 + 1) )
    return *((char *)off_1305B8 + 3);
  sub_10DE48();
  return (int)COERCE_FLOAT(sub_10DEA0());
}

