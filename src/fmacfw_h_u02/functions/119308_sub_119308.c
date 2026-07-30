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

extern uint32_t off_119358;
extern uint32_t off_11935C;
extern uint32_t dword_119364;
extern uint32_t dword_119360;

// sub_119308 @ 0x119308, size 80 bytes
int16_t * sub_119308(int16_t *result)
{
  int v1; // r2
  int v2; // r1
  uint32_t *v3; // r4
  int v4; // r3

  v1 = *((uint32_t *)result + 19);
  if ( *(uint32_t *)(v1 + 28) )
  {
    v2 = *((uint32_t *)off_119358 + 43);
    v3 = result;
    result = *(int16_t **)off_11935C;
    do
    {
      v4 = v3[9] & 0x380000;
      *(uint32_t *)(*(uint32_t *)(v1 + 32) - 3) = v2;
      if ( v4 == 3670016 )
        break;
      v3 = (uint32_t *)*v3;
      if ( *result < 0 && !v3 )
      {
        sub_12F32C(dword_119364, dword_119360, 909);
        __und(0xFFu);
      }
      v1 = v3[19];
    }
    while ( *(uint32_t *)(v1 + 28) );
  }
  return result;
}

