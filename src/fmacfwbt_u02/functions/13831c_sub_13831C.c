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

extern uint32_t dword_138374;

// sub_13831C @ 0x13831c, size 86 bytes
// Doc: sub_123831C [util]: Loads pointer from 0x192d84, accesses +0xf00 offset byte
// sub_123831C [util]: Loads pointer from 0x192d84, accesses +0xf00 offset byte
int  sub_13831C(uint16_t *a1)
{
  int v1; // r3
  int v2; // r1

  v1 = dword_138374;
  v2 = dword_138374 + 3840;
  while ( !*(uint8_t *)v1 )
  {
    v1 += 60;
    if ( v1 == v2 )
      return 0;
  }
  if ( *(uint16_t *)(v1 + 2) == *a1 )
    goto LABEL_7;
  while ( 1 )
  {
    v1 += 60;
    if ( v1 == v2 )
      break;
    if ( *(uint8_t *)v1 && *(uint16_t *)(v1 + 2) == *a1 )
    {
LABEL_7:
      if ( *(uint16_t *)(v1 + 4) == a1[1] && *(uint16_t *)(v1 + 6) == a1[2] )
        return v1;
    }
  }
  return 0;
}

