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

extern uint32_t dword_1019C8;
extern uint32_t dword_1019CC;
extern uint32_t off_1019C4;

// get_cached_1828f8 @ 0x10199c, size 40 bytes
// Doc: get_cached_1828f8 [util]: Retrieve cached pointer/value from 0x1828f8
// get_cached_1828f8 [util]: Retrieve cached pointer/value from 0x1828f8
uint64_t * get_cached_1828f8(uint64_t *result, int a2)
{
  uint64_t *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (uint64_t *)msg_parse(dword_1019C8, dword_1019CC, a2);
    *v2 = *(uint64_t *)((char *)off_1019C4 + 36);
  }
  else
  {
    *result = *(uint64_t *)((char *)off_1019C4 + 36);
  }
  return result;
}

