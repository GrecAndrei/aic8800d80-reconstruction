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

// aeabi_dmul @ 0x127be4, size 158 bytes
unsigned int  aeabi_dmul(unsigned int a1, int a2)
{
  unsigned int v2; // r12
  int v3; // cf
  int v4; // cc
  int v5; // r3
  int v6; // r2
  unsigned int result; // r0
  unsigned int v8; // r2
  int v9; // zf
  unsigned int v10; // r0

  v3 = (unsigned int)(2 * a2) >= 0x70000000;
  v5 = 2 * a2 - 1879048192;
  v4 = (unsigned int)(2 * a2) > 0x70000000;
  if ( (unsigned int)(2 * a2) >= 0x70000000 )
  {
    v3 = (unsigned int)v5 >= 0x200000;
    v2 = 2 * a2 - 1881145344;
    v4 = (unsigned int)v5 > 0x200000;
  }
  if ( v3 )
    v4 = v2 < 0x1FC00000;
  if ( v4 )
  {
LABEL_7:
    v6 = 8 * a1;
    result = 4 * v5 + (8 * a1 >= 0x80000000) + (a2 & 0x80000000 | (a1 >> 29));
    if ( v6 == 0x80000000 )
      result &= ~1u;
    return result;
  }
  if ( (a2 & 0x40000000) == 0 )
  {
    if ( v5 < -48234496 )
      return a2 & 0x80000000;
    a2 |= 0x100000u;
    v8 = 24 - ((unsigned int)(v5 + 48234496) >> 21);
    v9 = a1 << (((unsigned int)(v5 + 48234496) >> 21) + 8) == 0;
    v10 = a1 >> v8;
    if ( !v9 )
      v10 |= 1u;
    a1 = v10 | ((a2 & 0x1FFFFF) << (((unsigned int)(v5 + 48234496) >> 21) + 8));
    v5 = 2 * ((a2 & 0x1FFFFFu) >> v8);
    goto LABEL_7;
  }
  if ( (2 * a2) >> 21 == -1 && a1 | (a2 << 12) )
    return 2143289344;
  else
    return a2 & 0x80000000 | 0x7F800000;
}

