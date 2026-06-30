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

extern uint32_t dword_11CA10;
extern uint32_t off_11CA14;

// sub_11C9C8 @ 0x11c9c8, size 70 bytes
unsigned int * sub_11C9C8(unsigned int *result)
{
  int v1; // r2
  int v2; // r5
  unsigned int *v3; // r4
  uint64_t v4; // r6
  unsigned int *v5; // r0

  v1 = *(uint16_t *)(dword_11CA10 + 1320 * *((uint8_t *)result + 28) + 1222);
  if ( v1 != 1023 && *((uint8_t *)off_11CA14 + 361) != 2 )
  {
    v4 = *((uint64_t *)result + 9);
    v2 = dword_11CA10 + 1320 * *((uint8_t *)result + 28);
    v3 = (unsigned int *)(v4 + 64);
    LODWORD(v4) = v4 + 80;
    while ( 1 )
    {
      v5 = v3++;
      result = sub_11B510(v5, *(uint32_t *)(HIDWORD(v4) + 36), v1);
      if ( v3 == (unsigned int *)v4 )
        break;
      v1 = *(uint16_t *)(v2 + 1222);
    }
  }
  return result;
}

