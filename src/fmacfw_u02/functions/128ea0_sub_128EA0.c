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

extern uint32_t off_128EE8;
extern uint32_t off_128EEC;
extern uint32_t off_128EF0;
extern uint32_t dword_128EF4;

// sub_128EA0 @ 0x128ea0, size 72 bytes
void sub_128EA0()
{
  uint8_t *v0; // r5
  unsigned int *v1; // r1
  int v2; // r2
  int v3; // r4
  int v4; // r6
  int v5; // r0

  v0 = off_128EE8;
  if ( !*((uint8_t *)off_128EE8 + 28) )
  {
    v1 = (unsigned int *)off_128EEC;
    v2 = *(uint32_t *)off_128EEC;
    v3 = *((uint32_t *)off_128EF0 + 2);
    *((uint8_t *)off_128EE8 + 8) = 0;
    *v1 = v2 & 0xFFFFFFFB;
    if ( v3 )
    {
      v4 = dword_128EF4;
      do
      {
        if ( !*(uint8_t *)(v3 + 106) )
        {
          if ( *(uint8_t *)(v3 + 108) )
          {
            v5 = *(uint8_t *)(v3 + 116);
            if ( v5 != 255 && !sub_118DC4(v5, v4, v3) )
              ++v0[8];
          }
        }
        v3 = *(uint32_t *)v3;
      }
      while ( v3 );
    }
  }
}

