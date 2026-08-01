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

extern uint32_t off_12F5AC;
extern uint32_t dword_12F5B4;
extern uint32_t dword_12F5B8;
extern uint32_t off_12F5B0;

// parse_rx_packet_header @ 0x12f51c, size 144 bytes
unsigned int  parse_rx_packet_header(unsigned int a1, int a2, int a3)
{
  unsigned int v3; // r7
  int *v4; // r5
  uint8_t *v8; // r9
  int v9; // r3
  int v10; // r8
  uint8_t *v11; // r4
  uint8_t *v12; // r6
  int v13; // t1

  v3 = a2 - 1;
  if ( *(uint8_t *)(a2 - 1) == 9 )
  {
    v4 = (int *)off_12F5AC;
    if ( a3 < *(uint32_t *)off_12F5AC )
    {
      v8 = (uint8_t *)dword_12F5B4;
      do
      {
        radio_tx_write_string(v8);
        v9 = *v4 - 1;
        *v4 = v9;
      }
      while ( v9 > a3 );
    }
    if ( v3 > a1 )
    {
      v10 = dword_12F5B8;
      v11 = (uint8_t *)(a1 - 1);
      v12 = (uint8_t *)(a2 - 2);
      do
      {
        while ( 1 )
        {
          v13 = *++v11;
          if ( v13 == 9 )
            break;
          ++*v4;
          radio_tx_write_byte(*v11);
          if ( v11 == v12 )
            goto LABEL_10;
        }
        radio_tx_write_string((uint8_t *)((*v4 & 7) + v10));
        *v4 = (*v4 & 0xFFFFFFF8) + 8;
      }
      while ( v11 != v12 );
    }
  }
  else
  {
    radio_tx_write_string((uint8_t *)dword_12F5B4);
    --*(uint32_t *)off_12F5AC;
  }
LABEL_10:
  --*(uint32_t *)off_12F5B0;
  return v3;
}

