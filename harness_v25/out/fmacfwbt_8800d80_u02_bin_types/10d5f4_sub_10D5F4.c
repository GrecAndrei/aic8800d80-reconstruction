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

extern uint32_t off_10D604;
extern uint32_t off_10D608;

// sub_10D5F4 @ 0x10d5f4, size 14 bytes
int  sub_10D5F4(int result)
{
  while ( (*(uint32_t *)off_10D604 & 0x80000) != 0 )
    ;
  *(uint32_t *)off_10D608 = result;
  return result;
}

