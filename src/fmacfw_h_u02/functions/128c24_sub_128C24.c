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

extern uint32_t off_128C74;
extern uint32_t off_128C7C;
extern uint32_t off_128C78;
extern uint32_t off_128C80;

// mfp_get_state @ 0x128c24, size 78 bytes
void mfp_get_state()
{
  uint8_t *v0; // r5
  int v1; // r4
  void *v2; // r6
  int v3; // r0

  v0 = off_128C74;
  if ( *(uint8_t *)off_128C74 )
  {
    if ( *((uint8_t *)off_128C74 + 28) )
    {
      v1 = *((uint32_t *)off_128C7C + 2);
      *(uint32_t *)off_128C78 |= 4u;
      v0[8] = 0;
      if ( v1 )
      {
        v2 = off_128C80;
        do
        {
          if ( !*(uint8_t *)(v1 + 106) )
          {
            if ( *(uint8_t *)(v1 + 108) )
            {
              v3 = *(uint8_t *)(v1 + 116);
              if ( v3 != 255 && !phy_get_channel(v3, (int)v2, v1) )
                ++v0[8];
            }
          }
          v1 = *(uint32_t *)v1;
        }
        while ( v1 );
      }
    }
  }
}

