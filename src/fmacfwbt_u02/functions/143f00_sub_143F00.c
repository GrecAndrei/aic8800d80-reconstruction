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
uint32_t _R12;
uint64_t _R2;
uint64_t _R3;
uint32_t _R4;

  uint64_t *v1; // r1
  int v3; // r4
  int v5; // r0
  int v15; // r5

  __pld((void *)a1);
  v1 = (uint64_t *)(a1 & 0xFFFFFFF8);
  _R12 = -1;
  v3 = a1 & 7;
  __pld((void *)((a1 & 0xFFFFFFF8) + 32));
  if ( (a1 & 7) != 0 )
  {
    _R2 = *v1;
    v5 = -v3;
    __pld(v1 + 8);
    v15 = -1 << (8 * (v3 & 3));
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(_R2 | ~v15) & 0xFFFFFFFFULL) << 0);
    if ( (v3 & 4) != 0 )
    {
      _R2 = _R2 | (((uint64_t)(~v15)) << 32);
      _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(-1) & 0xFFFFFFFFULL) << 0);
    }
    _R4 = 0;
    goto LABEL_4;
  }
  _R4 = 0;
  v5 = -8;
  do
  {
    _R2 = *v1;
    __pld(v1 + 8);
    v5 += 8;
LABEL_4:
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | ((uint32_t)_R4 | __zmask32((uint32_t)_R2));
_R2 = (_R2 & 0xFFFFFFFFULL) | (((uint64_t)((uint32_t)_R2 | __zmask32((uint32_t)(_R2 >> 32)))) << 32);

    if ( HIDWORD(_R2) )
      break;
    _R2 = v1[1];
    (void)0;

    v5 += 8;
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | ((uint32_t)_R4 | __zmask32((uint32_t)_R2));
_R2 = (_R2 & 0xFFFFFFFFULL) | (((uint64_t)((uint32_t)_R2 | __zmask32((uint32_t)(_R2 >> 32)))) << 32);

    if ( HIDWORD(_R2) )
      break;
    _R2 = v1[2];
    (void)0;

    v5 += 8;
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | ((uint32_t)_R4 | __zmask32((uint32_t)_R2));
_R2 = (_R2 & 0xFFFFFFFFULL) | (((uint64_t)((uint32_t)_R2 | __zmask32((uint32_t)(_R2 >> 32)))) << 32);

    if ( HIDWORD(_R2) )
      break;
    _R2 = v1[3];
    v1 += 4;
    (void)0;

    v5 += 8;
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | ((uint32_t)_R4 | __zmask32((uint32_t)_R2));
_R2 = (_R2 & 0xFFFFFFFFULL) | (((uint64_t)((uint32_t)_R2 | __zmask32((uint32_t)(_R2 >> 32)))) << 32);

  }
  while ( !HIDWORD(_R2) );
  if ( !(uint32_t)_R2 )
  {
    v5 += 4;
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(HIDWORD(_R2)) & 0xFFFFFFFFULL) << 0);
  }
  return v5 + (__clz(bswap32(_R2)) >> 3);
}
