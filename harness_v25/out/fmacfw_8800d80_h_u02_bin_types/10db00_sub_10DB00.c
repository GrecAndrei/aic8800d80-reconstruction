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

extern uint32_t off_10DB5C;
extern uint32_t dword_10DB60;

// sub_10DB00 @ 0x10db00, size 90 bytes
void sub_10DB00()
{
  uint32_t *v0; // r4
  unsigned int v1; // r3
  signed int v2; // r3
  int v3; // r6
  int v4; // r0
  unsigned int v5; // r2
  void ( *v6)(int); // r1

  v0 = off_10DB5C;
  v1 = *((uint32_t *)off_10DB5C + 8);
  if ( v1 )
  {
    v2 = 31 - __clz(v1);
    if ( v2 <= 7 )
    {
      v3 = dword_10DB60;
      do
      {
        v0[9] = 1 << v2;
        __isb(0xFu);
        v6 = *(void ( **)(int))(v3 + 4 * v2);
        if ( v6 )
        {
          if ( ((v0[4] >> v2) & 1) != 0 )
            v4 = 2;
          else
            v4 = ((v0[5] >> v2) & 1) == 0;
          v6(v4 | (v2 << 16));
        }
        v5 = v0[8];
        v2 = 31 - __clz(v5);
      }
      while ( v5 && v2 <= 7 );
    }
  }
}

