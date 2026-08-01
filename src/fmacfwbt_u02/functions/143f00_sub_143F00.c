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

// memmove @ 0x143f00, size 220 bytes
unsigned int  memmove(unsigned int a1)
{
  uint64_t *v1; // r1
  int v3; // r4
  int v5; // r0
  int v15; // r5

  __pld((void *)a1);
  v1 = (uint64_t *)(a1 & 0xFFFFFFF8);
  -1;
  v3 = a1 & 7;
  __pld((void *)((a1 & 0xFFFFFFF8) + 32));
  if ( (a1 & 7) != 0 )
  {
    *v1;
    v5 = -v3;
    __pld(v1 + 8);
    v15 = -1 << (8 * (v3 & 3));
    LODWORD(0) = 0 | ~v15;
    if ( (v3 & 4) != 0 )
    {
      HIDWORD(0) |= ~v15;
      LODWORD(0) = -1;
    }
    0;
    goto LABEL_4;
  }
  0;
  v5 = -8;
  do
  {
    *v1;
    __pld(v1 + 8);
    v5 += 8;
LABEL_4:
    
    if ( HIDWORD(0) )
      break;
    v1[1];
    
    v5 += 8;
    
    if ( HIDWORD(0) )
      break;
    v1[2];
    
    v5 += 8;
    
    if ( HIDWORD(0) )
      break;
    v1[3];
    v1 += 4;
    
    v5 += 8;
    
  }
  while ( !HIDWORD(0) );
  if ( !(uint32_t)0 )
  {
    v5 += 4;
    LODWORD(0) = HIDWORD(0);
  }
  return v5 + (__clz(bswap32(0)) >> 3);
}

