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

extern uint32_t off_126CEC;
extern uint32_t off_126CF0;
extern uint32_t off_126CF4;
extern uint32_t off_126CF8;
extern uint32_t dword_126D00;
extern uint32_t off_126CFC;

// rf_mmio_write @ 0x126c70, size 124 bytes
// Doc: rf_mmio_write [ipc]: Dispatches a host message via registered handler table
// rf_mmio_write [ipc]: Dispatches a host message via registered handler table
void rf_mmio_write()
{
  int *v0; // r4
  int v1; // r5
  uint8_t *v2; // r7
  int v3; // r8
  uint32_t *v4; // r6

  v0 = *((int **)off_126CEC + 2);
  v1 = *((uint32_t *)off_126CF0 + 10);
  mmio_set_radio_bit();
  *(uint32_t *)off_126CF4 &= ~4u;
  if ( v0 )
  {
    v2 = off_126CF8;
    v3 = dword_126D00;
    v4 = off_126CFC;
    do
    {
      while ( 1 )
      {
        if ( v0[18] == v1 && !*((uint8_t *)v0 + 106) && *((uint8_t *)v0 + 108) )
        {
          if ( v2[2] )
            *v4 &= ~0x80000000;
          if ( !*((uint8_t *)v0 + 1224) || *(uint8_t *)(v3 + 140 * *((uint8_t *)v0 + 1225) + 133) )
            break;
        }
        v0 = (int *)*v0;
        if ( !v0 )
          return;
      }
      phy_channel_is_5g(*((uint8_t *)v0 + 116), 0, 0);
      v0 = (int *)*v0;
    }
    while ( v0 );
  }
}

