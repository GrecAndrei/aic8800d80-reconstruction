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

extern uint32_t dword_137740;

// find_table_entry @ 0x1376f4, size 76 bytes
int  find_table_entry(uint16_t *a1, int a2)
{
  int v2; // r3
  int v3; // r4

  v2 = dword_137740;
  v3 = dword_137740 + 3840;
  do
  {
    while ( !*(uint8_t *)v2 )
    {
      if ( a2 )
      {
        *(uint8_t *)(v2 + 56) = 0x80;
        return v2;
      }
LABEL_3:
      v2 += 60;
      if ( v2 == v3 )
        return 0;
    }
    if ( *(uint16_t *)(v2 + 2) != *a1 || *(uint16_t *)(v2 + 4) != a1[1] )
      goto LABEL_3;
    if ( *(uint16_t *)(v2 + 6) == a1[2] )
      return v2;
    v2 += 60;
  }
  while ( v2 != v3 );
  return 0;
}

