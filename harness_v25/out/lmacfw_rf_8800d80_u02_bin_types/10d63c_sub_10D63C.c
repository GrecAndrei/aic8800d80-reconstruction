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

extern uint32_t off_10D64C;
extern uint32_t off_10D650;

// sub_10D63C @ 0x10d63c, size 14 bytes
int  sub_10D63C(int result)
{
  while ( (*(uint32_t *)off_10D64C & 0x80000) != 0 )
    ;
  *(uint32_t *)off_10D650 = result;
  return result;
}

