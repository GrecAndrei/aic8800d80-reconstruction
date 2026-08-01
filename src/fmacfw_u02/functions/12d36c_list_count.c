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

// read_u32 @ 0x12d36c, size 20 bytes
// Doc: read_u32 [util]: Return node count loaded from list head pointer (linked-list length helper)
// read_u32 [util]: Return node count loaded from list head pointer (linked-list length helper)
int  read_u32(uint32_t **a1)
{
  uint32_t *v1; // r3
  int result; // r0

  v1 = *a1;
  if ( !*a1 )
    return 0;
  result = 0;
  do
  {
    v1 = (uint32_t *)*v1;
    ++result;
  }
  while ( v1 );
  return result;
}

