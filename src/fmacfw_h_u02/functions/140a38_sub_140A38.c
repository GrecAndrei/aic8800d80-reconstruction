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

// util_memcmp @ 0x140a38, size 116 bytes
int  util_memcmp(uint16_t *a1, int a2, int a3)
{
  int result; // r0
  int v6; // r2
  uint8_t *v7; // r0
  char *v8; // r5
  uint8_t v9; // [sp+4h] [bp-34h] BYREF
  char v10; // [sp+5h] [bp-33h] BYREF

  if ( !a3 )
    return 1;
  result = *(uint8_t *)(a3 + 50);
  if ( *(uint8_t *)(a3 + 50)
    || *(uint16_t *)(a3 + 52) == *a1
    && *(uint16_t *)(a3 + 54) == a1[1]
    && *(uint16_t *)(a3 + 56) == a1[2] )
  {
    v6 = *(uint8_t *)(a3 + 58);
    if ( !*(uint8_t *)(a3 + 58) )
      return 1;
    if ( !a2 )
      return 1;
    v9 = *(uint8_t *)(a2 + 1);
    if ( !v9 )
      return 0;
    v7 = &v9;
    v8 = (char *)(&v9 + v9);
    do
    {
      v7[1] = v7[a2 + 2 - (uint32_t)&v9];
      ++v7;
    }
    while ( v7 != (uint8_t *)v8 );
    return v9 == v6 && !memcmp(a3 + 59, &v10, v6);
  }
  return result;
}

