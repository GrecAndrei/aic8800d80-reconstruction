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

extern uint32_t dword_13AF7C;

// idx_struct_lookup @ 0x13af3c, size 64 bytes
// Doc: idx_struct_lookup [util]: Looks up per-index struct entry (stride 0x2b8) and dereferences member
// idx_struct_lookup [util]: Looks up per-index struct entry (stride 0x2b8) and dereferences member
int * idx_struct_lookup(int *result)
{
  int v1; // r5

  v1 = **(uint32_t **)(dword_13AF7C + 696 * *((uint8_t *)result + 29) + 188);
  if ( v1 )
  {
    if ( *(uint8_t *)(v1 + 96) == 1 )
      return sub_116174(
               (int)result,
               v1 + 80,
               result[18] - *((uint8_t *)result + 52) + 172,
               *((uint8_t *)result + 52) + *((uint16_t *)result + 24));
  }
  return result;
}

