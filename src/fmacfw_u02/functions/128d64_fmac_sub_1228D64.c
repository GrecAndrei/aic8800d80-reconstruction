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

extern uint32_t off_128DB4;
extern uint32_t off_128DBC;
extern uint32_t off_128DB8;
extern uint32_t dword_128DC0;

// wlc_chip_state @ 0x128d64, size 78 bytes
// Doc: wlc_chip_state [unknown]: Reads byte from global state at 0x190454
// wlc_chip_state [unknown]: Reads byte from global state at 0x190454
void wlc_chip_state()
{
  uint8_t *v0; // r5
  int v1; // r4
  int v2; // r6
  int v3; // r0

  v0 = off_128DB4;
  if ( *(uint8_t *)off_128DB4 )
  {
    if ( *((uint8_t *)off_128DB4 + 28) )
    {
      v1 = *((uint32_t *)off_128DBC + 2);
      *(uint32_t *)off_128DB8 |= 4u;
      v0[8] = 0;
      if ( v1 )
      {
        v2 = dword_128DC0;
        do
        {
          if ( !*(uint8_t *)(v1 + 106) )
          {
            if ( *(uint8_t *)(v1 + 108) )
            {
              v3 = *(uint8_t *)(v1 + 116);
              if ( v3 != 255 && !rf_channel_get(v3, v2, v1) )
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

